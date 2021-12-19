#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<endl;
if(n%2){

for(int i=0;i<n;i++)
    cout<<"* ";
    cout<<endl;
    for(int i=0;i<(n-1)/2;i++)
    {
         for(int j=(n-3)/2-i;j>=0;j--)
            cout<<"* ";
         for(int j=0;j<=4*i;j++)
            cout<<" ";
            cout<<" ";
         for(int j=(n-3)/2-i;j>=0;j--)
            cout<<"* ";
        cout<<"\n";
    }

        for(int i=(n-5)/2;i>=0;i--)
    {
         for(int j=(n-3)/2-i;j>=0;j--)
            cout<<"* ";
         for(int j=0;j<=4*i;j++)
            cout<<" ";
            cout<<" ";
         for(int j=(n-3)/2-i;j>=0;j--)
            cout<<"* ";
        cout<<"\n";
    }
for(int i=0;i<n;i++)
cout<<"* ";
cout<<endl;
}
}
