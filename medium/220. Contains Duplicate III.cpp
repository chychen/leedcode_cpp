// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
// [-2147483648,-2147483647]
// 3
// 3
// -> true

class Solution {
public:
    // O(N^2)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<=1)return false;
        for (int i =0;i<nums.size()-1;i++){
            for(int j=i+1;j<=i+k&&j<nums.size();j++){
                if(abs((long long int)nums[j]-(long long int)nums[i])<=t){
                    return true;
                }
            }
        }
        return false;
    }
    // O(N)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long int> window; // set is ordered automatically 
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound((long long int)nums[i] - (long long int)t); // x-nums[i] >= -t ==> x >= nums[i]-t 
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && abs(*pos - (long long int)nums[i]) <= (long long int)t) return true;
            window.insert((long long int)nums[i]);
        }
        return false;
    }
};