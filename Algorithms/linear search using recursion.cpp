 #include<iostream>
 #include<string.h>
 using namespace std;

 int f(int *a,int n,int val,int i)
 {
     if(i==n)
        return(-1);
     else
     if(a[i]==val)
        return(i);
     else
     {
         i++;
         return f(a,n,val,i);
     }

 }
 int main()
 {
     int i=0;
     int a[]={5,6,34,7,8,9,12};
     int n=sizeof(a)/sizeof(int);
     int val;cin>>val;
     int x=f(a,n,val,i);
     if(x==-1)
        cout<<"absent";
     else
        cout<<x;
 }
