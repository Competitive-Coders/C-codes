 #include<iostream>
 #include<vector>
 using namespace std;

 int main()
 {
     int n;cin>>n;
     int a[n];
     vector<int> left,right;
     cin>>a[0];
     int save=a[0];
     for(int i=1;i<n;i++)
     {
         cin>>a[i];
         if(a[i]<save)
            left.push_back(a[i]);
         else
            right.push_back(a[i]);
     }
     for(int i=0;i<left.size();i++)
        cout<<left[i]<<" ";
     cout<<save<<" ";
     for(int i=0;i<right.size();i++)
        cout<<right[i]<<" ";
     return 0;
 }
