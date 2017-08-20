// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]

// my sol (dfs)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        dfs(candidates, 0, target, temp, result);
        return result;
    }
    
    void dfs(vector<int>& candidates, int starter, int residual, vector<int>& temp, vector<vector<int>>& result){
        if(residual==0){
            result.push_back(temp);
            return;
        }
        
        for(int i=starter;i<candidates.size(); i++){
            int newRes = residual - candidates[i];
            if(newRes>=0){
                temp.push_back(candidates[i]);
                dfs(candidates, i, newRes, temp, result);
                temp.pop_back();
            }
        }
        return;
    }
};


// solution
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};