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
int n,k;
vector<int>dp,a;

int winner(int stones){
   if(dp[stones]!=-1){return dp[stones];}
   for(int i=1;i<=n;i++){
       if(stones>=a[i] and winner(stones-a[i])){
           dp[stones]=0;
           return dp[stones];
       }
   }
   dp[stones]=1;
   return dp[stones];
}
void solve()
{
    cin>>n>>k;
    dp.resize(k+1,-1);a.resize(n+1);
    for(int i=1;i<=n;i++){cin>>a[i];}
    dp[0]=1;
    if(winner(k)==0){cout<<"First";}
    else{cout<<"Second";}
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
