class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for(char label : tasks) {
            freq[label - 'A']++;
        }   

        priority_queue<int, vector<int>> pq;

        for(int i : freq) {
            if(i > 0) {
                pq.push(i);
            }
        }

        queue<pair<int, int>> cooldown;

        int time = 0;

        while(!pq.empty() || !cooldown.empty()) {

            time++;

            if(!pq.empty()) {
                int count = pq.top();
                pq.pop();

                count--;

                if(count > 0) {
                    cooldown.push({count, time + n});
                }
            }

            if(!cooldown.empty() && cooldown.front().second == time) {

                int rem_freq = cooldown.front().first;
                pq.push(rem_freq);

                cooldown.pop();
            }
        }


        return time;
    }
};