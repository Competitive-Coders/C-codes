  #include<iostream>
 using namespace std;
 int gcd(int a,int b)
 {
     if(b==0)
        return a;
     return gcd(b,a%b);
 }
 int findgcd(int *a,int n)
 {
     int result=a[0];
     for(int i=1;i<n;i++)
     {
         if(result>a[i])
         {
             result=gcd(result,a[i]);
         }
         else
         {
             result=gcd(a[i],result);
         }
     }
     return result;
 }
 int main()
 {
     int t;
     cin>>t;
     while(t)
     {
         int n;cin>>n;
         int a[n];
         for(int i=0;i<n;i++)
            cin>>a[i];
         int x=findgcd(a,n);
         t--;
     }
     return 0;
 }
