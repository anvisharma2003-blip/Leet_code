class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }

        // Maximum probability to reach each node
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        // Max Heap: {probability, node}
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {

            auto [currProb, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if (currProb < prob[node])
                continue;

            // Reached destination
            if (node == end_node)
                return currProb;

            for (auto &it : graph[node]) {

                int adjNode = it.first;
                double edgeProb = it.second;

                double newProb = currProb * edgeProb;

                if (newProb > prob[adjNode]) {
                    prob[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }

        return 0.0;
    }
};