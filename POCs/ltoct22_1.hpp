// Problem URL: https://leetcode.com/problems/count-good-triplets/
// Status : There are some bugs

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class ArrayPossitonPair {
    private:
        int _x, _y;

    public:
        ArrayPossitonPair(int x, int y) {
            _x = x;
            _y = y;
        }

        bool operator==(const ArrayPossitonPair& rhs) const {
            if( _x == rhs._x && _y == rhs._y ) return true;
            else return false;
        }

        inline int getX() const { return _x; }
        inline int getY() const { return _y; } 
};

template<>
class hash<ArrayPossitonPair> {
    public:
    size_t operator()(const ArrayPossitonPair& obj) const {
        int xHash = hash<int>()(obj.getX());
        int yHash = hash<int>()(obj.getY());

        return xHash ^ yHash;
    }
};

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int inputSize = arr.size();
        int goodSets = 0;
        unordered_set<ArrayPossitonPair> positionPairs;

        for( int i=0; i<inputSize-1; i++ ) {
            for(int j=i+1; j<inputSize; j++ ) {
                ArrayPossitonPair pair(i,j);
                unsigned int diffVal = abs(arr[i] - arr[j]);
                if( diffVal <= a ) { positionPairs.insert(pair); };
            }
        }

        for( const ArrayPossitonPair& pair : positionPairs ) {
            for(int k=0; k<inputSize; k++ ) {
                int i = pair.getX();
                int j = pair.getY();

                // I think this where we might be having bugs
                bool allAccessending = false;
                if( i < j and j < k ) allAccessending = true;
                if( not allAccessending ) continue;

                if( k != i and k != j ) {
                    unsigned int diffB = arr[j] - arr[k];
                    unsigned int diffC = arr[i] - arr[k];

                    if( diffB <= b and diffC <= c ) {
                        // cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                        goodSets++;
                    }
                }
            }
        }

        return goodSets;        
    }
};

int main() {
    unordered_set<ArrayPossitonPair> positionPairs;
    vector<int> input1 { 3, 0, 1, 1, 9, 7 };
    const int a = 7;
    const int b = 2;
    const int c = 3;
    Solution s;

    // Should output 4
    int retVal = s.countGoodTriplets(input1, 7,2,3);
    cout << retVal << endl;

    // Should output 4
    retVal = s.countGoodTriplets(input1, 2,3,7);
    cout << retVal << endl;

    // Should output 12
    vector<int> input2{ 7,3,7,3,12,1,12,2,3 };
    retVal = s.countGoodTriplets(input1, 5, 8, 1);
    cout << retVal << endl;
    
    return 0;
}
