// This is function programming style absatct factory, still there is memory leaks to be solved
// There could be a bettre SingleTon implentation

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <list>
#include <functional>

using namespace std;

struct IHotDrink {
    virtual void drink() = 0;
    virtual ~IHotDrink() = default;
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

using factoryMethod = function<IHotDrink* ()>;

class HotDrinkFactory {
    private:
        map<string, factoryMethod>     _functionalObjectStore;
        static HotDrinkFactory*        _instnace;

        HotDrinkFactory() {
            _functionalObjectStore.insert(make_pair("tea", [] () -> IHotDrink* {
                return new Tea();
            }));
            
            _functionalObjectStore.insert(make_pair("coffe",[] () -> IHotDrink* {
                return new Coffee(true);
            }));

            _functionalObjectStore.insert(make_pair("blackcoffe",[] () -> IHotDrink* {
                return new Coffee(false);
            }));

            _functionalObjectStore.insert(make_pair("smalltea", [] () -> IHotDrink* {
                auto obj = new Tea();
                obj->setSize(50);

                return obj;
            }));

            _functionalObjectStore.insert(make_pair("largetea", [] () -> IHotDrink* {
                auto obj = new Tea();
                obj->setSize(300);

                return obj;
            }));

            _functionalObjectStore.insert(make_pair("blacktea", [] () -> IHotDrink* {
                return new Tea(true, false);
            }));

        };

    public:
        static HotDrinkFactory& getInstance() {
            // If not create, create the factory object
            if( _instnace == nullptr )
                _instnace = new HotDrinkFactory();

            return *(_instnace);
        }

        IHotDrink* createHotDrink(string drinkType) {
            if( _functionalObjectStore.find(drinkType) != _functionalObjectStore.end() )
                return _functionalObjectStore[drinkType]();
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
        else {
            cout << "We don't have the drink order something else" << endl;
        }
    }

    return 0;
}
