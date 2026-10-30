class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        if (k < 1) return -1;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) continue;

            if (u == n - 1) return (int)d;

            for (auto [v, w] : adj[u]) {
                int nextCnt;

                if (labels[u] == labels[v]) {
                    nextCnt = cnt + 1;
                } else {
                    nextCnt = 1;
                }

                if (nextCnt > k) continue;

                long long nd = d + w;

                if (nd < dist[v][nextCnt]) {
                    dist[v][nextCnt] = nd;
                    pq.push({nd, v, nextCnt});
                }
            }
        }

        return -1;
    }
};