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
    int n,w;cin>>n>>w;
    int wt[n+1],val[n+1];
    for(int i=1;i<=n;i++){cin>>wt[i]>>val[i];}
    int dp[n+1][w+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j<wt[i]){dp[i][j]=dp[i-1][j];}
            else{
                dp[i][j]=max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][w];


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
