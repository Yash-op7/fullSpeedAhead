#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

bool check(int curr, int x, int n, int total){
    if (curr == 14)
    {
        cout << total << endl;
    }

    total -= curr;
	if(total<0){
		return false;
	}
    if(curr==14){cout<<total<<endl;}
	int k = curr;
	for(int i=x-1;i>0;i--){
		if(k == 1){
			total-=1;
		}else{
			total-=(k-1);
			k--;
		}
		if(total < 0){
			return false;
		}
        if (curr == 14)
        {
            cout << total << endl;
        }
    }
	k = curr;
	for(int i=x+1; ;i++){
		if(k == 1){
			total-=1;
		}else{
			total-=(k-1);
			k--;
		}
		if(total < 0){
			return false;
		}
        if (curr == 14)
        {
            cout << total << endl;
        }
    }
	return true;
}

int maxVaccinesAdministered(int n, int dayNumber, int maxVaccines)
{
	int l = 1;
	int r = maxVaccines;;
	int ans = 1;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid, dayNumber, n, maxVaccines)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	return ans;
}

int main(){
    cout<<maxVaccinesAdministered(9,2,100);
}