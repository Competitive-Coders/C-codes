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

//0 means tiro
//1 means jiro
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(auto& i:a){cin>>i;}
    vector<vector<int>>dp(k+1,vector<int>(2));
    dp[0][0]=1;dp[0][1]=0;
    for(int i=1;i<=k;i++){
        bool p0=false,p1=false;
        for(auto x:a){
            if(x<=i and dp[i-x][1]==0){
                p0=true;
            }
            if(x<=i and dp[i-x][0]==1){
                p1=true;
            }
        }
        p0?dp[i][0]=0:dp[i][0]=1;
        p1?dp[i][1]=1:dp[i][1]=0;
    }

    if(dp[k][0]==0){cout<<"First";}
    else{cout<<"Second";}

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
