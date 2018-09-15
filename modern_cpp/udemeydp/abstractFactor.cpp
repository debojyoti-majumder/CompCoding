// This is an exmaple of abstarct factory,
// This is a wrong implentation beccause I am return the same object

#include <iostream>
#include <memory>
#include <string>
#include <map>

using namespace std;

struct IHotDrink {
    virtual void drink() = 0;
    virtual ~IHotDrink() {}
};

class Coffee : public IHotDrink {
    private:
        bool _withCream;
        short int _quantity;

    public:
        explicit Coffee(bool cream) : _withCream(cream) {
            _quantity = 100;
        }

        void drink() override {
            cout << "[" << this << "] ";
            cout << "Drinking coffe " << _quantity << " ml "; 

            if(_withCream)
                cout << "With cream";
            cout << endl;
        }

        inline void setSize(short int s) { _quantity = s; }
};

class Tea : public IHotDrink {
    private:
        bool _sugarAdded;
        bool _withMilk;
        short int _quantity;
    
    public:
        Tea(bool sugerAdded = true, bool milkAdded = true) : _sugarAdded(true), _withMilk(true) {
        _quantity = 150;
        }

        void drink() override {
            cout << "[" << this << "] ";
            cout << "Drinking tea " << _quantity << " ml ";

            if( _sugarAdded )
                cout << "Tests better with suger ";
            if( _withMilk )
                cout << "Even better with milk";

            cout << endl;
        }

        inline void setSize(short int s) { _quantity = s; }
};

class HotDrinkFactory {
    private:
        map<string, IHotDrink*>     _objectStore;
        static HotDrinkFactory*     _instnace;
        
        HotDrinkFactory() {
            _objectStore.insert(make_pair("tea", new Tea()));
            _objectStore.insert(make_pair("coffe", new Coffee(true)));
        };

    public:
        static HotDrinkFactory& getInstance() {
            // If not create, create the factory object
            if( _instnace == nullptr )
                _instnace = new HotDrinkFactory();

            return *(_instnace);
        }

        IHotDrink* createHotDrink(string drinkType) {
            if( _objectStore.find(drinkType) != _objectStore.end() )
                return _objectStore[drinkType];
            else
                return nullptr;
        }

        ~HotDrinkFactory() {
            cout << "Make sure fire all employees" << endl;
        }
};

HotDrinkFactory* HotDrinkFactory::_instnace = nullptr;

int main() {
    auto dfactory = HotDrinkFactory::getInstance();
    string order = "";

    // Hitting end would end the program
    while( order.compare("end") ) {
        cin >> order;
        auto obj = dfactory.createHotDrink(order);
        
        if( obj != nullptr ){
            obj->drink();
        }
    }

    return 0;
}
