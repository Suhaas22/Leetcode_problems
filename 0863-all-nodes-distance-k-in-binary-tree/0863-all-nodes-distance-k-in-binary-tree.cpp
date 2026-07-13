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
    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr -> left){
                    mpp[curr -> left] = curr;
                    q.push(curr -> left);
                }

                if(curr -> right){
                    mpp[curr -> right] = curr;
                    q.push(curr -> right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        queue<TreeNode*> q;
        q.push(target);
        int curr_dist = 0;


        while(!q.empty()){
            int size = q.size();
            if(curr_dist++ == k) break;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && !visited[node -> left]){
                    q.push(node -> left);
                    visited[node -> left] = true;
                }

                if(node -> right && !visited[node -> right]){
                    q.push(node -> right);
                    visited[node -> right] = true;
                }

                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front() -> val);
            q.pop();
        }

        return ans;
        
    }
};