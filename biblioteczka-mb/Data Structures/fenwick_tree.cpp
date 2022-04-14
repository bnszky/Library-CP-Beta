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