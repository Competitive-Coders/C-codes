 #include<iostream>
 using namespace std;
 int main()
 {
     //assuming (0<=arr[]<100) and hashing
     int n;cin>>n;
     int count_frequency[100]={};
     int a[n];
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
         count_frequency[a[i]]++;
     }
     for(int i=0;i<100;i++)
     {
         for(int j=0;j<count_frequency[i];j++)
         {
             cout<<i<<" ";
         }
     }
     return 0;
 }

