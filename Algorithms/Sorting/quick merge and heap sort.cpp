 #include<iostream>
 using namespace std;

 void swap(int* a,int* b)
 {
     int temp=*a;
     *a=*b;
     *b=temp;
 }

 int partition(int *a,int l,int h)
 {
     int pivot=a[h];
     int i=l-1;
     for(int j=l;j<h;j++)
     {
         if(a[j]<=pivot)
         {
             i++;
             swap(a[i],a[j]);
         }
     }
     swap(a[i+1],a[h]);
     return i+1;
 }

 void quickSort(int *a,int l,int h)
 {
     if(l<h)
     {
         int j=partition(a,l,h);
         quickSort(a,l,j-1);
         quickSort(a,j+1,h);
     }
 }

 void merge(int *a,int l,int m,int h)
 {
     int n1=m-l+1;
     int n2=h-m;
     int L[n1],R[n2];

     for(int i=0;i<n1;i++)
        L[i]=a[l+i];
     for(int i=0;i<n2;i++)
        R[i]=a[m+i+1];

     int i=0,j=0,k=l;

     while(i<n1&&j<n2)
     {
         if(L[i]<=R[j])
         {
             a[k]=L[i];
             k++;
             i++;
         }
         else
         {
             a[k]=R[j];
             k++;
             j++;
         }
     }
     while(i<n1)
     {
         a[k]=L[i];
             k++;
             i++;
     }
     while(j<n2)
     {
         a[k]=R[j];
             k++;
             j++;
     }
 }

 void mergeSort(int *a,int l,int h)
 {
     if(l<h)
     {
         int m=(l+h)/2;
         mergeSort(a,l,m);
         mergeSort(a,m+1,h);
         merge(a,l,m,h);
     }
 }


 void heapSort(int *a)
 {
     //NOT DONE
 }
 int main()
 {
     int a[]={9,8,7,6,5,4,6,2,12};
     int b[]={9,8,7,6,5,4,6,2,12};
     int c[]={9,8,7,6,5,4,6,2,12};
     int n=sizeof(a)/sizeof(int);

     quickSort(a,0,n-1);
     mergeSort(b,0,n-1);
     heapSort(c);
     cout<<"\nUsing quick sort: ";
     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

     cout<<"\nUsing merge sort: ";
     for(int i=0;i<n;i++)
        cout<<b[i]<<" ";

     cout<<"\nUsing heap sort: ";
     for(int i=0;i<n;i++)
        cout<<c[i]<<" ";

     return 0;
 }
