class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> store;
        int total_capital = w;
        int n = profits.size();
        for(int i=0;i<n;i++){
            store.push_back({capital[i],profits[i]});
        }
        sort(store.begin(), store.end());
        priority_queue<int> pq;
        int i = 0;
        while(k--){
            for(;i<n;i++){
                int profit = store[i].second;
                int capital = store[i].first;
                if(capital > total_capital) break;
                pq.push(profit);
            }
            if(pq.empty()){
                break; 
            }
            int ideal_profit = pq.top();
            pq.pop();
            total_capital += ideal_profit;
            
        }
        return total_capital;
    }
};
