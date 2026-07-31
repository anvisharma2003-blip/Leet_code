class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

       
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            graph[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (d > dist[node])
                continue;

            for (auto &it : graph[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    
    }
};