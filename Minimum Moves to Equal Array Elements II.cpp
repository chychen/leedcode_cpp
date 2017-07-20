class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int totalSteps = 0;
        int midianIdx;
        if(nums.size()%2==0)midianIdx=nums.size()/2-1;
        else int(midianIdx=nums.size()/2);
        for(auto it:nums){
            totalSteps+=abs(it-nums[midianIdx]);
        }
        return totalSteps;
    }
};