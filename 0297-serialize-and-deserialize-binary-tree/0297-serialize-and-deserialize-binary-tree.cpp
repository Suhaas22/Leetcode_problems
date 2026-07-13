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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                res += "N ";
                continue;
            }

            res += to_string(node -> val) + " ";
            q.push(node -> left);
            q.push(node -> right);
        }

        return res;
    }
        

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty()) return NULL;
        
        stringstream ss(data);
        string str;

        ss >> str;
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            ss >> str;
            if(str != "N"){
                node -> left = new TreeNode(stoi(str));
                q.push(node -> left);
            }

            ss >> str;
            if(str != "N") {
                node -> right = new TreeNode(stoi(str));
                q.push(node -> right);
            }
        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));