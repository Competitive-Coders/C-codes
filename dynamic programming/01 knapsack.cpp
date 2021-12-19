 #include<iostream>
 #include<math.h>
 #define ull long long int
 using namespace std;

 int main()
 {
     int wt;cin>>wt;
     int n;cin>>n;
     int v[n],w[n];
     for(int i=0;i<n;i++)cin>>v[i];
     for(int i=0;i<n;i++)cin>>w[i];

     int T[n][wt+1]={};
     for(int i=1;i<=wt;i++)
     {
         if(i>=w[0])T[0][i]=v[0];
     }

     for(int i=1;i<n;i++)
     {
         for(int j=1;j<=wt;j++)
         {
            if(j<w[i])
                T[i][j]=T[i-i][j];
            else
            {
                //cout<<"lo";
                T[i][j]=max((v[i]+T[i-1][j-w[i]]),(T[i-1][j]));
            }
         }
     }

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<=wt;j++)
            cout<<T[i][j]<<" ";
         cout<<endl;
     }
     return 0;
 }
