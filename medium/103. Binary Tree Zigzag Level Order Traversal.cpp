// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/#/description
// input:
// [3,9,20,null,null,15,7]
// [1,2,3,4,null,null,5]
// output:
// [[3],[20,9],[15,7]]
// [[1],[3,2],[4,5]]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int, vector<int> > mapDepth;
        vector<vector<int> > result;
        queue<pair<int, TreeNode*> > queuePointer;
        if(!root)return result;
        queuePointer.push(pair<int, TreeNode*>(0, root));
        while(queuePointer.size()!=0){
            int tempDepth =  queuePointer.front().first;
            TreeNode* currentNode = queuePointer.front().second;
            queuePointer.pop();
            if(currentNode->left!=NULL){
                queuePointer.push(pair<int, TreeNode*>(tempDepth+1, currentNode->left));
            }
            if(currentNode->right!=NULL){
                queuePointer.push(pair<int, TreeNode*>(tempDepth+1, currentNode->right));
            }
            mapDepth[tempDepth].push_back(currentNode->val);
        }
        int counter = 0;
        for(auto iter: mapDepth){
            if(counter%2!=0){
                reverse(iter.second.begin(), iter.second.end());
            }
            result.push_back(iter.second);
            counter++;
        }
        
        return result;
    }
};

//better sol