 #include<bits/stdc++.h>
 using namespace std;
 int fun(int* a,int n)
 {
     int m_c=a[0],m_g=a[0];
     int b=0,e=0,b_g=0,e_g=0;
     for(int i=1;i<n;i++)
     {
         if(m_c+a[i]>m_c)
         {
             m_c=m_c+a[i];
             e=i;
         }
         else
         {
             m_c=a[i];
             b=i;e=i;
         }

         if(m_c>m_g)
         {
             m_g=m_c;
             b_g=b;
             e_g=e;
         }
     }

     for(int i=b_g;i<=e_g;i++)
        cout<<a[i];
     return m_g;
 }
 int main()
 {
     int a[]={-2,3,2,-1};
     int n=sizeof(a)/sizeof(int);
     cout<<fun(a,n);
     return 0;
 }
