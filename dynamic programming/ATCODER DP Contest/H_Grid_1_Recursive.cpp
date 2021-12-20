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

vector<vector<char>>grid;
vector<vector<int>>dp;

int paths(int i,int j){
    if(dp[i][j]!=-1){return dp[i][j];}
    if(grid[i][j]=='#'){
        dp[i][j]=0;
        return dp[i][j];
    }
    dp[i][j]=(paths(i-1,j)+paths(i,j-1))%mod;
    return dp[i][j];
}

void solve()
{
    int h,w;cin>>h>>w;
    grid.resize(h+1,vector<char>(w+1));
    dp.resize(h+1,vector<int>(w+1,-1));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<=h;i++){dp[i][1]=0;}
    for(int i=1;i<=h;i++){
        if(grid[i][1]=='#'){break;}
        dp[i][1]=1;
    }
    for(int i=1;i<=w;i++){dp[1][i]=0;}
    for(int i=1;i<=w;i++){
        if(grid[1][i]=='#'){break;}
        dp[1][i]=1;
    }
    cout<<paths(h,w);
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
