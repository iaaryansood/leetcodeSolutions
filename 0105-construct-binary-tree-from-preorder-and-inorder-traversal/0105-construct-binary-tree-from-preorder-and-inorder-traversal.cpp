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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()  == 1 || preorder.size() == 0)
        {
            if(preorder.size() == 1)
            {
                TreeNode *node=new TreeNode(preorder[0]);
                return node;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            unordered_map<int,int> map;
            for(int i=0;i<inorder.size();i++)
            {
                map[inorder[i]]=i;
            }

            int rootIndex=map[preorder[0]];

            vector<int> leftPre,leftIn,rightPre,rightIn;

            leftIn.insert(leftIn.end(),inorder.begin(),inorder.begin()+rootIndex);
            rightIn.insert(rightIn.end(),inorder.begin()+rootIndex+1,inorder.end());

            leftPre.insert(leftPre.end(),preorder.begin()+1,preorder.begin()+rootIndex+1);
            rightPre.insert(rightPre.end(),preorder.begin()+rootIndex+1,preorder.end());

            TreeNode *left=buildTree(leftPre,leftIn);
            TreeNode *right=buildTree(rightPre,rightIn);

            TreeNode *node=new TreeNode(preorder[0]);
            node->left=left;
            node->right=right;
            return node;
        }
        

    }
};