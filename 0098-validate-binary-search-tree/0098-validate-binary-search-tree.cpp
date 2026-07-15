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
    TreeNode* prev = NULL;
// solution 2
    // bool helper(TreeNode* root, long long low, long long high){
    //     if(root == NULL) return true;

    //     if(root -> val <= low || root -> val >= high) {
    //         return false;
    //     }

    //     return helper(root -> left, low, root -> val) && helper(root -> right, root -> val, high);
    // }
    bool isValidBST(TreeNode* root) {
        // solution 2
        // return helper(root, LONG_MIN, LONG_MAX);

        if(root == NULL) return true;

        // left tree traversal
        if(!isValidBST(root -> left)){
            return false;
        }

        // current node check

        if(prev != NULL && prev -> val >= root -> val){
            return false;
        }

        prev = root;

        //right tree traversal

        return isValidBST(root -> right);
        
    }
};