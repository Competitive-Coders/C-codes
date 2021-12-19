 #include<iostream>
 #include<string.h>
 #include<algorithm>
 using namespace std;

 int main()
 {
     int a[]={5,2,3,1,0,1,0,1,5,3,2,4,1,5,1};
     int n=sizeof(a)/sizeof(int);
     int u,l;
     if(n%2)//odd
     {
         u=a[0];
         l=a[0];
         for(int i=1;i<n;i+=2)
         {
             if(u<max(a[i],a[i+1]))
                u=max(a[i],a[i+1]);
             if(l>min(a[i],a[i+1]))
                l=min(a[i],a[i+1]);
         }
     }
     else
     {
         if(a[0]>=a[1])
         {
             u=a[0];
             l=a[1];
         }
         else
         {
             u=a[1];
             l=a[0];
         }
         for(int i=2;i<n;i+=2)
         {
             if(u<max(a[i],a[i+1]))
                u=max(a[i],a[i+1]);
             if(l>min(a[i],a[i+1]))
                l=min(a[i],a[i+1]);
         }
     }
     int f[u-l+1]={};
     for(int i=0;i<n;i++)
         f[a[i]-l]++;

     int cf[u-l+1]={};
     for(int i=1;i<n;i++)
         cf[i]=cf[i-1]+f[i-1];

     int sorted[n]={};
     for(int i=0;i<n;i++)
     {
         sorted[cf[a[i]-l]]=a[i];
         cf[a[i]-l]++;
     }
     for(int i=0;i<n;i++)
        cout<<sorted[i]<<" ";
 }
