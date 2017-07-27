// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

// click to show more practice.

// More practice:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // a(i) = a(i-1) > 0 ? a(i-1) + a[i] : a[i]
        if(nums.size()<1)return 0;
        int *table = new int[nums.size()];
        int maxResult=nums[0];
        table[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            table[i] = table[i-1]>0? table[i-1]+nums[i]: nums[i];
            if(table[i]>maxResult)maxResult = table[i];
        }
        return maxResult;
    }
};