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

vector<vector<vector<int>>>dp;
vector<int>a;

int value(int i,int j,int turn){
    if(dp[i][j][turn]!=LLONG_MIN){return dp[i][j][turn];}
    if(i==j){
        if(turn==0){dp[i][j][turn]=a[i];}
        else{dp[i][j][turn]=-a[i];}
        return dp[i][j][turn];
    }
    if(turn==0){
        dp[i][j][turn]=max(a[i]+value(i+1,j,1),a[j]+value(i,j-1,1));
    }
    else{
        dp[i][j][turn]=min(value(i+1,j,0)-a[i],value(i,j-1,0)-a[j]);
    }
    return dp[i][j][turn];
}

void solve()
{
    int n;cin>>n;
    a.resize(n+1);
    dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,LLONG_MIN)));
    for(int i=1;i<=n;i++){cin>>a[i];}
    cout<<value(1,n,0);

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
