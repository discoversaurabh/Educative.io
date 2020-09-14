/* INORDER SUCCESSOR */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A) return NULL;
    
    TreeNode* potSuc = NULL;
    
    while(A)
    {
        if(A->val > B)
        {
            if(!potSuc)
                potSuc = A;
            else
                potSuc = (potSuc->val < A->val)?potSuc : A;
            A = A->left;
        }
        else
            A = A->right;
    }
    return potSuc;
}
