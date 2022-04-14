vector<pair<int,int>> find_prime_factors(int n){
    vector<pair<int,int>> S;
    int q = sqrt(n);
    while(!(n & 1)) {
        n>>=1; 
        if(!S.empty()) S[S.size()-1].second ++;
        else S.push_back({2, 1});
    }
    
    for(int i = 3; i <= q; i+=2){
        while(n%i == 0){
            if(!S.empty() and S[S.size()-1].first == i) S[S.size()-1].second ++;
            else S.push_back({i, 1});
            n/=i;
        }
    }
    if(n > 1) {
        if(!S.empty() and S[S.size()-1].first == n) S[S.size()-1].second ++;
        else S.push_back({n, 1});
    }
    return S;
}