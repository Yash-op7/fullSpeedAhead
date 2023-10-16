long long f(int idx, int k, vector<long> &c){
    if(k==0){
        return 1;
    }
    if(idx == (int)c.size()){
        return 0;
    }
    if(k >= c[idx]){
        ll take =  f(idx, k-c[idx], c);
        ll notTake = f(idx+1, k, c);
        return min(take, notTake);
    }
    return  f(idx+1, k, c);
}