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
const int maxLimit=(int)1e5;
vector<int>wt,val;
vector<vector<int>>dp;
int n,w;

int maxSum(int index,int value){
    if(dp[index][value]!=-1){return dp[index][value];}
    if(value>=val[index]  and maxSum(index-1,value-val[index])!=INT_MAX and (wt[index]+maxSum(index-1,value-val[index]))<=w and maxSum(index-1,value)!=INT_MAX){
        dp[index][value]=min(wt[index]+maxSum(index-1,value-val[index]),maxSum(index-1,value));
    }
    else if (value>=val[index]  and maxSum(index-1,value-val[index])!=INT_MAX and (wt[index]+maxSum(index-1,value-val[index]))<=w){
        dp[index][value]=wt[index]+maxSum(index-1,value-val[index]);
    }
    else{
        dp[index][value]=maxSum(index-1,value);
    }
    return dp[index][value];
}

void solve()
{
    cin>>n>>w;
    wt.resize(n+1);val.resize(n+1);
    dp.resize(n+1,vector<int>(maxLimit+1,-1));
    for(int i=1;i<=n;i++){cin>>wt[i]>>val[i];}
    for(int i=1;i<=maxLimit;i++){dp[0][i]=INT_MAX;}
    for(int i=0;i<=n;i++){dp[i][0]=0;}
    int ans;
    for(int i=0;i<=maxLimit;i++){
        if(maxSum(n,i)!=INT_MAX){
            ans=i;
        }
    }
    cout<<ans;


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
