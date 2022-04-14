ll power(ll a, int b){
    if(b == 0) return 1;

    ll tmp = power(a, b/2);
    tmp *= tmp;
    if(b & 1) tmp *= a;
    return tmp;
}