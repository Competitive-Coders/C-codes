 #include<iostream>
 using namespace std;

 int product(int a,int b)
 {
     int p=0;
         if(b==0)
            return 0;
         p=a+product(a,b-1);
         return (p);
 }
 int main()
 {
     int a,b;
     cin>>a>>b;
     int x;
     if(a>0&&b>0)
        {
            x=product(a,b);
            cout<<x;
        }
     if(a>0&&b<0)
     {
         x=product(a,-b);
         cout<<(-x);
     }
      if(a<0&&b<0)
     {
         x=product(-a,-b);
         cout<<x;
     }
      if(a<0&&b>0)
     {
         x=product(-a,b);
         cout<<(-x);
     }
 }
