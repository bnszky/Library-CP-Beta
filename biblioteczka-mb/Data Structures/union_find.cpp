namespace Set{

const int N = 200005;

int rank[N];
int parent[N];

void init(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rank[i] = 1;
    }
}

int Find(int x){
    if(parent[x] != x) 
        return parent[x] = Find(parent[x]);
    return x;
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    if(x == y) return;

    if(rank[x] > rank[y]) swap(x,y);
    if(rank[x] == rank[y]) rank[x] ++;
    parent[x] = y;
}

}