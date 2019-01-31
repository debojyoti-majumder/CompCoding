// Probelm URL: https://leetcode.com/contest/weekly-contest-95/problems/stone-game/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
private:
    // First the user score, second is the opponent scores
    pair<int,int> makeMove(vector<int>& board, int moveCount, pair<int,int> score) {
        auto sz = board.size();

        if( sz != 0 ) {
            auto board1(board);
            auto board2(board);
            auto score1(score);
            auto score2(score);

            auto p1 = board1[0];
            board1.erase(board1.begin());
            
            auto p2 = board2[sz - 1];
            board2.erase(board2.end() - 1);

            if( moveCount % 2 ) {
                score1.first += p1;
                score2.first += p2;
            }
            else {
                score1.second += p1;
                score2.second += p2;
            }

            auto outcome = makeMove(board1, ++moveCount, score1);
            if( outcome.first >= outcome.second ) {
                return outcome;
            }
            else {
                return makeMove(board2,++moveCount,score2);
            }
        }
        else {
            return score;
        }
    }    
public:
    bool stoneGame(vector<int>& piles) {
        pair<int,int> score(0,0);
        auto finalScore = makeMove(piles, 1, score);

        if( finalScore.first >= finalScore.second )
            return true;
        else
            return false;        
    }
};

int main() {
    Solution s;
    vector<int> boardGame {5,3,4,5};
    vector<int> gm2 {4,2,10,9};

    cout << s.stoneGame(boardGame) << endl;
    cout << s.stoneGame(gm2) << endl;
    return 0;
}
