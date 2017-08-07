// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

// input:
// [5,4,17,11,null,9,4,7,2,null,null,5,1]
// 22
// [1]
// 1
// [1,2]
// 1
// ans:
// [[5,4,11,2]]
// [[1]]
// []


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        if(root==NULL)return result;
        dfs(result, path, root, sum);
        return result;
    }
    
    void dfs(vector<vector<int> > &result, vector<int> &path, TreeNode* root, int sum){
        TreeNode* temoNode = root;
        sum=sum-root->val;
        //cout << "val::"<<root->val<< "  sum::"<<sum <<endl;
        path.push_back(root->val);
        if(sum==0 && root->left==NULL &&root->right==NULL){
            result.push_back(path);
            //cout<<"yeah"<<endl;
            return;
        }
        if(root->left!=NULL){
            //cout<<"left..."<<endl;
            temoNode = root->left;
            dfs(result, path, temoNode, sum);
            path.pop_back();
        }
        if(root->right!=NULL){
            //cout<<"right..."<<endl;
            temoNode = root->right;
            dfs(result, path, temoNode, sum);
            path.pop_back();
        }
        return;
    }
};