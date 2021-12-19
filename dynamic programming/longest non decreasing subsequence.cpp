 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
     int n;cin>>n;
     int a[n];
     for(int i=0;i<n;i++)cin>>a[i];
     int T[n];
     for(int i=0;i<n;i++)
        T[i]=1;
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<i;j++)
         {
             if(a[i]>=a[j]&&T[j]+1>T[i])
             T[i]=T[j]+1;
         }
     }
     for(int i=0;i<n;i++)
     cout<<T[i]<<" ";
     return 0;
 }
