#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int f(int k, priority_queue<vi>&q){
    int retVal = 0;
    while(!q.empty()){
        int curr = q.top()[0];
        q.pop();
        int cnt=0;
        while(curr != k){
            if(curr - 5 >=k){
                cnt++;
                curr-=5;
            }else{
                break;
            }
        }
        while(curr != k){
            if(curr - 2 >=k){
                cnt++;
                curr-=2;
            }else{
                break;
            }
        }
        while(curr != k){
            if(curr - 1 >=k){
                cnt++;
                curr-=1;
            }else{
                break;
            }
        }
        return cnt;
    }
}

int equal(vector<int> a) {
    priority_queue<vi>q;
    int n = a.size();
    int smallest=1e9;

    for(int i=0;i<n;i++){
        q.push({a[i], i});
        smallest=min(smallest, a[i]);
    }
    priority_queue<vi> q1, q2, q3, q4;
    q4 = q;
    q3 = q;
    q1 = q;
    q2 = q;
    int retVal = 1e9;
    retVal = min({retVal, f(smallest q1), f(smallest-1, q2) , f(smallest-2, q3), f(smallest-5, q4)});
    return retVal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
