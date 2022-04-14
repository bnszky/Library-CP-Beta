namespace LCA{

int sz;
int root;

vector<bool> vis;
vector<int> dep;
vector <vector<int>> anc;

void comp_anc(int v, int parent){
    anc[v].resize(sz);
    fill(anc[v].begin(), anc[v].end(), root);

    for(int i = 0; i < sz and parent != root; i++){
        anc[v][i] = parent;
        parent = anc[parent][i];
    }
}

void dfs(int v, int parent){
    vis[v] = true;
    comp_anc(v, parent);

    for(auto u: edges[v]){
        if(!vis[u]){
            dep[u] = dep[v] + 1;
            dfs(u, v);
        }
    }
}

void run(int _sz, int _root){
    vis.assign(_sz+1, 0);
    dep.assign(_sz+1, 0);
    anc.resize(_sz+1);
    sz = 32-__builtin_clz(_sz-1);
    root = _root;
    dfs(root, root);
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];

    for(int i = 0; i < sz; i++){
        if(diff & (1<<i))
            u = anc[u][i];
    }

    assert(dep[u] - dep[v] == 0);
    if(u == v) return u;

    for(int i = sz-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }   
    }

    return anc[u][0];
}

int lca(int r, int a, int b){
    int c = lca(a,r);
    int d = lca(b,r);

    if(c == d) return lca(a,b);
    else {
        if(dep[c] < dep[d]) swap(c,d);
        return c;
    }
}

int dist(int u, int v){
    return dep[u] + dep[v] - dep[lca(u,v)]*2;
}

}