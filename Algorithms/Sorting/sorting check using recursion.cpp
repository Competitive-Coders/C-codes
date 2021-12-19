 #include<iostream>
 using namespace std;
 sort(int *a,int n)
 {
     if(n==1)
        return (true);
     if(a[0]<a[1]&&sort(a+1,n-1))
     return (true);
     return (false);

 }
 int main()
 {
    int n;cin>>n;
    bool x;
    int a[20];4
    for(int i=0;i<n;i++)
        cin>>a[i];
    x=sort(a,n);

    cout<<x;
 }
