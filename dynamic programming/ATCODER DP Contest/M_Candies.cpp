//Ceil of (a/b) is (a+b-1)/b

//Recursive solution for this problem is very difficult to implement

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
    int a[n+1];
    for(int i=1;i<=n;i++){cin>>a[i];}
    int dp[n+1][k+1];
    for(int i=1;i<=k;i++){dp[0][i]=0;}
    for(int i=0;i<=n;i++){dp[i][0]=1;}
    for(int i=1;i<=n;i++){
        vector<int>prefix(k+1);
        prefix[0]=1;
        for(int j=1;j<=k;j++){
            prefix[j]=(prefix[j-1]+dp[i-1][j])%mod;
        }
        for(int j=1;j<=k;j++){
            if(j>a[i]){
                dp[i][j]=(prefix[j]-prefix[j-a[i]-1]+mod)%mod;
            }
            else{
                dp[i][j]=(prefix[j])%mod;
            }
        }
    }
    cout<<(dp[n][k])%mod;

    
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
