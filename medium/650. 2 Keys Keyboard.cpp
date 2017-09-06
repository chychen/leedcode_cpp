// Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

// Example 1:
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.

class Solution {
public:
    // 1 0
    // 2 2=1*2
    // 3 3=1*3
    // 4 4=2*2
    // 5 5=1*5
    // 6 5=2*3
    // 7 7=1*7
    // 8 6=2*4
    // 9 6=3*3
    // 10 7=2*5
    // 11 11=1*11
    // n == Table[factor] + Table[n/factor]
    int minSteps(int n) {
        vector<int> Table={0,0};//1-based
        if(n<=1)return 0;
        for(int target=2;target<=n;target++){
            for(int factor=sqrt(target);factor>0;factor--){
                if(factor==1){
                    Table.push_back(target);
                    break;
                }
                if (target%factor==0){
                    Table.push_back(Table[factor]+Table[target/factor]);
                    break;
                }
            }
        }
        return Table[n];
    }
};

/**
 * It take 2 op to double, 3 ops to triple, ...
 * if n % 2 == 0, then f(n) = f(n/2) + 2
 * if n % 3 == 0, then f(n) = f(n/3) + 3
 * 2 * 2 = 2 + 2, 2 * 3 > 2 + 3, 4 * 4 > 4 + 4, so it is always better to divide whenever possible.
 * now it became a problem for finding all possible factors;
 */
 
 class Solution {
 public:
     int minSteps(int n) {
         if (n == 1) return 0;
         for (int i = 2; i < n; i++)
             if (n % i == 0) return i + minSteps(n / i);
         return n;
     }
 };