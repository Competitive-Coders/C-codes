//Ceil of (a/b) is (a+b-1)/b

//Recursive
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
vector<vector<int>>adj;
vector<int>dp;
int dfs(int curr_node){
    if(dp[curr_node]!=-1){return dp[curr_node];}
    int ans=INT_MIN;
    for(auto node:adj[curr_node]){
        ans=max(ans,dfs(node));
    }
    if(ans==INT_MIN){ans=0;}
    else{ans++;}
    dp[curr_node]=ans;
    return dp[curr_node];
}
void solve()
{
    int n,m;cin>>n>>m;
    adj.resize(n+1);dp.resize(n+1,-1);
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        if(dp[i]==-1){
            dp[i]=dfs(i);
        }
        ans=max(ans,dp[i]);
    }
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
