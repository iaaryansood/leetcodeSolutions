/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum(TreeNode * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            return root->val + sum(root->left) + sum(root->right);
        }
    }
    int numNodes(TreeNode * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + numNodes(root->right) + numNodes(root->left);
        }
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int subtreeSum=sum(root);
            int Nodes=numNodes(root);
            int ans=0;
            if(root->val == (subtreeSum/Nodes))
            {
                ans++;
            }
            return ans+averageOfSubtree(root->left) + averageOfSubtree(root->right);
        }
        
    }
};