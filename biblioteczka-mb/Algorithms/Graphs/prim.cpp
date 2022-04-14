struct Edge{
    int u;
    ll w;
    int id;
};

vector<vector<Edge>> edges;

namespace MST2{
    
ll Prim(int n, vector<vector<Edge>> edges, vector<int> &res){

    int root = 1;
    priority_queue<pair<ll,pair<int, int>>> Q;
    for(auto x: edges[root]) {
        Q.push({-x.w, {x.u, x.id}});
    } 

    bool vis[n+1];
    fill(vis, vis+n+1, 0);

    vis[root] = true;
    ll ans = 0;

    while(!Q.empty()){
        auto nx = Q.top(); Q.pop();

        if(!vis[nx.second.first]){
            res.push_back(nx.second.second);
            ans -= nx.first;
            vis[nx.second.first] = true;

            for(auto v: edges[nx.second.first]){
                Q.push({-v.w, {v.u, v.id}});
            }
        }
    }

    return ans;
}

}