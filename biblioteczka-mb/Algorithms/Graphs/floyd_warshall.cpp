namespace floyd_warshall{
    
    vector <vector<ll>> dist;
    const ll INF = LONG_LONG_MAX;
    int n;
    
    void init(int _n){
        n = _n;
        dist.resize(n+1);
        for(int i = 0; i <= n; i++) dist[i].assign(n+1, INF);
    }
    
    void run(){
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if( (dist[i][k] != INF and dist[k][j] != INF) 
                    and (dist[i][k] + dist[k][j] < dist[i][j]) ){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    void add_edge(int u, int v, ll w){
        dist[u][v] = w;
    }
    
    ll shortest_path(int u, int v){
        return dist[u][v];
    }
    
}