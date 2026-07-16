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
class BSTiterator{
    private:
    stack<TreeNode*> st;
    bool reverse;

    public:
    BSTiterator(TreeNode* root, bool rev){
        reverse = rev;
        pushall(root);
    }

    int next(){
        TreeNode* temp = st.top();
        st.pop();

        if(reverse){
            pushall(temp -> left);
        }
        else{
            pushall(temp -> right);
        }

        return temp -> val;
    }

    void pushall(TreeNode* curr) {
        while(curr) {
            st.push(curr);
            if(reverse){
                curr = curr -> right;
            }
            else {
                curr = curr -> left;
            }
        }
    }

};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        BSTiterator l(root, false);   
        BSTiterator r(root, true);
        // next function that gives the smallest value
        int i = l.next();
        // before() function that gives the largest value
        int j = r.next();

        while(i < j){

        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();

        }

        return false;
    }
};