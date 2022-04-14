int extended_gcd(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int k = extended_gcd(b%a, a, &x1, &y1);
    *x = y1 - (x1 * (b/a));
    *y = x1;
    return k;
}