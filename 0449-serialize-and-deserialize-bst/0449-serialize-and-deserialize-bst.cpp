/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // BST can be determinde by a preorder traversal
    void preorder(TreeNode* root, string &str) {

        if(root == NULL) return;

        str += to_string(root -> val) + " ";

        preorder(root -> left, str);
        preorder(root -> right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preorder(root, res);
        return res;
    }

    TreeNode* build(vector<int> & preorder, int &index, int bound){

        if(index == preorder.size()) {
            return NULL;
        }

        if(preorder[index] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index++]);

        root -> left = build(preorder, index, root -> val);

        root -> right = build(preorder, index, bound);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty()) return NULL;

        stringstream ss(data);

        string str;

        vector<int> preorder;

        while(ss >> str) {
            preorder.push_back(stoi(str));
        }

        int index = 0;

        return build(preorder, index, INT_MAX);


        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;