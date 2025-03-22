class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);  // Undirected edge
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                vector<int> nodes;
                int edgeCount = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    nodes.push_back(curr);
                    edgeCount += graph[curr].size();  

                    for (int neighbor : graph[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                int k = nodes.size();
                if (edgeCount == k * (k - 1)) {  
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};