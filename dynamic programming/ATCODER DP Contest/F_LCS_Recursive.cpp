//Ceil of (a/b) is (a+b-1)/b


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>PBDS;
string s,t;
vector<vector<int>>dp;

int lcs(int i_s,int i_t){
    if(dp[i_s][i_t]!=-1){return dp[i_s][i_t];}
    if(s[i_s-1]==t[i_t-1]){dp[i_s][i_t]=1+lcs(i_s-1,i_t-1);}
    else{
        dp[i_s][i_t]=max(lcs(i_s-1,i_t),lcs(i_s,i_t-1));
    }
    return dp[i_s][i_t];
}

void solve()
{
    cin>>s>>t;
    dp.resize(s.length()+1,vector<int>(t.length()+1,-1));
    for(int i=0;i<=s.length();i++){dp[i][0]=0;}
    for(int i=0;i<=t.length();i++){dp[0][i]=0;}
    lcs(s.length(),t.length());
    int i=s.length(),j=t.length();
    string ans;
    while(i>0 and j>0){
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){i--;}
        else{j--;}
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while (t--)
    {
        solve();
    }

    return 0;
}
