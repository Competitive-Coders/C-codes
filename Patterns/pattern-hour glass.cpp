 #include<iostream>
 using namespace std;

 int main()
 {
     int n;cin>>n;
     for(int i=0;i<n;i++)
     {
         for(int j=n;j>=n-i;j--)
            cout<<j<<" ";
         for(int j=(n-i-1)*4;j>=0;j--)
            cout<<" ";
        cout<<" ";
         for(int j=n-i;j<=n;j++)
            cout<<j<<" ";
         cout<<"\n";
     }

     for(int i=n;i>=0;i--)
        cout<<i<<" ";
     for(int i=1;i<=n;i++)
        cout<<i<<" ";
     cout<<"\n";
     for(int i=n-1;i>=0;i--)
     {
         for(int j=n;j>=n-i;j--)
            cout<<j<<" ";
         for(int j=(n-i-1)*4;j>=0;j--)
            cout<<" ";
            cout<<" ";
         for(int j=n-i;j<=n;j++)
            cout<<j<<" ";
         cout<<"\n";
     }
 }
