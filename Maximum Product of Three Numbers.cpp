//Given an integer array, find three numbers whose product is maximum and output the maximum product.
// Input: [1,2,3,4]
// Output: 24

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<=3){
            return nums[0] *nums[1]*nums[2];
        }
        sort(nums.begin(), nums.end());
        int max = 0;
        int temp;
        // 1st
        temp = nums[0]*nums[1]*nums.back();
        if(temp>max) max = temp;
        temp = nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
        if(temp>max) max = temp;
        return max;
        
    }
};