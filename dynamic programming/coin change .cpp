 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
     int tot;cin>>tot;
     int n;cin>>n;
     int a[n];
     for(int i=0;i<n;i++)cin>>a[i];

     int T[n][tot+1]={};
     for(int i=0;i<=tot;i++)T[0][i]=i;

     for(int i=1;i<n;i++)
     {
         for(int j=1;j<=tot;j++)
         {
             if(a[i]>j)
             T[i][j]=T[i-1][j];
             else
             {
                 T[i][j]=min(T[i-1][j],1+T[i][j-a[i]]);
             }
         }
     }
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<=tot;j++)
            cout<<T[i][j]<<" ";
         cout<<endl;
     }
     return 0;
 }
