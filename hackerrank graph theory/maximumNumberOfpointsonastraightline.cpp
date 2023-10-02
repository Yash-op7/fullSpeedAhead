

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>

float slope(vi &a, vi &b){
	int den = b[0] - a[0];
	int num = b[1] - a[1];
	if(den == 0){
		return 1e9;
	}
	if(num == 0){
		return 0;
	}
	return num/den;
}

float get_y_intercept(vvi &a){
	vi p1 = a[0];
	vi p2 = a[1];
	float m = slope(p1, p2);
	return (p1[1] - m*p1[0]);
}

int maxPointsOnLine(vector<vector<int>> &points, int n) {
	// Write your code here.
	auto uniqueNums = unique(points.begin(), points.end());
    points.erase(uniqueNums, points.end());

    map<float, vector<vvi>> slopes;
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			slopes[slope(points[i], points[j])].push_back({points[i], points[j]});
		}
	}
	int ans = 1;
	for( auto m:slopes){
		ans = max(ans, 2);
		int sz = m.second.size();
		vvvi pairs = m.second;
		int max_cnt = 1;
		if(sz > 1){
			map<float, int> y_intercept_cnt;
			for( auto p1:pairs){
				y_intercept_cnt[get_y_intercept(p1)]++;
				max_cnt = max(max_cnt, y_intercept_cnt[get_y_intercept(p1)]);
			}
		}
		ans = max(ans, max_cnt/2);
	}
	return ans;
}