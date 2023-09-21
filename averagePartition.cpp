// Similar to subset sum problem but with an additional constraint on the length of the subset
// time=O(n*2^n)(w/o dp) time=O(n*n*sum)(with dp)
//  bool customComp(vector<int> &A1,vector<int> &A2){
//  if(A1.size()<A2.size())
//  return true;
//  if(A1.size()==A2.size()){
//  int i=0;
//  while(i<A1.size() && A1[i]==A2[i])
//  i++;
//  return (i==A1.size() || A1[i]<A2[i]);
//  }
//  return false;
//  }
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

bool isPossible(int idx, int size, int sum, vector<int> &A, vector<int> &A1, vector<vector<vector<bool>>> &dp)
{
    // base cases
    if (size == 0)
        return sum == 0;
    if (idx == A.size())
        return false;
    // The very first time we get a solution we exit. So calcuations are getting repeated for false cases. 
    // So we check if (idx,size,sum) has already been
    // calculated i.e been set to false. If yes, return else calculate save and return.
    if (dp[idx][size][sum] == false)
        return dp[idx][size][sum];
    if (A[idx] <= sum)
    {
        // option1:use idx th element
        A1.push_back(A[idx]);
        if (isPossible(idx + 1, size - 1, sum - A[idx], A, A1, dp))
            return true;
        A1.pop_back();
        // this can also be done since A[idx]> sum so there's no point going any further since A is sorted
        //  if(isPossible(idx+1,size,sum,A,A1,dp))
        //  return true;
    }
    if (isPossible(idx + 1, size, sum, A, A1, dp))
        return true;
    return dp[idx][size][sum] = false;
}
vector<vector<int>> Solution::avgset(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int s = 0;
    for (int num : A)
        s += num;
    vector<vector<vector<bool>>> dp(101, vector<vector<bool>>(101, vector<bool>(5001, true)));
    // dp[i][j][k] tells if in A[i...n-1],there exists a subset of length j with sum k
    vector<vector<int>> ans;
    // subset1:sum=s1 size=n1 subset2:sum=s2 size=n2 For equal average partition:s1/n1==s2/n2 which leads to s1=(n1*s)/n
    // size of 1st subset can be from 1 to (n-1)(since both subsets need to be non-empty).
    //  if for a given n1, s1 comes out to be decimal we can straight away say that we can't find sum s1 in A
    for (int n1 = 1; n1 < n; n1++)
    {
        if ((n1 * s) % n == 0)
        {
            int s1 = (n1 * s) / n;
            vector<int> A1;
            if (isPossible(0, n1, s1, A, A1, dp))
            {
                vector<int> A2;
                int i = 0;
                for (int num : A1)
                {
                    while (i < n && A[i] != num)
                    {
                        A2.push_back(A[i]);
                        i++;
                    }
                    i++;
                }
                while (i < n)
                    A2.push_back(A[i++]);
                ans.push_back(A1);
                ans.push_back(A2);
                // The way we generated subset1, it will follow all the ordering constraints
                //  given in the question. So we dont really need to sort.
                //  sort(ans.begin(),ans.end(),customComp);
                break;
            }
        }
    }
    return ans;
}