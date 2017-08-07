// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

// Example:

// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13

// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13


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
    void travel(TreeNode* root, int &cur_sum){
        if (!root) return;
        if (root->right) travel(root->right, cur_sum);
        
        root->val = (cur_sum += root->val);
        if (root->left) travel(root->left, cur_sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int cur_sum = 0;
        travel(root, cur_sum);
        cout<<cur_sum<<endl;
        return root;
    }
};


// // key to solve:
// new right = current_sum + old right (= old right)
// current_sum += old right
// new mid = current_sum + old mid (= old right + old mid)
// current_sum += old mid
// new left = current_sum + old left (= old right + old mid + old left)
// current_sum += old left