// You need to find the largest value in each row of a binary tree.

// Example:
// Input:

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9

// Output: [1, 3, 9]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // nothing but BFS
class Solution
{
  public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size() != 0)
        {
            int largest = INT_MIN;
            int size = q.size();
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (largest < temp->val)
                    largest = temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            result.push_back(largest);
        }
        return result;
    }
};

// python example
// def findValueMostElement(self, root):
//     maxes = []
//     row = [root]
//     while any(row):
//         maxes.append(max(node.val for node in row))
//         row = [kid for node in row for kid in (node.left, node.right) if kid]
// return maxes