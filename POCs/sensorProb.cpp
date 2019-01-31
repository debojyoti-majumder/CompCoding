#include "stdafx.h"
#include <thread>
#include <iostream>
#include <map>
#include <sstream>
#include <memory>
#include <functional>
#include <random>

using namespace std;

template <typename T>
struct Singleton {
private:
	static shared_ptr<T> _instance;

public:
	static shared_ptr<T> getInstance() {
		if( Singleton<T>::_instance == nullptr )
			Singleton<T>::_instance = make_shared<T>(move(T{}));
		
		return Singleton<T>::_instance;
	}
};

template <typename T>
shared_ptr<T> Singleton<T>::_instance = nullptr;

template <typename T>
class Observable {
private:
	const T& _container;
	vector<function<void(T)>> _subscribers;

protected:
	void notify() {
		for (auto fn : _subscribers) {
			fn(_container);
		}
	}

public:
	Observable() = delete;

	Observable(const T& obj) : _container(obj) {

	}

	void addSubscriber(function<void(T)> func) {
		_subscribers.emplace_back(func);
	}

	Observable<T>& operator=(const Observable<T>& rhs) {
		changeValue(rhs._container);
		notify();
		return *(this);
	}

	virtual void changeValue(const T& rhs) = 0;
};

class RandomNumbergenerator {
private:
	int _max;
	int _min;

public:
	RandomNumbergenerator() = delete;
	RandomNumbergenerator(int min, int max) : _max(max), _min(min) {
	}

	int getRadomData() {
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> dis(_min, _max);

		return dis(gen);
	}
};

class SensorData : public Observable<SensorData> {
public:
	int age;
	int heartrate;
	
	SensorData() : Observable<SensorData>(*this) {
		age = 18;
		heartrate = 85;
	}

	void changeValue(const SensorData& d) override {
		age = d.age;
		heartrate = d.heartrate;
	}
};

class WorkoutSession {
	private:
		unsigned int _duration;
		string		_user;
		bool		_stopExecution;
		SensorData _currentsensor;
		RandomNumbergenerator _randGen;

	public:
		WorkoutSession() = delete;
		
		explicit WorkoutSession(unsigned int duration) :_duration(duration) , _user("Anaonymus user"), _stopExecution(false), _randGen(4,10) {
			unsigned int* time = &_duration;

			_currentsensor.addSubscriber([=](SensorData d) {
				if (d.heartrate > 120)
					*time = 3;
			});
		}

		WorkoutSession(unsigned int d, string name): _duration(d), _user(name), _stopExecution(false) , _randGen(4,10) {}

		// This is suppose to be the long running job
		void operator()() {
			for (unsigned int i = 0; i < _duration; i++) {
				if (_stopExecution) break;

				auto newSensordata{ _currentsensor };

				cout << _user << " Working out " << this << "\n";
				this_thread::sleep_for(chrono::seconds(1));

				// Incrementing the heart rate randomly
				newSensordata.heartrate += _randGen.getRadomData();
				_currentsensor = newSensordata;
			}
		}
};

class SessionManager : public Singleton<SessionManager> {
	private:
		SessionManager() = default;
		map<string,shared_ptr<thread>>	_sessionThreads;
		map<string, WorkoutSession*>	_sessionMap;

	public:
		SessionManager(const SessionManager&) = delete;
		SessionManager(const SessionManager&& r) : _sessionThreads(r._sessionThreads) {}

		bool startSession(string userName) {
			auto it = _sessionThreads.find(userName);
			
			if (it == _sessionThreads.end()) {
				auto task = new WorkoutSession(10, userName);
				_sessionThreads.insert(make_pair(userName, new thread{ *task }));
				
				auto taskId = _sessionThreads[userName]->get_id();
				_sessionMap.insert(make_pair(userName,task));
				return true;
			}

			return false;
		}
		
		void stopSession(string userName) {
			cout << "Stopping session for" << userName << "\n";

			auto taskIt = _sessionThreads.find(userName);
			if (taskIt != _sessionThreads.end()) {
				taskIt->second->detach();
				_sessionThreads.erase(taskIt);

			}
		}

		~SessionManager() {
			for (auto& task : _sessionThreads) {
				if (task.second->joinable())
					task.second->join();
			}

			for (auto t : _sessionMap)
				delete t.second;

			cout << "All tasks are done\n";
		}

	friend struct Singleton<SessionManager>;
};

int main() {
	char ch = 'q';
	bool bRunning = true;
	int counter = 1;

	while (bRunning) {
		cin >> ch;
		auto sessMgr = SessionManager::getInstance();

		switch (ch)
		{
			case 'c':{
				stringstream name;
				name << "Deb" << counter;

				sessMgr->startSession(name.str());
				counter++;
				break;
			}

			case 'd': {
				string userName;
				cin >> userName;

				sessMgr->stopSession(userName);
				break;
			}

			case 'q':
			case 'Q':
				bRunning = false;
				break;

			default:
				break;
		}
	}

	cout << "End of program\n";
	return 0;
}
