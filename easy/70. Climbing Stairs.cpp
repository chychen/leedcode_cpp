//basically fibonacci
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.
// // input:
// 1
// 10
// 2
// // output:
// 1
// 89
// 2
class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem;
        mem.push_back(0);
        mem.push_back(1);
        int result=0;
        for(int i=0;i<n;i++){
            result = mem[i]+mem[i+1];
            mem.push_back(result);
        }
        return result;
    }
};