#include "stdafx.h"
#include <thread>
#include <iostream>
#include <map>
#include <sstream>
#include <memory>

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


class WorkoutSession {
	private:
		unsigned int _duration;
		string _user;

	public:
		WorkoutSession() = delete;
		
		explicit WorkoutSession(unsigned int duration) :_duration(duration) , _user("Anaonymus user") {}
		WorkoutSession(unsigned int d, string name): _duration(d), _user(name) {}
		
		// This is suppose to be the long running job
		void operator()() {
			for (unsigned int i = 0; i < _duration; i++) {
				cout << _user << " Working out " << i + 1 << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
};

class SessionManager : public Singleton<SessionManager> {
	private:
		SessionManager() = default;
		map<string,shared_ptr<thread>> _sessionThreads;

	public:
		SessionManager(const SessionManager&) = delete;
		SessionManager(const SessionManager&& r) : _sessionThreads(r._sessionThreads) {}

		void startSession(string userName) {
			WorkoutSession s(10,userName);
			_sessionThreads.insert(make_pair(userName, new thread{ s }));
		}
		
		void stopSession(string userName) {
			cout << "Stopping session for" << userName << "\n";

			auto taskIt = _sessionThreads.find(userName);
			if (taskIt != _sessionThreads.end()) {
				cout << "Emergency stop\n";
				taskIt->second->detach();
				_sessionThreads.erase(taskIt);
			}
		}

		~SessionManager() {
			for (auto& task : _sessionThreads) {
				if (task.second->joinable())
					task.second->join();

			}
		}

	friend struct Singleton<SessionManager>;
};

int main() {
	auto sessMgr = SessionManager::getInstance();

	char ch = 'q';
	bool bRunning = true;
	int counter = 1;

	while (bRunning) {
		cin >> ch;

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
