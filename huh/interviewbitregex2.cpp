
bool checkTheMatch(int i,int j,const string &s1,const string &s2,vector<vector<bool>> &dp){
       
    if(i==-1 )
    return  j==-1;
   
    if(j==-1)
    {
        if(s1[i]=='*' && i==0)
        return true;
        return false;
    }
    if(dp[i][j]==false)
    return false;
   
    if(s1[i]==s2[j] || s1[i]=='?')
    return dp[i][j]=checkTheMatch(i-1,j-1,s1,s2,dp);
   
    if(s1[i]=='*')
    {
        return dp[i][j]=(checkTheMatch(i,j-1,s1,s2,dp) || checkTheMatch(i-1,j,s1,s2,dp));
    }
   
    return dp[i][j]= false;
   
}


int Solution::isMatch(const string s2, const string s1) {
   
    int n=s1.size(),m=s2.size();
 
    int i,j;
    string str;
    str+=s1[0];
    for(i=1;i<n;i++)
    {
        if(!(s1[i]=='*' && s1[i-1]=='*'))
        str+=s1[i];
    }
    n=str.size();
   
    vector<vector<bool>> dp(n+1,vector<bool> (m+1,true));
    return checkTheMatch(n-1,m-1,str,s2,dp);
   
   
}
