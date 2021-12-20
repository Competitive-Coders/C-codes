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

vector<int>a,b,c;
vector<vector<int>>dp;
//0 means a
//1 means b
//2 means c
int maxi(int a,int b,int c){
    if(a>b and a>c){return a;}
    else if(b>c){return b;}
    return c;
}
int maxPoints(int day,int turn){
    if(dp[day][turn]!=-1){return dp[day][turn];}
    if(turn==0){dp[day][turn]=a[day]+max(maxPoints(day-1,1),maxPoints(day-1,2));}
    else if(turn==1){dp[day][turn]=b[day]+max(maxPoints(day-1,0),maxPoints(day-1,2));}
    else{dp[day][turn]=c[day]+max(maxPoints(day-1,0),maxPoints(day-1,1));}
    return dp[day][turn];
}
void solve()
{
    int n;cin>>n;
    a.resize(n+1);b.resize(n+1);c.resize(n+1);
    dp.resize(n+1,vector<int>(3,-1));
    for(int i=1;i<=n;i++){cin>>a[i]>>b[i]>>c[i];}
    dp[1][0]=a[1];dp[1][1]=b[1];dp[1][2]=c[1];
    cout<<maxi(maxPoints(n,0),maxPoints(n,1),maxPoints(n,2));

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
