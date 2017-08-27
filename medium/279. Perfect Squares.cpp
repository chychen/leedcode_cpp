// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

class Solution
{
  public:
    // k*k: 1, 4, 9, 16, 25, 36
    // i: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    // A: 1, 2, 3, 1, 2, 3, 4, 2, 1,  2,  3,  3,  2
    // A[i] = min(A[i-k*k] + 1), k=1~sqrt(i), A[0]=0
    int numSquares(int n)
    {
        vector<int> A = {0}; //change 0-based to 1-based
        int i = 1;
        while (i <= n)
        {
            int result = INT_MAX;
            for (int k = 1; k * k <= i; k++)
            {
                result = min(result, A[i - k * k] + 1);
            }
            A.push_back(result);
            i++;
        }
        return A[n];
    }
};