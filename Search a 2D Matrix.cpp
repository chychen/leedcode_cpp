// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// input:
// [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
// 3
// [[]]
// 1
// ans:
// true
// false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())return false;
        if(matrix[0].empty())return false;
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        // find which row
        bool flagFoundRow = false;
        int found_row = 0;
        for(int i =0;i<row_size;i++){
            if(matrix[i][0]==target)return true;
            if(!flagFoundRow){
                if(matrix[i][0]>target)flagFoundRow = true;
            }else{
                if(matrix[i][0]<target)found_row = i-1;
            }
        }
        
        // find which col in row we found
        bool flagFound = false;
        for(int i =0;i<col_size;i++){
            if(!flagFound){
                if(matrix[found_row][i]==target)flagFound = true;
            }
        }
        return flagFound;
    }
};

// better solution
// treat it as one sorted list
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};