// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

// Note:
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.
// Example 1:
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4

// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
// Example 2:
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2

// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".

// // input
// ["10","0001","111001","1","0"]
// 5
// 3
// ["10","0001","111001","1","0"]
// 3
// 2
// ["1100","100000","011111"]
// 6
// 6
// ["011111","001","001"]
// 4
// 5

// // output::
// 4
// 3
// 2
// 2

// Cant get AC
class Solution
{
  public:
    int countExist(string str, char cmp)
    {
        if (cmp == '2')
        {
            int count0 = 0, count1 = 0;
            for (auto iter : str)
            {
                if (iter == '0')
                    count0++;
                if (iter == '1')
                    count1++;
            }
            return min(count0, count1);
        }
        else
        {
            int count = 0;
            for (auto iter : str)
            {
                if (iter == cmp)
                    count++;
            }
            // cout<<str<<endl;
            // cout<<count<<endl<<endl;
            return count;
        }
    }

    vector<string> goSort(vector<string> &strs, char cmp)
    {
        if (strs.size() <= 1)
            return strs;
        vector<string> merged, left, right;
        // divide
        left.insert(left.begin(), strs.begin(), strs.begin() + strs.size() / 2);
        right.insert(right.begin(), strs.begin() + strs.size() / 2, strs.end());
        left = goSort(left, cmp);
        right = goSort(right, cmp);

        // conquer
        int i = 0, j = 0;
        while (i != left.size() || j != right.size())
        {
            if (i == left.size())
            {
                merged.insert(merged.end(), right.begin() + j, right.end());
                break;
            }
            if (j == right.size())
            {
                merged.insert(merged.end(), left.begin() + i, left.end());
                break;
            }
            int leftCount = countExist(left[i], cmp);
            int rightCount = countExist(right[j], cmp);
            if (leftCount <= rightCount)
            {
                if (leftCount == rightCount)
                { // ==
                    if (left[i].size() < right[j].size())
                    {
                        merged.push_back(left[i]);
                        i++;
                    }
                    else
                    {
                        merged.push_back(right[j]);
                        j++;
                    }
                }
                else
                { // <
                    merged.push_back(left[i]);
                    i++;
                }
            }
            else
            { // >
                merged.push_back(right[j]);
                j++;
            }
        }
        return merged;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        if (m > n)
            strs = goSort(strs, '1');
        else if (m == n)
            strs = goSort(strs, '2');
        else
            strs = goSort(strs, '0');
        // for(auto iter:strs){
        //     cout<<iter<<endl;
        // }
        int result = 0;
        bool GG = false;
        for (auto iter : strs)
        {
            for (auto cha : iter)
            {
                if (cha == '0')
                    m--;
                else if (cha == '1')
                    n--;

                if (m == -1 || n == -1)
                {
                    GG = true;
                    break;
                }
            }
            if (GG)
                break;
            else
                result++;
        }

        return result;
    }
};

// DP!!!!!!!!!!!!!!!!!!!
// memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
    int numZeroes, numOnes;

    for (auto &s : strs)
    {
        numZeroes = numOnes = 0;
        // count number of zeroes and ones in current string
        for (auto c : s)
        {
            if (c == '0')
                numZeroes++;
            else if (c == '1')
                numOnes++;
        }

        // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
        // from the first few strings up to the current string s
        // Catch: have to go from bottom right to top left
        // Why? If a cell in the memo is updated(because s is selected),
        // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
        // If we go from top left to bottom right, we would be using results from this iteration => overcounting
        for (int i = m; i >= numZeroes; i--)
        {
            for (int j = n; j >= numOnes; j--)
            {
                memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
            }
        }
    }
    return memo[m][n];
}