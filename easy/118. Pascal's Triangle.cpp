// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

// my straight forward solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0)return result;
        result.push_back(vector<int>{1});
        if(numRows==1)return result;
        result.push_back(vector<int>{1,1});
        if(numRows==2)return result;
        
        int counter = 3 -1; // 0-based
        while(counter != numRows){
            vector<int> temp = {1};
            for(int i=0;i<result[counter-1].size()-1;i++){
                temp.push_back(result[counter-1][i]+result[counter-1][i+1]);
            }
            temp.push_back(1);
            result.push_back(temp);
            counter++;
        }
        return result;
    }
};

// more neat
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};