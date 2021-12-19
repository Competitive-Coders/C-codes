 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
     string s1,s2;cin>>s1>>s2;
     int n=s1.length();
     int m=s2.length();
     int T[n+1][m+1]={};

     for(int i=0;i<=n;i++)T[i][0]=i;
     for(int i=0;i<=m;i++)T[0][i]=i;

     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             if(s1[i]==s2[j])
             {
                 T[i][j]=T[i-1][j-1];
             }
             else
             {
                 T[i][j]=min(T[i-1][j-1],min(T[i-1][j],T[i][j-1]))+1;
             }
         }
     }
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=m;j++)
            cout<<T[i][j]<<" ";
         cout<<endl;
     }

     return 0;
 }
