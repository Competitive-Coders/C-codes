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

vector<int>wt,val;
vector<vector<int>>dp;

int maxSum(int index,int weight){
    if(dp[index][weight]!=-1){return dp[index][weight];}
    if(weight>=wt[index]){
        dp[index][weight]=max(val[index]+maxSum(index-1,weight-wt[index]),maxSum(index-1,weight));
    }
    else{
        dp[index][weight]=maxSum(index-1,weight);
    }
    return dp[index][weight];
}

void solve()
{
    int n,w;cin>>n>>w;
    wt.resize(n+1);val.resize(n+1);
    dp.resize(n+1,vector<int>(w+1,-1));
    for(int i=0;i<=n;i++){dp[i][0]=0;}
    for(int i=0;i<=w;i++){dp[0][i]=0;}
    for(int i=1;i<=n;i++){cin>>wt[i]>>val[i];}
    cout<<maxSum(n,w);
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
