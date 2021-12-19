 #include<iostream>
 #include<algorithm>
 int f(int a,int b)
 {
     if(b==0)
        return 1;
     if(b%2)
     {
         return a*f(a,b/2)*f(a,b/2);
     }
     else
        return f(a,b/2)*f(a,b/2);
 }
 using namespace std;
 int main()
 {
     int a,b;cin>>a>>b;
     cout<<f(a,b);
 }
