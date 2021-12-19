 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
     int l;cin>>l;
     int profit[]={0,2,5,9,6};
     int n=4;
     int T[n+1][l+1]={};

     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=l;j++)
         {

             if(j<i)
             {
                 T[i][j]=T[i-1][j];
             }
             else
             {
                 T[i][j]=max(profit[i]+T[i][j-i],T[i-1][j]);
             }
         }
     }

     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=l;j++)
            cout<<T[i][j]<<" ";
         cout<<endl;
     }

     return 0;
 }
