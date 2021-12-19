 #include<bits/stdc++.h>
 using namespace std;
 int T[10][10]={};
 int fun(string s,int l,int u)
 {
     if(T[l][u])
        return T[l][u];
     if(s[l]==s[u])
     {
         T[l][u]=2+fun(s,l+1,u-1);
         return (2+fun(s,l+1,u-1));
     }
     else
     {
         T[l][u]=max(fun(s,l,u-1),fun(s,l+1,u));
         return (max(fun(s,l,u-1),fun(s,l+1,u)));
     }
 }
 int main()
 {
     string s;cin>>s;
     int n=s.length();
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(i==j)T[i][j]=1;
         }
     }
     cout<<fun(s,0,n-1)<<endl;

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             cout<<T[i][j]<<" ";
         }
         cout<<endl;
     }
     return 0;
 }
