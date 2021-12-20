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
int max(int a,int b,int c){
    if(a>b and a>c){return a;}
    else if(b>c){return b;}
    return c;
}
void solve()
{
    int n;cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){cin>>a[i]>>b[i]>>c[i];}
    int dp[n][3];
    dp[0][0]=a[0];dp[0][1]=b[0];dp[0][2]=c[0];
    for(int i=1;i<n;i++){
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
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
