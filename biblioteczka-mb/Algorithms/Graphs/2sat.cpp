namespace SAT2{
vector<vector<int>> edges;
stack<int> S;
vector<bool> vis;
vector<int> comp;

void reverse(vector<vector<int>> &A){
    vector<vector<int>> B;
    B.resize(A.size());
    for(int u = 0; u < A.size(); u++){
        for(auto v: A[u]){
            B[v].push_back(u);
        }
    }
    A = B;
}

void dfs(int v, int k){
    vis[v] = true;
    if(k != -1) comp[v] = k;

    for(auto u: edges[v]){
        if(!vis[u]){
            dfs(u, k);
        }
    }
    if(k == -1) S.push(v);
}

bool run(int n, vector<int>& res){
    vis.assign(n*2, 0);
    for(int i = 0; i < n*2; i++){
        if(!vis[i]) dfs(i, -1);
    }
    vis.assign(n*2, 0);

    reverse(edges);
    int cnt = 0;
    comp.resize(n*2);
    while(!S.empty()){
        auto nxt = S.top(); S.pop();
        if(!vis[nxt]){
            dfs(nxt, ++cnt);
        }
    }

    for(int i = 0; i < n*2; i+=2){
        if(comp[i] == comp[i+1]) return false;
        if(comp[i] > comp[i+1]) res.push_back(i/2);
    }

    return true;
}

void add_clause(int a, int b, bool neg_a, bool neg_b){
    a = (a*2)+neg_a;
    b = (b*2)+neg_b;
    edges[a^1].push_back(b);
    edges[b^1].push_back(a);
}

}