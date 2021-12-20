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
    int h[n];
    for(int i=0;i<n;i++){cin>>h[i];}
    int dp[n];
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);
    }
    cout<<dp[n-1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
