class Twitter {
    private:
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;  // {timestamp, tweetId}

public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;

        // pushing user's own tweets

        if(!tweets[userId].empty()) {
            int index = tweets[userId].size() - 1;

            pq.push({
                tweets[userId][index].first,
                tweets[userId][index].second,
                userId,
                index
            });
        }

        for(auto followee : followers[userId]) {

            if(!tweets[followee].empty()) {

                int index = tweets[followee].size() - 1;

                pq.push({
                    tweets[followee][index].first,
                    tweets[followee][index].second,
                    followee,
                    index
                });
            }
        }

        vector<int> res;

        while(!pq.empty() && res.size() < 10) {

            auto current = pq.top();
            pq.pop();

            int timestamp = current[0];
            int tweetid = current[1];
            int userid = current[2];
            int index = current[3];

            res.push_back(tweetid);

            if(index > 0) {
                index--;

                pq.push({
                    tweets[userid][index].first,
                    tweets[userid][index].second,
                    userid,
                    index
                });
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */