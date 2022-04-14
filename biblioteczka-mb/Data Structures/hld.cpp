namespace HLD{

////////////////////////////////////////////////////////////////////

int magic(int x) {return x&(-x);}

template<typename T>
struct fenwick_tree{

    vector <T> A;
    size_t n;

    fenwick_tree(int _n) {init(_n);}
    fenwick_tree() {}

    void init(int _n) {n = _n; A.resize(n+1);}

    T point(int x, T val){
        T res = 0;
        for(; x<=n; x+=magic(x)) res += A[x] += val;
        return res; 
    }

    T segment(int l, int r, T val){
        if(l != 0) return (segment(0, r, val) - segment(0, l-1, -val));
        T res = 0;
        for(; r>0; r-=magic(r)) res += A[r] += val;
        return res;
    }
    
};

////////////////////////////////////////////////////////////////////

vector <vector <Edge>> edges;
vector <pair<int,ll>> parent;
int root;
int n;

vector <int> sz;
vector <int> dep;
vector <pair<int,int>> paths;
pair<int,int> curr;
unordered_map <int,int> ptr;

fenwick_tree<ll> tree;
vector <int> pos; 

namespace LCA{

int sz;

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
    comp_anc(v, parent);
    for(auto u: edges[v]){
        dfs(u.adj, v);
    }
}

void run(){
    sz = 32-__builtin_clz(n-1);
    anc.resize(n+1);
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

}

////////////////////////////////////////////////////////////////////

void dfs(int v){
    for(auto u: edges[v]){
        dep[u.adj] = dep[v] + 1;
        dfs(u.adj);
        sz[v] += sz[u.adj];
    }
}

void dfs2(int v){
    for(auto u: edges[v]){
        dfs2(u.adj);
        if(sz[v]/2 < sz[u.adj]){
            if(curr.second == u.adj) {
                curr.second = v;
                ptr[v] = paths.size();
            }
            else {
                paths.push_back(curr);
                curr = {u.adj, v};
                ptr[u.adj] = paths.size();
                ptr[v] = paths.size();
            }
        }
    }
}

void add_on_edge(int x, ll val){
    if(ptr[x] != 0){
        int a = dep[paths[ptr[x]].f]-dep[x] + 1;
        a += pos[ptr[x]];
        tree.point(a, val);
    }
    else if(x != root) parent[x].s += val;
}

ll get_sum(int u, int v){
    //cout << "GET_SUM: " << u << " " << v << "\n";
    ll res = 0;
    int high = dep[v];
    
    while(dep[u] > high){
        if(ptr[u] != 0){
            int b;
            int a = dep[paths[ptr[u]].f] - dep[u] + 1; 
            if(dep[paths[ptr[u]].s] >= high) b = dep[u] - dep[paths[ptr[u]].s] - 1;
            else b = dep[u] - high - 1;

            a += pos[ptr[u]];
            res += tree.segment(a, a+b, 0);
            u = paths[ptr[u]].s;  
        }
        else {
            res += parent[u].s;
            u = parent[u].f;
        }
    }

    return res;
}

ll get_sum_on_path(int a, int b){
    int c = LCA::lca(a, b);
    return get_sum(a, c) + get_sum(b, c);
}

void init(int _n, int _root){
    n = _n;
    root = _root;
    edges.resize(n+1);
    parent.assign(n+1, {-1, -1});
}

void run(){
    sz.assign(n+1, 1);
    dep.assign(n+1, 0);
    curr = {0,0};

    dfs(root);
    dfs2(root);
    paths.push_back(curr);
    LCA::run();

    for(auto x: paths) ptr[x.s] = 0;

    pos.assign(n+1, 0);
    for(int i = 1; i < paths.size()-1; i++){
        int diff = dep[paths[i].f] - dep[paths[i].s];
        pos[i+1] = pos[i] + diff;
    }

    int k = paths.size()-1;
    tree.init(pos[k] + dep[paths[k].f] - dep[paths[k].s]);

    for(int i = 2; i <= n; i++) if(ptr[i] != 0) add_on_edge(i, parent[i].s);

}

void add_edge(int a, int b, ll val){
    parent[b] = {a, val};
    edges[a].push_back({b, val});
}

}