class Solution {
public:
    string decodeString(string s) {

        int n = s.size();

        stack<string> st;

        int i = 0;

        while(i < n){

            if(isdigit(s[i])){

                string num = "";

                while(i < n && isdigit(s[i])){
                    num += s[i];
                    i++;
                }

                st.push(num);
            }

            else if(s[i] == '['){
                st.push("[");
                i++;
            }
            else if(s[i] == ']'){

                vector<string> parts;

                while(st.top() != "["){
                    parts.push_back(st.top());
                    st.pop();
                }

                st.pop();

                string orig = "";

                for(int i = parts.size() - 1; i >= 0; i--) {
                    orig += parts[i];
                }

                int times = stoi(st.top());
                st.pop();

                string dec = "";

                for(int i = 0; i < times; i++){
                    dec += orig;
                }

                st.push(dec);
                i++;
            }
            else{
                st.push(string(1, s[i]));
                i++;
            }
        }

        vector<string> parts;

        while(!st.empty()){
            parts.push_back(st.top());
            st.pop();
        }

        string ans= "";

        for(int i = parts.size() - 1; i >= 0; i--){
            ans += parts[i];
        }


        return ans;
        
    }
};