class Solution {
    private:
    unordered_map<string, int> level;
    vector<vector<string>> res;

    void dfs(string word, string beginWord, vector<string> & path) {
        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        int currlevel = level[word];

        string nword = word;

            for(int i = 0; i < nword.size(); i++) {
                char original = nword[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    nword[i] = ch;

                    if(level.find(nword) != level.end() && level[nword] == currlevel - 1) {
                        path.push_back(nword);
                        dfs(nword, beginWord, path);
                        path.pop_back();
                    }

                    nword[i] = original;
                }
            }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end()) {
            return {};
        }

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 0;
        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front();
            int steps = level[word];
            q.pop();

            for(int i = 0; i < word.size(); i++) {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.find(word) != st.end()) {
                        level[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }

                word[i] = original;
            }

        }

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return res;
    }
};