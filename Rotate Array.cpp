// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k--){
            int temp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), temp);
        }
    }
};
// better~
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        int preSize = nums.size()-k;
        if(preSize<1)return;
        vector<int> pre;
        pre.insert(pre.end(), nums.begin(), nums.begin()+preSize);
        nums.erase(nums.begin(), nums.begin()+preSize);
        nums.insert(nums.end(), pre.begin(), pre.end());
    }
};