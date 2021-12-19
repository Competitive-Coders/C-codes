 #include<iostream>
 using namespace std;
 void insertion_sort(int* a,int n)
 {
     for(int i=1;i<n;i++)
     {
         int j=i-1;
         int save=a[i];
         while(j>=0&&a[j]>save)
         {
             a[j+1]=a[j];
             j--;
         }
         a[j+1]=save;
         for(int l=0;l<n;l++)
         {
             cout<<a[l]<<" ";
         }
         cout<<endl;
     }
 }
 int main()
 {
     int n;cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
        cin>>a[i];
     insertion_sort(a,n);
     return 0;
 }
