#include<iostream>
using namespace std;
int fun(int a,int b)
{
    if(b==0)
    return(a);
    else
        return(fun(b,a%b));
}

int main()
{
    int a,b;
    cin>>a>>b;
    int x=fun(a,b);
    cout<<"\n"<<x;
}
