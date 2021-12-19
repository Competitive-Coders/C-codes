#include<iostream>
using namespace std;
int p[100000]={};
int fun(int *p,int n)
{
    p[2]=1;
    for(int i=3;i<n;i+=2)
        p[i]=1;
    for(int i=3;i<n;i+=2)
    {
        for(int j=i*i;j<n;j+=2*i)
            p[j]=0;
    }
    return(0);
}

int main()
{
    int n;cin>>n;
    fun(p,n);
    for(int i=0;i<n;i++)
    {
        if(p[i])
        cout<<i<<" ";
    }
}
