class unionFind {
public:
    vector<int> parent;
    vector<int> rank;
    unionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findP(int u) {
        if (u != parent[u])
            parent[u] = findP(parent[u]);
        return parent[u];
    }
    void uf(int u, int v) {
        u = findP(u), v = findP(v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            ++rank[u];
        }
    }
    int noOFGraph(int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (i == findP(i))
                cnt++;
        return cnt;
    }

    void setGraph(int n, vector<int>& edgesCount) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int e = parent[i];
            if (!mp[e])
                mp[e] = 1;
            else
                mp[e] += 1;
        }

        for (auto i : mp)
            edgesCount.push_back(i.second);
    }
    long long answer(vector<int>& edgesCount) {
        long long sum = 0;
        int ec = edgesCount.size();
        for (int i = 0; i < ec; i++)
            for (int j = i + 1; j < ec; j++)
                sum += static_cast<long long>(edgesCount[i]) *
                       static_cast<unsigned long long>(edgesCount[j]);
        return sum;
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        if (!edges.size())
            return (static_cast<long long>(n - 1) * static_cast<long long>(n)) / 2;
        ios_base::sync_with_stdio(false);
        vector<int> edgesCount;
        unionFind obj(n);
        for (auto i : edges)
            obj.uf(i[0], i[1]);
        obj.noOFGraph(n);
        obj.setGraph(n, edgesCount);
        return obj.answer(edgesCount);
    }
};