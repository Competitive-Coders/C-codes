 #include<iostream>
 using namespace std;

 int main()
 {
     int n;cin>>n;

     if(n%2&&n>=5)
     {
         for(int i=0;i<(n-1)/2;i++)
         {
             cout<<"*";
             for(int j=0;j<(n-3)/2;j++)
                cout<<" ";
             if(i==0)
             {
                 for(int j=0;j<(n+1)/2;j++)
                    cout<<"*";
             }
             else
                cout<<"*";
             cout<<"\n";
         }

         for(int i=0;i<n;i++)
            cout<<"*";
            cout<<"\n";

            for(int i=0;i<(n-1)/2;i++){
         for(int j=0;j<n-1;j++)
         {
             if(j==(n-1)/2)
                cout<<"*";
             else
             if(i==(n-3)/2&&j<(n-1)/2)
             {
                 cout<<"*";
             }
             else
                cout<<" ";
         }

         cout<<"*";
         cout<<"\n";
     }
     }
 }
