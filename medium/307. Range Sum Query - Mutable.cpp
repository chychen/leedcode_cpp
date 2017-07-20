class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int> nums) {
        for(auto t: nums){
            this->nums.push_back(t);
        }
    }
    
    void update(int i, int val) {
        if(this->nums.size()>i){
            this->nums[i]=val;
        }
    }
    
    int sumRange(int i, int j) {
        int sum=0;
        for(int p=i;p<=j;p++){
            sum += this->nums[p];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
 