#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <functional>

class IDBConnection {
    public:
        virtual bool connect() = 0;
        virtual bool save() = 0;
        virtual bool load() = 0;

        // For derived destructors to be working fine
        virtual ~IDBConnection() = default;
};

class MongoDBConnection : public IDBConnection {
    private:
        std::string _strPrefix;
    public:
        explicit MongoDBConnection(const std::string& s) : _strPrefix(s) {}

        bool connect() {
            std::cout << "[" << _strPrefix << "]" << "Connect\n";
            return true;
        }      

        bool save() {
            std::cout << "[" << _strPrefix << "]" << "Save\n";
            return true;
        }

        bool load() {
            std::cout << "[" << _strPrefix << "]" << "load\n";
            return true;
        }

        void closeConnection() {
            std::cout << "[" << _strPrefix << "]" << "closing connection\n";
        }

        ~MongoDBConnection() {
            closeConnection();
        }
};

class SQLDBConnection : public IDBConnection {
    private:
        std::string _prefix;

    public:
        explicit SQLDBConnection(const std::string& s) : _prefix(s) {};

        bool connect() {
            std::cout << "[" << _prefix << "]" << "Connect\n";
            return true;
        }      

        bool save() {
            std::cout << "[" << _prefix << "]" << "Save\n";
            return true;
        }

        bool load() {
            std::cout << "[" << _prefix << "]" << "Load\n";
            return true;
        }

        void closeConnection() {
            std::cout << "[" << _prefix << "]" << "closing connection\n";
        }

        ~SQLDBConnection() {
            closeConnection();
        }
};

class DatabaseConnectionFactory {
public:
    enum DbType { SQL, MongoDB };
    std::map<DbType, std::function<std::unique_ptr<IDBConnection> (void)> > _factoryMap;

    DatabaseConnectionFactory() {
        _factoryMap.insert(std::make_pair(DbType::SQL,[] () -> std::unique_ptr<IDBConnection> {
            return std::make_unique<SQLDBConnection>("Local MySQL DB");
        }));
        
        _factoryMap.insert(std::make_pair(DbType::MongoDB,[] () -> std::unique_ptr<IDBConnection> {
            return std::make_unique<MongoDBConnection>("Mongo DB");
        }));
    }

    std::unique_ptr<IDBConnection> createDBConnection(DbType type) {
        return _factoryMap[type]();
    }
};

int main(int argc, char**argv) {
    auto type { 1 };
    std::cin >> type;
    
    std::map<int, DatabaseConnectionFactory::DbType> dbTypeMap;
    dbTypeMap.insert(std::make_pair(1,DatabaseConnectionFactory::DbType::MongoDB));
    dbTypeMap.insert(std::make_pair(2,DatabaseConnectionFactory::DbType::SQL));

    auto dbInterface = DatabaseConnectionFactory().createDBConnection(dbTypeMap[type]);
    
    if( dbInterface != nullptr ) {
        dbInterface->connect();
        dbInterface->load();
        dbInterface->save();
    }

    return 0;
}
