bool is_cycled(int n, vector <pair<int,int>> edges){
    queue<int> Q;
    vector <vector<int>> x(n+1);
    vector <int> out(n+1);

    for(int i = 0; i < (int)edges.size(); i++){
        x[edges[i].s].push_back(edges[i].f);
        out[edges[i].f] ++;
    }

    for(int i = 1; i <= n; i++) if(out[i] == 0) Q.push(i);
    int cnt = 0;

    while(!Q.empty()){
        auto v = Q.front(); Q.pop(); cnt++;
        for(auto u: x[v]){
            out[u] --;
            if(out[u] == 0) Q.push(u);
        }
    }

    if(cnt < n) return true;
    else return false;
}