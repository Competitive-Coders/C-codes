 #include<iostream>
 #include<algorithm>
 using namespace std;
 void swap(int* a,int* b)
 {
     int temp=*a;
     *a=*b;
     *b=temp;
 }
 void bubble(int* a,int n)
 {
     if(n==1)
        return;
     int s=0;
     for(int i=0;i<n-1;i++)
     {
         if(a[i]>a[i+1])
         {
             swap(&a[i],&a[i+1]);
             s=1;
         }
     }
     if(s==0)
        return;
     else
        bubble(a,n-1);
 }
 int main()
 {
     int a[]={5,4,3,2,1,9};
     int n=sizeof(a)/sizeof(int);
     bubble(a,n);
     for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
     return 0;
 }
