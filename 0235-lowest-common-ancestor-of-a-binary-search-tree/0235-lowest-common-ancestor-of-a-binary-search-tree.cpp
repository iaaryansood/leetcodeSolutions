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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        else
        {
            if(root->val == p->val)
            {
                return p;
            }
            else if(root->val == q->val)
            {
                return q;
            }
            else
            {
                TreeNode *left=lowestCommonAncestor(root->left,p,q);
                TreeNode *right=lowestCommonAncestor(root->right,p,q);
                if(!left && !right)
                {
                    return NULL;
                }
                else if(!left && right)
                {
                    return right;
                }
                else if(left && !right)
                {
                    return left;
                }
                else
                {
                    return root;
                }

            }
        }
    }
};