// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
// Note:
// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum=-999999.0;
        for(int i=0;i<=nums.size()-k;i++){
            if(nums[i+k-1] - nums[i-1] > 0 || i==0){
                double temp=0.0;
                for(int j =0;j<k;j++){
                    temp+=double(nums[i+j]);
                }
                if(maxsum<temp)maxsum = temp;
            }
        }
        maxsum/=k;
        return maxsum;
    }
};