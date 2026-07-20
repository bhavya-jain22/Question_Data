class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue <
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        > pq;

        int n = apples.size(),  cur_day = 1, appleEaten = 0;
        for(int i=0; i<n; i++) {            
            if(apples[i]) pq.push({days[i]+i, apples[i]});
            while(!pq.empty() && pq.top().first <  cur_day) pq.pop();
            if(!pq.empty()) {
                auto [expiry_d, app] = pq.top();
                pq.pop();
                if(expiry_d >= cur_day && app>0) {
                    appleEaten++;
                    app--;
                    if(expiry_d > cur_day && app) pq.push({expiry_d, app});
                }
            }
            cur_day++;
        }

        while(!pq.empty()) {
            while(!pq.empty() && pq.top().first <  cur_day) pq.pop();
            if(!pq.empty()) {
                auto [expiry_d, app] = pq.top();
                pq.pop();
                if(expiry_d >= cur_day && app>0) {
                    app--;
                    appleEaten++;
                    if(expiry_d > cur_day && app) pq.push({expiry_d, app});
                }
            }
            cur_day++;
        }
        return appleEaten;

    }
};