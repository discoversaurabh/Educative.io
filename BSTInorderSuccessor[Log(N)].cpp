/* INORDER SUCCESSOR */
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return NULL;
        TreeNode* tmp = p->right;
        while(tmp){
            if(!tmp->left) return tmp;
            tmp = tmp->left;
        }
        
        //now successor is in p's parent
        tmp = root;
        TreeNode* successor = NULL;
        
        while(tmp){
            if(p->val == tmp->val) return successor;
            
            else if(p->val < tmp->val){
                if(!successor || successor->val > tmp->val){
                    successor = tmp;
                }
                tmp = tmp->left;
            }else {
                tmp = tmp->right;
            }
        }
        return successor;
    }
};
