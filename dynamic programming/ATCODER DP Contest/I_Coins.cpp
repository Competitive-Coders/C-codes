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
    int n;cin>>n;
    double p[n+1];
    for(int i=1;i<=n;i++){cin>>p[i];}
    double dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=(1-p[i])*dp[i-1][0];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=((p[i]*dp[i-1][j-1])+((1-p[i])*dp[i-1][j]));
        }
    }
    double ans=0;
    for(int i=(n+1)/2;i<=n;i++){
        ans+=dp[n][i];
    }
    cout<<setprecision(10)<<ans;

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
