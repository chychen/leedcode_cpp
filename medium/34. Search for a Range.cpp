// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

// binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return vector<int> {-1, -1};
        int left=0, right=nums.size();
        while(left < right){
            if(nums[left]==target){
                break;
            }
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        if(nums[left]!=target||left>=nums.size())return vector<int> {-1, -1};
        int i;
        for(i = left;i<nums.size();i++){
            if(nums[i]!=target)break;
        }
        return vector<int> {left, i-1};
    }
};