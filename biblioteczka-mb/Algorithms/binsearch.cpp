int binsearch(long long val){
    int l, r;
    int res = 0;

    while(l <= r){
        int mid = (l+r)/2;

        if(check(mid) <= val){
            l = mid+1;
            res = mid;
        }
        else {
            r = mid-1;
        }
    }

    return res;
}