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

int min_cost(int n){
    if(dp[n]!=-1){return dp[n];}
    dp[n]=min(llabs(h[n]-h[n-1])+min_cost(n-1),llabs(h[n]-h[n-2])+min_cost(n-2));
    return dp[n];
}

void solve()
{
  int n;cin>>n;
  h.resize(n+1);dp.resize(n+1,-1);
  for(int i=1;i<=n;i++){cin>>h[i];}
  dp[1]=0;dp[2]=llabs(h[2]-h[1]);
  cout<<min_cost(n);
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
