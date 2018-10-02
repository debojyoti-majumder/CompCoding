#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto sz = nums.size();
        auto expectedSum = ((sz) * (sz +1)) / 2;
        auto sum = 0;
        
        for( auto n : nums )
            sum += n;

        return (expectedSum - sum);
    }
};


int main() {
    return 0;
}
