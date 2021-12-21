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
    int wt[n],val[n];
    for(int i=0;i<n;i++){cin>>wt[i]>>val[i];}
    const int max_limit=(int)1e5+1;
    int dp[n+1][max_limit]; //dp[i][j]=-1 means that value j cannot be made using first i elements
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<max_limit;j++){
            if((j>=val[i-1] and dp[i-1][j-val[i-1]]!=-1 and wt[i-1]+dp[i-1][j-val[i-1]]<=w) and dp[i-1][j]!=-1){
                dp[i][j]=min(wt[i-1]+dp[i-1][j-val[i-1]],dp[i-1][j]);
            }
            else if(j>=val[i-1] and dp[i-1][j-val[i-1]]!=-1 and wt[i-1]+dp[i-1][j-val[i-1]]<=w){
                dp[i][j]=wt[i-1]+dp[i-1][j-val[i-1]];
            }
            else if(dp[i-1][j]!=-1){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans;
    for(int i=0;i<max_limit;i++){
        if(dp[n][i]!=-1){ans=i;}
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
