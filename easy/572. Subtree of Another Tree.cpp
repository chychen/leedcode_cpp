// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

// Example 1:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.
// Example 2:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

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
    bool compare_two_tree(TreeNode* s, TreeNode* t){
        //find out if two subtrees are same
        if(s->val!=t->val)return false;
        if(bool(s->left) ^ bool(t->left)) return false;
        if(bool(s->right) ^ bool(t->right)) return false;
        if(s->left && t->left)if(!compare_two_tree(s->left, t->left))return false;
        if(s->right && t->right)if(!compare_two_tree(s->right, t->right))return false;
        
        return true;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //use queue to traverse the tree to find the same head value
        queue<TreeNode*> q;
        q.push(s);
        while(q.size()>0){
            int temp_size = q.size();
            while(temp_size--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->val==t->val){
                    //compare two tree
                    if(compare_two_tree(temp, t))return true;
                }
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return false;
    }
};