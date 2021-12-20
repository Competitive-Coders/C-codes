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
    int n,k;cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++){cin>>h[i];}
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        int ans=INT_MAX;
        for(int j=1;(j<=k and j<=i);j++){
            ans=min(ans,llabs(h[i]-h[i-j])+dp[i-j]);
        }
        dp[i]=ans;
    }
    cout<<dp[n-1];
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
