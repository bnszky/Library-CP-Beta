ll rand(ll a, ll b){
    return rand()%(b-a+1) + a;
}

ll power(ll a, int k, ll MOD){
    if(k == 0) return 1;
    if(k == 1) return a;
    
    ll tmp = power(a, k/2, MOD);
    tmp%=MOD; tmp*=tmp; tmp%=MOD;
    if(k & 1) tmp*=a;
    return tmp;
}

bool miller_rabin(ll p, int q){
    
    if(p < 2) return false;
    ll s = 0, d;
    for(d = p-1; d&1; d>>=1) s++;
    
    for(int i = 0; i < q; i++){
        ll a = rand(2, p-1);
        ll x = power(a, d, p);
        if( (x == 1) or (x == p-1) ) continue;
        bool flag = true;
        for(int i = 0; i < s; i++){
            x*=x; x%=p;
            if( (x == 1) or (x == p-1 and i < s-1)) {
                flag = false;
                break;
            }
        }
        if(flag) return false;
    }
    
    return true;
    
}