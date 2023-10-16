#include <bits/stdc++.h> 
using namespace std;

string f(int idx, int k, string &str){
	if(idx == str.length()){
		return "";
	}
	if(k == 0){
		int len = 0;
		string ans = "";
		for(int i=idx;i<str.length();i++){
			char c = str[i];
			while(i<str.length() && str[i] == c){
				i++;
				len++;
			}
			i--;
			ans += "" + c;
			ans += to_string(len);
			len = 0;
		}
		return ans;
	}
	string ans = "";
	int len = 0;
	int i = idx;
	while(i < str.length() && str[i] == str[idx]){
		i++;
		len++;
	}
	string take = string('x', str.length());
	string ptake = string('x', str.length());
	if(k >= len){
		take = f(i, k-len, str);
	}
	if(len > 9 && k >= len-9){
		ptake = str[idx] + to_string(len-9) + f(i, k-len+9, str);
	}
	string notTake =  str[idx] + to_string(len) + f(i, k, str);
	if(take.length() < ptake.length()){
		if(take.length() < notTake.length()){
			return take;
		}else{
			return notTake;
		}
	}else{
		if(notTake.length() < ptake.length()){
			return notTake;
		}else{
			return ptake;
		}
	}
	
}
int afterProcessing(string &str){
    if(str.length() == 0){
        return 0;
    }
	
	int ans = 0;
	char c;
	for(int i=0;i<str.length();i++){
		c = str[i];
		int cnt=0;
		string temp = "";
        i++;
		while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
			temp+=str[i];
			i++;
		}
		cnt += stoi(temp);
		temp = "";
        if(i == str.length()){
            ans += cnt;
            return ans;
        }
		while(str[i] == c){
			i++;
			while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
				temp+=str[i];
				i++;
			}
			cnt += stoi(temp);
			temp = "";
		}
		ans += 1 + to_string(cnt).length();
		if(i == str.length()){
			return ans;
		}else{
			i--;
		}
	}
	return ans;
}

int minLengthOfCompressedString(string &str, int k) 
{
	// Write your code here
	string compressed = f(0, k, str);
	cout<<compressed<<'\n';
    return afterProcessing(compressed);
	return 100;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string str;
        int k;
        getline(cin, str);
        getline(cin, str);
        cin>>k;
        cout << minLengthOfCompressedString(str, k)<<endl;
    }
}