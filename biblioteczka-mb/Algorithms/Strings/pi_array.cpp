vector<int> comp_pi(string s){

    vector <int> PI(s.size()+1);
    int b = PI[0] = -1;

    for(int i = 1; i <= s.size(); i++){
        while(b != -1 and s[b] != s[i-1]) b = PI[b];
        PI[i] = ++b;
    }
    
    return PI;

}