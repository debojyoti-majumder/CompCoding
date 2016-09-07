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
            _doubleCharMap.insert("I", 1));
            _doubleCharMap.insert("V", 5));
            _doubleCharMap.insert("X", 10));
            _doubleCharMap.insert("L", 50));
            _doubleCharMap.insert("C", 100));
            _doubleCharMap.insert("D", 500));
            _doubleCharMap.insert("M", 1000));

            _doubleCharMap.insert("XL", 40);
            _doubleCharMap.insert("XC", 90);
            _doubleCharMap.insert("CD", 400);
            _doubleCharMap.insert("CM", 900);
        }
    
        int romanToInt(string s) {
            int sum = 0;

            while(s.length()) 
            
            return sum;    
        }
}
int main() 
{
    Solution s;
    
    return 0;
}