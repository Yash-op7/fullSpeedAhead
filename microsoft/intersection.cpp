ll get_intersections(vector<int>po&v, int num){
    ll n = v.size();
    ll cnt = 0;
    for(int i=0; i<n-1; i++){
        ll st = min(v[i], v[i+1]);
        ll en = max(v[i], v[i+1]);
        if(st<num && num <en) cnt++;
    }
    for(int i=0; i<n; i++) if(v[i] == num) cnt++;
    return cnt;
}

int func(vector<int> v){
    ll n = v.size();
    vector<pair<int, int>> vec;
    for(int i=0; i<n-1; i++){
        ll st = min(v[i], v[i+1]);
        ll en = max(v[i], v[i+1]);
        vec.push_back({st, 1});
        vec.push_back({en, -1});
    }
    sort(vec.begin(), vec.end());
    ll cnt = 0;
    ll res = 0;
    for(auto &it: vec){
        cnt += it.second;
        res = max(res, cnt);
    }
    res = max(res, get_intersections(v, v[0]));
    res = max(res, get_intersections(v, v[n-1]));
    return res;
}