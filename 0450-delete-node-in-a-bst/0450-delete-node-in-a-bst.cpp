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
    TreeNode* minvaluenode(TreeNode* root) {
        TreeNode* curr = root;

        while(curr -> right) {
            curr = curr -> right;   
        }

        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
        }
        else{

            // no left child case
            if(root -> left == NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }

            // no right child case
            else if(root -> right == NULL) {
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }


            // two children case
            // inorder successor
            TreeNode* temp = minvaluenode(root -> left);
            root -> val = temp -> val;
            root -> left = deleteNode(root -> left, temp -> val);
        }

        return root;
    }
};