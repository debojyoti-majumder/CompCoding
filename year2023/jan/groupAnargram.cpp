#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    vector<map<char,int>>   _uniqueElements;
    vector<vector<string>>  _returnValue;

    bool areMapsEqual(const map<char,int>& lhs, const map<char,int>& rhs) {
        if( rhs.size() != lhs.size() ) return false;

        for(const auto& elem : lhs ) {
            auto it = rhs.find(elem.first);

            if( it == rhs.end() ) return false;
            if( it->second != elem.second ) return false;
        }

        return true;
    }

    int getGroupId(map<char,int> charMap) {
        for( int i=0; i<_uniqueElements.size(); i++ ) {
            if( areMapsEqual(_uniqueElements[i], charMap) ) return i;
        }

        return -1;
    }

    void processString(const string& inputString) {
        auto currentMap { makeCharMap(inputString) };
        int groupId = getGroupId(currentMap);

        if( groupId != -1 ) {
            _returnValue[groupId].emplace_back(inputString);
        }
        else {
            _uniqueElements.emplace_back(currentMap);
            _returnValue.emplace_back(vector<string>{inputString});
        }
    }

    map<char,int> makeCharMap(const string& inputStr) {
        map<char,int> charMap;
        
        for( char ch : inputStr ) {
            auto it = charMap.find(ch);
            if( it == charMap.end() ) {
                charMap.insert(make_pair(ch,1));
            }
            else {
                it->second += 1;
            }
        }

        return charMap;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        _uniqueElements.clear();
        _returnValue.clear();

        for( const string& inpString : strs ) {
            processString(inpString);
        }

        return _returnValue;
    }
};

int main() {
    Solution s;
    vector<string> inputs { "eat","tea","tan","ate","nat","bat" };

    auto groups { s.groupAnagrams(inputs) };
    for( const auto& group : groups ) {
        for( const string& elem : group ) cout << elem << " ";
        cout << endl;
    }

    vector<string> inputs2 { "acc","","ac" };
    auto groups2 { s.groupAnagrams(inputs2) };
    for( const auto& group : groups2 ) {
        for( const string& elem : group ) cout << elem << " ";
        cout << endl;
    }

    cout << groups2.size() << endl;

    return 0;
}
