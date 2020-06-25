#pragma once

// Problem URL: https://leetcode.com/problems/longest-happy-string/
// Problem ID: 1405

#include <string>

using namespace std;

class Solution {
private:
    string  _retValue;
    int _leftA, _leftB, _leftC;

    inline bool isEmpty() {
        return _leftA == 0 && _leftB == 0 && _leftC == 0;
    }

    bool appendChar(char ch) {
        auto lastIndex = _retValue.length() - 1;
        
        // For an empty string we don't have to check
        if (lastIndex == -1) {
            _retValue = ch;
            updateCharCount(ch);
            return true;
        }

        // This is the first condition for the happy string
        if ( lastIndex >= 1 ) {
            if (ch == _retValue[lastIndex] && ch == _retValue[lastIndex - 1])
                return false;
        }

        updateCharCount(ch);
        _retValue += ch;
        return true;
    }

    int getNextIndex() {
        if (_leftA > _leftB) {
            if (_leftA > _leftC) return 0;
            else return 2;
        }
        else {
            if (_leftB > _leftC) return 1;
            else return 2;
        }
    }

    int getNonZeroIndex(int startIndex) {
        switch (startIndex) {
            case 0:
                return _leftB != 0 ? 1 : 2;

            case 1:
                return _leftC != 0 ? 2 : 0;

            case 2:
                return _leftA != 0 ? 0 : 1;

            default:
                return -1;
        }
    }

    void updateCharCount(char ch) {
        switch (ch) {
            case 'a':
                _leftA--;
                break;

            case 'b':
                _leftB--;
                break;

            case 'c':
                _leftC--;

            default:
                break;
        }
    }

public:
    string longestDiverseString(int a, int b, int c) {
        _retValue = "";
        _leftA = a, _leftB = b, _leftC = c;

        char characterMapping[3] = { 'a', 'b', 'c' };

        while (isEmpty() == false) {
            int mI = getNextIndex();

            // The append would fail in case of string get like "aaa" or "bbb"
            if (false == appendChar(characterMapping[mI])) {
                auto bret = appendChar(characterMapping[getNonZeroIndex(mI)]);

                if (bret == false) break;
            }
        }

        return _retValue;
    }
};
