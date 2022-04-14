vector<ll> dijkstra(int src, int n, vector<vector<pair<int,ll>>> edges){
    
    const ll INF = LONG_LONG_MAX;
    vector <ll> dist(n+1, INF);
    vector <bool> vis(n+1, 0);
    priority_queue<pair<ll,int>> Q;
    
    dist[src] = 0;
    Q.push({0, src});
    
    while(!Q.empty()){
        auto v = Q.top().s; Q.pop();
        vis[v] = true;
        for(auto u: edges[v]){
            if(!vis[u.f] and dist[v] + u.s < dist[u.f]){
                dist[u.f] = dist[v] + u.s;
                Q.push({-dist[u.f], u.f});
            }   
        }
    }
    
    return dist;
    
}