// Have to implement based on this code http://www.rapidtables.com/convert/number/how-roman-numerals-to-number.htm
// Problem url https://leetcode.com/problems/integer-to-roman/

#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
    private:
        map<string,int> _stringValueMap;
        map<string,int> _doubleCharMap;

    public:
        Solution() {
            // Making the roman character map
            _stringValueMap.insert(make_pair("I", 1));
            _stringValueMap.insert(make_pair("V", 5));
            _stringValueMap.insert(make_pair("X", 10));
            _stringValueMap.insert(make_pair("L", 50));
            _stringValueMap.insert(make_pair("C", 100));
            _stringValueMap.insert(make_pair("D", 500));
            _stringValueMap.insert(make_pair("M", 1000));
            
            _doubleCharMap.insert(make_pair("XL", 40));
            _doubleCharMap.insert(make_pair("XC", 90));
            _doubleCharMap.insert(make_pair("CD", 400));
            _doubleCharMap.insert(make_pair("CM", 900));
        }
    
        int romanToInt(string s) {
            int sum = 0;
            std::transform(s.begin(), s.end(),s.begin(), ::toupper);

            while(s.length()) {
                string f1 = s.substr(0,2);

                auto doubleCharIt = _doubleCharMap.find(f1);
                if( doubleCharIt == _doubleCharMap.end() ) {
                    string f2 = s.substr(0,1);
                    auto singleCharIt = _stringValueMap.find(f2);
                    
                    if( singleCharIt != _stringValueMap.end() )
                        sum += singleCharIt->second;

                    s.erase(0,1);
                }
                else {
                    sum += doubleCharIt->second;
                    s.erase(0,2);
                }
            }

            return sum;    
        }
};

int main() 
{
    Solution s;
    cout << s.romanToInt("MCMXCVI") << endl;

    return 0;
}