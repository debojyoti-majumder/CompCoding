
// Leetcode problem : https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct SearchPosition {
    int x;
    int y;
};

struct BrackTrackingInfo {
    SearchPosition  postion;
    vector<char>    searchedChars;
    size_t          searchLength;
};

class Solution {
private:
    size_t _rowSize;
    size_t _colSize;
    queue<BrackTrackingInfo> _backtrackQueue;

    bool isInBound(const SearchPosition& pos) {
        if( pos.x < 0 || pos.x >= _rowSize ) return false;
        else if( pos.y < 0 || pos.y >= _colSize ) return false;
        else return true;
    }

    vector<SearchPosition> getNextPositions(const SearchPosition& pos) {
        vector<SearchPosition> validBoxes;

        SearchPosition posTop       { pos.x, pos.y -1 };
        SearchPosition posBottom    { pos.x, pos.y + 1};
        SearchPosition posLeft      { pos.x - 1, pos.y};
        SearchPosition posRight     { pos.x + 1, pos.y};

        if( isInBound(posTop) ) validBoxes.emplace_back(posTop);
        if( isInBound(posBottom) ) validBoxes.emplace_back(posBottom);
        if( isInBound(posLeft)) validBoxes.emplace_back(posLeft);
        if( isInBound(posRight) ) validBoxes.emplace_back(posRight);
        
        return validBoxes;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // This wouold be the return value for the program
        bool wordFound { false };
        size_t wordLength = word.length();

        // Setting up the bounds
        _rowSize = board.size();
        if (_rowSize == 0 ) return true;
        _colSize = board[0].size();

        SearchPosition pos { 0, 0 };
        BrackTrackingInfo btrInfo { pos, vector<char>{}, 0 };
        _backtrackQueue.push(btrInfo);

        while( _backtrackQueue.empty() == false ) {
            // Obbtain and remove the element from the queue
            BrackTrackingInfo currentItem { _backtrackQueue.front() };
            _backtrackQueue.pop();

            auto r { currentItem.postion.x };
            auto c { currentItem.postion.y };

            char boardChar { board[r][c] };
            char macthChar { word.at(currentItem.searchLength) };

            if( boardChar == macthChar ) {
                // This means we have matched all the options
                if( currentItem.searchLength == wordLength - 1 ) {
                    wordFound = true;
                    break;
                }

                // We look for next chars
                auto nextPostions = getNextPositions(currentItem.postion);
                for( const auto& pos : nextPostions ) {
                    BrackTrackingInfo inf { currentItem };

                    inf.postion = pos;
                    inf.searchLength = currentItem.searchLength + 1;
                    _backtrackQueue.push(inf);
                }
            } else {
                                
            }
        }

        return wordFound;        
    }
};

int main(int, char**) {
    vector<vector<char>> input1 {
        {'A', 'B', 'C','E'},
        {'S', 'F', 'C', 'F' },
        {'A', 'D', 'E', 'E'}
    };

    string wordPattern("ABCCED");

    Solution s;
    auto retValue { s.exist(input1, wordPattern) };

    std::cout << "Input 1:" << retValue;
}
