class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int n = words.size();
        
        vector<string> res;
        vector<string> temp;

        int charlength = 0;

        for(int i = 0; i < n; i++){

            if(charlength + words[i].size()> maxWidth){

                int gaps = temp.size() - 1;

                string s;

                if(gaps == 0){
                    s = temp[0];
                    s += string(maxWidth - s.size(), ' ');
                }
                else {

                    int extraspaces = maxWidth - charlength + temp.size();

                    int spacingeach = extraspaces / gaps;
                    int reminder = extraspaces % gaps;

                    for(int j = 0; j < temp.size(); j++){

                        s += temp[j];

                        if(j < gaps){

                            s += string(spacingeach, ' ');

                            if(j < reminder){
                                s += " ";
                            }
                        }
                    }
                }

                res.push_back(s);
                temp.clear();
                charlength = 0;
            
        }

                        temp.push_back(words[i]);
                charlength += words[i].size() + 1;
        }

        string lastline;

        for(int j = 0; j < temp.size(); j++){

            lastline += temp[j];

            if(j < temp.size() - 1){
                lastline += " ";
            }
        }


        lastline += string(maxWidth - lastline.size(), ' ');

        res.push_back(lastline);


        return res;
    }

};