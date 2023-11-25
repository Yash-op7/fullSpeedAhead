vector<vector<int>> inds(26);

bool good(ll k, ll n, vector<int> &c){
    vector<ll> vec(n+1);
    for(int i=0; i<k; i++) vec[c[i]] = 1;
    for(int i=1; i<n+1; i++) vec[i] += vec[i-1];
    for(auto &ele: inds){
        int len = ele.size();
        for(int j=0; j<len-1; j++){
            if(vec[ele[j]] == vec[ele[j+1]]) return 0;
        }
    }
    return 1;
}

int solution(string &str, vector<int> &c){
    ll n = str.length();
    ll m = c.size();
    for(int i=0; i<n; i++){
        inds[str[i] - 'a'].push_back(i);
    }
    ll l = -1, r = m+1;
    while(l+1<r){
        ll mid = (l+r)/2;
        if(good(mid, n, c)) r = mid;
        else l = mid;
    }
    if(r == m+1) return -1;
    return r;
}