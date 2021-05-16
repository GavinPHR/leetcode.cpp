class Solution {
public:
    bool intersect(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) ++i;
            else if (a[i] > b[j]) ++j;
            else return true;
        }
        return false;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int N = routes.size();
        for (auto &route : routes) sort(route.begin(), route.end()); // sorted for intersection and binsearch
        vector<vector<int>> graph(N, vector<int>());
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (intersect(routes[i], routes[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        unordered_set<int> visited, S, T;
        for (int i = 0; i < N; ++i) {
            if (binary_search(routes[i].begin(), routes[i].end(), source)) S.insert(i);
            if (binary_search(routes[i].begin(), routes[i].end(), target)) T.insert(i);
        }
    
        // Init queue
        deque<pair<int, int>> q; // <route_number, number of routes taken>
        for (auto &s : S) q.push_back(make_pair(s, 1));

        while (!q.empty()) {
            auto [route, n] = q.front();
            if (T.find(route) != T.end()) return n;
            for (auto &neigh : graph[route]) {
                if (visited.find(neigh) != visited.end()) continue;
                q.push_back(make_pair(neigh, n + 1));
                visited.insert(neigh);
            }
            q.pop_front();
        }
        return -1;
    }
};