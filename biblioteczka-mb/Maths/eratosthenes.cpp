vector <bool> eratosthenes_sieve(int n){
    //slower version
    vector <bool> prime_num(n+1, 1);
    
    prime_num[0] = prime_num[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(prime_num[i]){
           for(int j = i*i; j <= n; j+=i) prime_num[j] = false; 
        }
    }
    return prime_num;
}