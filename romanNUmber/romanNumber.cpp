// Have to implement based on this code http://www.rapidtables.com/convert/number/how-roman-numerals-to-number.htm

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
    private:
        map<string,int> _stringValueMap;
    
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
            
            _stringValueMap.insert(make_pair("XL", 40));
            _stringValueMap.insert(make_pair("XC", 90));
            _stringValueMap.insert(make_pair("CD", 400));
            _stringValueMap.insert(make_pair("CM", 900));
        }
    
        int romanToInt(string s) {
            int sum = 0;
            
            return sum;    
        }
};

int main() 
{
    Solution s;
    cout << s.romanToInt("MCMXCVI") << endl;

    return 0;
}