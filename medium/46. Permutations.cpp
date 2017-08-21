// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// my recursive solution:
// divide and conquer
// each result = first item + permutation of the rest
// e.g. [[1,2,3],[1,3,2]] = [1] + [[2,3],[3,2]]
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int item = nums[i];
            nums.erase(nums.begin() + i);
            vector<vector<int>> back = permute(nums);
            nums.insert(nums.begin() + i, item);
            if (back.size() != 0)
            {
                for (auto iter : back)
                {
                    iter.insert(iter.begin(), item);
                    result.push_back(iter);
                }
            }
            else
            {
                vector<int> temp;
                temp.push_back(item);
                result.push_back(temp);
            }
        }
        return result;
    }
};

// more elegant
void dfs(int pos, vector<int> &num, vector<vector<int>> &result){
    if(pos == num.size()){
        result.push_back(num);
    }
    else{
        for(int i=pos; i<num.size(); i++){
            swap(num[i], num[pos]);
            dfs(pos+1, num, result);
            swap(num[i], num[pos]);
        }
}