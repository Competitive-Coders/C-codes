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
             
vector<int>h,dp;

int min_cost(int n,int k){
    if(dp[n]!=-1){return dp[n];}
    int ans=INT_MAX;
    for(int i=1;i<=n and i<=k;i++){
        ans=min(ans,llabs(h[n]-h[n-i])+min_cost(n-i,k));
    }
    dp[n]=ans;
    return dp[n];
}

void solve()
{
    int n,k;cin>>n>>k;
    h.resize(n+1);dp.resize(n+1,-1);
    for(int i=1;i<=n;i++){cin>>h[i];}
    dp[1]=0;
    cout<<min_cost(n,k);
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
