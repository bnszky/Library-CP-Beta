struct Edge{
    int u;
    ll w;
    int id;
};

vector <vector<Edge>> edges;

namespace MST1{

struct E{
    int u;
    int v;
    ll w;
    int id;
};

bool cmp(E a, E b){
    return a.w < b.w;
}

vector <E> A;

namespace Set{

    const int N = 1005;

    int parent[N];
    int rank[N];

    void init(int n){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int Find(int x){
        if(x != parent[x]) return parent[x] = Find(parent[x]);
        return x;
    }

    void Union(int x, int y){
        x = Find(x); y = Find(y);

        if(x == y) return;

        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x] ++;

        parent[y] = x;
    }

}

ll Kruskal(int n, vector<vector<Edge>> G, vector <int> &res){
    for(int u = 1; u <= n; u++){
        for(auto v: G[u]){
            A.push_back({u,v.u,v.w,v.id});
        }
    }  

    sort(A.begin(), A.end(), cmp);
    bool vis[n+1];
    fill(vis, vis+n+1, 0);

    ll ans = 0;

    Set::init(n);
    for(auto x: A){
        if(!vis[x.id] and Set::Find(x.u) != Set::Find(x.v)){
            vis[x.id] = true;

            Set::Union(x.u, x.v);
            ans += x.w;
            res.push_back(x.id);
        }    
    }

    return ans;
}

}