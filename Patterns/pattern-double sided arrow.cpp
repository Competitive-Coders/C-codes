  #include<iostream>
#include<math.h>
#include<algorithm>
 using namespace std;

 int main()
 {
     int n;cin>>n;

     if(n%2)
     {

         for(int i=0;i<(n+1)/2;i++)
         {
             for(int j=(n+1)/2-i;j>=0;j--)
                cout<<"    ";
             for(int k=0;k<=i;k++)
                cout<<i-k+1<<" ";
             for(int j=0;j<i;j++)
                cout<<"    ";
             cout<<"\b\b";
             for(int k=i+1;k>0;k--)
                cout<<i-k+2<<" ";

             cout<<endl;
         }

          for(int i=(n-3)/2;i>=0;i--)
         {
             for(int j=(n+1)/2-i;j>=0;j--)
                cout<<"    ";
             cout<<" ";
             for(int k=0;k<=i;k++)
                cout<<i-k+1<<" ";
             for(int j=0;j<i;j++)
                cout<<"    ";
             cout<<"\b\b";
             for(int k=i+1;k>0;k--)
                cout<<i-k+2<<" ";

             cout<<endl;
         }

     }
 }
