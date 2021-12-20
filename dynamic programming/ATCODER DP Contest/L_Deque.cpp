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
//0 means taro
//1 means jiro
void solve()
{
    int n;cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){cin>>a[i];}
    int dp[n+1][n+1][2];
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            if(i==j){
                dp[i][j][0]=a[i];
                dp[i][j][1]=-a[i];
            }
            else{
                dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
                dp[i][j][1]=min(dp[i+1][j][0]-a[i],dp[i][j-1][0]-a[j]);
            }
        }
    }
    cout<<dp[1][n][0];

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
