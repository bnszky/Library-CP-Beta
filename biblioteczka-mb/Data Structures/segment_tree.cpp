template<typename T>
    struct segment_tree{

        vector<T> A;
        int sz;

        segment_tree(int _n) : sz((1<<(32-__builtin_clz(_n-1)))) {A.resize(sz*2+1);}

        T point(int x){
            x--; T res = 0;
            for(x+=sz; x > 0; x>>=1) res += A[x];
            return res;
        }

        void segment(int l, int r, T val){
            l--;
            for(l+=sz, r+=sz; l<r; l>>=1, r>>=1){
                if(l&1) A[l++] += val;
                if(r&1) A[--r] += val;
            }
        }

    };