#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    int getEditDistance(string s1, string s2) {
        int count = 0;

        for(int i=0; i<s1.length(); i++) {
            if( s1[i] != s2[i] )
                count++;
        }

        return count;
    }
public:
    int minFlipsMonoIncr(string S) {
        int inputLength = S.length();
        int distance = 0;

        string testString("");

        for(auto i=0; i<inputLength; i++)
            testString += "0";
        
        distance = getEditDistance(testString, S);
        
        for(auto i=inputLength-1; i>=0; i--) {
            testString[i] = '1';
            auto d = getEditDistance(testString, S);

            if( d < distance )
                distance = d;
        }

        return distance;
    }
};

int main() {
    Solution s;
    cout << s.minFlipsMonoIncr("00110") << "\n";
    cout << s.minFlipsMonoIncr("010110") << "\n";
    cout << s.minFlipsMonoIncr("00011000") << "\n";
}
