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

void solve()
{
    string s,t;cin>>s>>t;
    int dp[s.length()+1][t.length()+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans;
    int i=s.length(),j=t.length();
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
