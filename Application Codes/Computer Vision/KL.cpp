 #include<bits/stdc++.h>
 #define mod 1000000007
 #define small INT_MIN
 #define large INT_MAX
 #define inl long long
 #define ll long long
 #define ld long double
 #define lli long long int
 #define rep(i,n) for(ll i=0;i<n;i++)
 #define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
 #define rep2(i,j,n) rep(i,n) rep(j,n)
 #define pb push_back
 #define mp make_pair
 #define ff first
 #define ss second
 #define pii pair<int,int>
 #define pll pair<ll,ll>
 #define vi vector<int>
 #define vl vector<ll>
 #define vpi vector<pii>
 #define vpl vector<pll>
 #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 using namespace std;

 class matrix
 {
 public:
    ll dim=2;
    ld M[2][2];
    void find_covar_matrix(pll px,ld col,ld row)
    {
        ld c=(ld)px.ff-col;
        ld r=(ld)px.ss-row;

        M[0][0]=c*c;
        M[0][1]=c*r;
        M[1][0]=r*c;
        M[1][1]=r*r;
    }

    void print_covar_matrix()
    {
        rep(i,dim)
        {
            rep(j,dim)cout<<setw(10)<<setprecision(4)<<M[i][j];
            cout<<endl;
        }
    }
 };
 void fun()
 {
     cout<<"\nDimensions:";
     ll n;cin>>n;
     ll img[n][n];
     ll sum_row=0,sum_col=0;
     ld avg_row,avg_col;

     cout<<"\nEnter Image:\n";
     vector<pll> v;
     rep2(i,j,n)
     {
         cin>>img[i][j];
         if(img[i][j]!=0)
         {
             v.pb({j,n-i-1});
             sum_row+=n-i-1;
             sum_col+=j;
         }
     }

     avg_row=(ld)sum_row/(ld)n;
     avg_col=(ld)sum_col/(ld)n;

     cout<<"\nAverage matrix: { "<<avg_col<<" , "<<avg_row<<" }\n";

     ll total_on_pixels=v.size();
     cout<<total_on_pixels;
     cout<<"\nDark Pixels:\n";
     rep(i,total_on_pixels)cout<<"("<<v[i].ff<<","<<v[i].ss<<") ";

     matrix* arr[total_on_pixels*10];

     ld covar_matrix[2][2]={};
     rep(i,total_on_pixels)
     {
         matrix m;
         arr[i]=&m;
         (*arr[i]).find_covar_matrix(v[i],avg_col,avg_row);
         cout<<"\nCovar matrix "<<i<<":\n";
         (*arr[i]).print_covar_matrix();
         fflush(stdin);
         rep2(j,k,2)
         {
             covar_matrix[i][j]=covar_matrix[i][j]+(abs)((*arr[i]).M[i][j]);
         }
     }

     rep2(i,j,2)covar_matrix[i][j]/=(ld)n;

     cout<<"\nFinal Covariance Matrix:\n";

    rep(i,2)
    {
        rep(j,2)cout<<setw(10)<<setprecision(4)<<covar_matrix[i][j];
        cout<<endl;
    }
 }

 int main()
 {
     ll t;cin>>t;
     while(t--)
     {
         fun();cout<<endl;
     }
     return 0;
 }
