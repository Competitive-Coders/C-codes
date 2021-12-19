 #include<iostream>
 using namespace std;
 void swap(int *a,int j)
 {
     int temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
 }
 void bubble(int *a,int n)
 {
     for(int i=0;i<n-1;i++)
     {
         int chk=0;
         for(int j=0;j<n-i-1;j++)
         {
             if(a[j]>a[j+1])
             {
                 swap(a,j);
                 chk=1;
             }
         }
         if(chk==0)
            break;
     }
 }

 void selection(int *a,int n)
 {
     for(int i=0;i<n-1;i++)
     {
         int m=i;
         for(int j=i+1;j<n;j++)
         {
             if(a[j]<a[m])
                m=j;
         }
         int temp=a[i];
         a[i]=a[m];
         a[m]=temp;
     }
 }

 void insertion(int *a,int n)
 {
     for(int i=1;i<n;i++)
     {
         int j=i-1;
         int x=a[i];
         while(j>=0&&a[j]>x)
         {
             a[j+1]=a[j];
             j--;
         }
         a[j+1]=x;
     }
 }

 void counting(int *a,int n)
 {
     int f[10]={};
     for(int i=0;i<n;i++)
     {
         f[a[i]]++;
     }
     for(int i=1;i<10;i++)
     {
         f[i]+=f[i-1];
     }
     int out[n];
     for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
     for(int i=0;i<n;i++)
     {
         out[f[i]]=i;
     }
     for(int i=0;i<n;i++)
        cout<<out[i]<<" ";

 }
 int main()
 {
     int n;cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
        cin>>a[i];
        counting(a,n);
     /*for(int i=0;i<n;i++)
        cout<<a[i]<<" ";*/
 }
