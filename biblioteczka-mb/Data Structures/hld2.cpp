namespace lazy_propagation{

    vector <ll> tree;
    vector <ll> lazy;

    int siz;
    ll res;

    void update(int v){
        tree[v] = tree[v<<1] + tree[(v<<1)^1];
    }

    void push(int v, int k){
        tree[v] += lazy[v]*k;
        if((v<<1) < (siz<<1)){
            lazy[v<<1] += lazy[v];
            lazy[(v<<1)^1] += lazy[v];
        }
        lazy[v] = 0;
    }

    void segment(int l, int r, int a, int b, int v, ll val){
        push(v, b-a+1);
        if(l <= a and b <= r){
            lazy[v] += val;
            res += tree[v];
        }
        else if((a <= l and l <= b) or (a <= r and r <= b)){
            int mid = (a+b)/2;
            segment(l, r, a, mid, (v<<1), val);
            segment(l, r, mid+1, b, (v<<1)^1, val);
            update(v);
        }
        push(v, b-a+1);
    }

    void add_on_range(int a, int b, ll val){
        segment(a-1, b-1, 0, siz-1, 1, val);
    }

    ll get_sum_on_range(int a, int b){
        res = 0;
        segment(a-1, b-1, 0, siz-1, 1, 0);
        return res; 
    }

    void init(int n, vector <ll> v){
        siz = (1<<(32-__builtin_clz(n-1)));
        res = 0;
        tree.resize(2*siz);
        lazy.resize(2*siz);

        for(int i = 0; i < v.size(); i++) tree[i+siz] = v[i];
        for(int i = siz-1; i > 0; i--) update(i);
    }

}