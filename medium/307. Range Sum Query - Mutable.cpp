// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.
// Example:
// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

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
 
// better solution
// Approach #3 (Segment tree) (Java)
// Segment Tree can be broken down to the three following steps:
//     Pre-processing step which builds the segment tree from a given array.
//     Update the segment tree when an element is modified.
//     Calculate the Range Sum Query using the segment tree.

int[] tree;
int n;
public NumArray(int[] nums) {
    if (nums.length > 0) {
        n = nums.length;
        tree = new int[n * 2];
        buildTree(nums);
    }
}
private void buildTree(int[] nums) {
    for (int i = n, j = 0;  i < 2 * n; i++,  j++)
        tree[i] = nums[j];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
void update(int pos, int val) {
    pos += n;
    tree[pos] = val;
    while (pos > 0) {
        int left = pos;
        int right = pos;
        if (pos % 2 == 0) {
            right = pos + 1;
        } else {
            left = pos - 1;
        }
        // parent is updated after child is updated
        tree[pos / 2] = tree[left] + tree[right];
        pos /= 2;
    }
}
public int sumRange(int l, int r) {
    // get leaf with value 'l'
    l += n;
    // get leaf with value 'r'
    r += n;
    int sum = 0;
    while (l <= r) {
        if ((l % 2) == 1) {
           sum += tree[l];
           l++;
        }
        if ((r % 2) == 0) {
           sum += tree[r];
           r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}
