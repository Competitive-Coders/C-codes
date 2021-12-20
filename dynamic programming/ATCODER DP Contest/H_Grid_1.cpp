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
    int h,w;cin>>h>>w;
    char grid[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){cin>>grid[i][j];}
    }
    int dp[h][w];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<w;i++){
        if(grid[0][i]=='#'){break;}
        dp[0][i]=1;
    }
    for(int i=0;i<h;i++){
        if(grid[i][0]=='#'){break;}
        dp[i][0]=1;
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(grid[i][j]=='#'){continue;}
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[h-1][w-1];

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
