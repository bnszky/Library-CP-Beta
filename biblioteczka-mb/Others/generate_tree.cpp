#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
    if(b < a) swap(a, b);
    return rand()%(b-a+1) + a;
}

int main(int argv, char** argc){
    srand(atoi(argc[1]));

    int n = 10;

    int j = 1;
    vector <int> parent;
    parent.resize(n+1);
    for(int i = 2; i <= n; i++){
        int k = rand(1, j); if(k == j) j++;
        parent[i] = k;
    }

}