#include <bits/stdc++.h>

using namespace std;

class disjoint_set {
private:
    vector<int> rank, par;
public:
    disjoint_set(int n) {
        rank.resize(n+1);
        par.resize(n+1);
        for (int i=1; i<=n; i++)
            par[i] = i;
    }

    int find(int u) {
        if (u != par[u])
            par[u] = find(par[u]);
        return par[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;

        if (rank[u] > rank[v])
            swap(u, v);

        par[u] = v;

        if (rank[v] == rank[u])
            rank[v]++;
    }
    // this method is used to get count of groups in sorted way
    vector<int> get_groups() {
        int n = par.size()-1;
        unordered_map<int, int> umap;
        for (int i=1; i<=n; i++) 
            umap[find(i)]++;
        
        vector<int> result;
        for (auto v : umap)
            result.push_back(v.second);

        sort(result.begin(), result.end());
        return result;
    }
};

int max_less_than_equal(vector<int> &v, int val) {
    int begin = 0, end = v.size()-1;

    while (begin <= end) {
        int mid = (begin+end)/2;

        if (v[mid] <= val)
            begin = mid+1;
        else 
            end = mid-1;
    }

    return end;
}

int max_less_than(vector<int> &v, int val) {
    int begin = 0, end = v.size()-1;

    while (begin <= end) {
        int mid = (begin+end)/2;

        if (v[mid] < val)
            begin = mid+1;
        else 
            end = mid-1;
    }

    return end;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, n, m, q, v, u, l, r;
    cin>>T;
    while (T--) {
        cin>>n>>m>>q;
        disjoint_set dsu(n);
        for (int i=0; i<m; i++) {
            cin>>u>>v;
           dsu.unite(u, v);
        }
        vector<int> groups = dsu.get_groups();

        while (q--) {
            cin>>l>>r;
            int right = max_less_than_equal(groups, r),
            left = max_less_than(groups, l);

            int result = right-left;
            cout<<result<<'\n';
        }
    }
}
