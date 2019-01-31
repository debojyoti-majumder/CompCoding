#include <iostream>
#include <string>
#include <memory>
#include <boost/signals2.hpp>

void method1(int value) {
	std::cout << "This is method 1" << std::endl;
	std::cout << "Value changed:" << value << std::endl;
}

void method2(int value) {
	std::cout << "This is the second method" << std::endl;
	std::cout << "Value:" << value;
}

class EventSubscriber {
	private:
		unsigned int id;

	public:
		EventSubscriber() = delete;
		explicit EventSubscriber(int m) : id(m) {}

 		void dataChanged(int data) {
			std::cout << id << ":" << data << std::endl;
		}

		~EventSubscriber() {
			std::cout << "Making sure object is destroyed" << std::endl;
		}
};

int main() {
	typedef boost::signals2::signal<void(int)> signals;
	typedef signals::slot_type signalSlots;
	std::string str("Random Stuff");
	std::shared_ptr<EventSubscriber> evtSubscriber1(new EventSubscriber(1));
	std::shared_ptr<EventSubscriber> evtSubscriber2(new EventSubscriber(2));

	signals mySignals;

	mySignals.connect(method1);
	mySignals.connect(method2);
	mySignals.connect([&](int value) {
		std::cout << "This is a lambda function" << std::endl;
		std::cout << "From capture:" << str << " " << value << std::endl;
	});

	mySignals.connect(boost::bind(&EventSubscriber::dataChanged, evtSubscriber1, _1));
	mySignals.connect(boost::bind(&EventSubscriber::dataChanged, evtSubscriber2, _1));

	int i = 1;
	while( i!=0 ) {
		std::cin >> i;
		mySignals(i);
	}

	return 0;
}
