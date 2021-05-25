class Solution {
public:
    static constexpr uint8_t WHITE = 0, GREY = 1, BLACK = 2;

    bool dfs(int node, 
             unordered_map<int, vector<int>> &graph, 
             unordered_map<int, uint8_t> &colours) {
        colours[node] = GREY;
        for (auto neigh : graph[node]) {
            if (colours[neigh] == GREY) return false;
            if (colours[neigh] == BLACK) continue;
            if (!dfs(neigh, graph, colours)) return false;
        }
        colours[node] = BLACK;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        unordered_map<int, vector<int>> graph;
        for (auto v : prerequisites) {
            if (graph.find(v[1]) == graph.end()) graph[v[1]] = vector<int>();
            graph[v[1]].push_back(v[0]);
        }
        
        unordered_map<int, uint8_t> colours;
        for (auto &[k, v] : graph) {
            colours[k] = WHITE;
        }
        
        for (auto &[k, v] : graph) {
            if (colours[k] == BLACK) continue;
            if (!dfs(k, graph, colours)) return false;
        }
        return true;
    }
};