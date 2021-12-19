 #include<bits/stdc++.h>
 #define rep(i,n) for(int i=0;i<n;i++)
 #define rep2(i,j,n) rep(i,n) rep(j,n)
 #define mod 1000000007
 #define pb push_back
 #define ff first
 #define ss second
 #define ii pair<int,int>
 #define vi vector<int>
 #define vii vector<ii>
 #define ll long long
 #define lli long long int
 #define N 50
 using namespace std;

 void mul(int A[][N],int B[][N],int n)
 {
     int C[n][n]={};
     rep2(i,j,n) rep(k,n) C[i][j]+=A[i][k]*B[k][j];
     rep2(i,j,n)A[i][j]=C[i][j];
 }

 void power(int A[][N],int n,int m)
 {
     int I[N][N]={};
     rep2(i,j,n)if(i==j)I[i][j]=1;

     /* NAIVE
     rep(i,m)
     {
         mul(I,A,n);
     }
     */

     while(m)
     {
         if(m%2)mul(I,A,n),m--;
         else mul(A,A,n),m/=2;
     }
     rep2(i,j,n)A[i][j]=I[i][j];
 }

 //calculate mth power of a matrix of NxN dimension: Brute force O( (N^3)*(m) )
 //Binary expo: O( (N^3)*log(m) )
 int main()
 {
     int n,m;
     cout<<"\nDimension:";cin>>n;
     cout<<"\nPower:";cin>>m;
     cout<<"\nEnter matrix:\n";

     int A[N][N];
     rep2(i,j,n)cin>>A[i][j];

     cout<<"\nMatrix Entered:\n";
     rep(i,n)
     {
         rep(j,n)cout<<setw(5)<<A[i][j];
         cout<<endl;
     }

     power(A,n,m);
     cout<<m<<" th power is:\n";
     rep(i,n)
     {
         rep(j,n)cout<<setw(5)<<A[i][j];
         cout<<endl;
     }

     return 0;
 }
