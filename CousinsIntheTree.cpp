
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
    bool isCousins(TreeNode* root, int x, int y) {
       queue<TreeNode*> q;
       queue<TreeNode*> parentQ;
        
        q.push(root);
        parentQ.push(NULL);

        TreeNode* xParent = NULL;
        TreeNode* yParent = NULL;
        bool xFound = false;
        bool yFound = false;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                TreeNode * parent = parentQ.front();
                parentQ.pop();

                if(curr->val == x)
                {
                    xFound = true;
                    xParent = parent;
                }
                if(curr->val == y)
                {
                    yFound = true;
                    yParent = parent;
                }
                if(curr->left!= NULL)
                {
                    q.push(curr->left); 
                    parentQ.push(curr);
                }
                if(curr->right!= NULL)
                {
                    q.push(curr->right); 
                    parentQ.push(curr);
                }
            }

                if(xFound && yFound) return xParent != yParent;
                if(xFound || yFound) return false;
            
        }
         return false;
    }
};