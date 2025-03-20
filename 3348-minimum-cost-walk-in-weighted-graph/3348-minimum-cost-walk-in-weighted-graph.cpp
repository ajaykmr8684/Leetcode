class Solution {
public:
    struct DSU {
        vector<int> par;
        DSU(int n) { par.resize(n + 1, -1); }
        int findParent(int a) {
            if (par[a] < 0)
                return a;
            return par[a] = findParent(par[a]);
        }
        bool unionSet(int a, int b) {
            a = findParent(a);
            b = findParent(b);
            if (a == b)
                return 0;
            if (par[a] > par[b])
                swap(a, b);
            par[a] += par[b];
            par[b] = a;
            return 1;
        }
        bool sameSet(int x, int y) { return findParent(x) == findParent(y); }
        int size(int x) { return -par[findParent(x)]; }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1];
            dsu.unionSet(u, v);
        }

        unordered_map<int, int> bitwiseAnd;

        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            int par = dsu.findParent(u);
            if (bitwiseAnd.count(par)) {
                bitwiseAnd[par] &= w;
            } else {
                bitwiseAnd[par] = w;
            }
        }

        vector<int> res;
        for (auto& it : query) {
            int u = it[0], v = it[1];
            if (!dsu.sameSet(u, v)) {
                res.push_back(-1);
            } else {
                int par = dsu.findParent(u);
                res.push_back(bitwiseAnd[par]);
            }
        }

        return res;
    }
};