class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> graph(n);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto &it : graph[node]){

                int adj = it.first;
                int wt = it.second;

                long long newDist = d + wt;

                if(newDist < dist[adj]){

                    dist[adj] = newDist;
                    ways[adj] = ways[node];

                    pq.push({newDist, adj});
                }

                else if(newDist == dist[adj]){

                    ways[adj] = (ways[adj] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    
    }
};