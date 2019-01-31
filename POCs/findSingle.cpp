// Problem Url: https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int retValue = 0;
        
        for(auto item : nums) 
            retValue = retValue ^ item;
            
        return retValue;
    }
};
