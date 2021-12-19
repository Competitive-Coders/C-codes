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
 #define PI 3.141593
 #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 using namespace std;

 class matrix
 {
 public:
    ll len;
    ld** cosine;
     matrix(ll len)
     {
         this->len=len;
         cosine=new ld*[len];
         rep(i,len)cosine[i]=new ld[len];
     }

    void set_cosine_matrix()
    {
        rep2(i,j,len)
        {
            if(i==0)
            {
                cosine[i][j]=sqrt((ld)1/(ld)len);
            }
            else
            {
                ld multiplier=sqrt((ld)2/(ld)len);
                ld angle= ( (ld)((2*j)+1))*PI;
                angle*=(ld)i;
                angle/=(ld)(2*len);
                cosine[i][j]=multiplier*cos(angle);
            }
        }
    }

    void print_cosine_matrix()
    {
        cout<<"\nCosine matrix:\n";
        rep(i,len)
        {
            rep(j,len)cout<<setw(15)<<setprecision(4)<<cosine[i][j];
            cout<<"\n";
        }
    }

    void get_transform_1D(ld *a)
    {
        ld mat[len]={};
        rep(i,len)
        {
            ld temp=0;
            rep(j,len)
            {
                temp+=cosine[i][j]*((ld)a[j]);
            }
            mat[i]=temp;
        }

        cout<<"\n\nOutput:\n";
        rep(i,len)cout<<mat[i]<<" ";
    }

    void get_transform_2D(ld** a)
    {
        ld mat[len][len]={};
        rep(i,len)
        {
            rep(j,len)
            {
                rep(k,len)
                {
                    mat[i][j]+=cosine[i][k]*((ld)a[k][j]);
                }
            }
        }

        rep2(i,j,len)a[i][j]=0;

        rep(i,len)
        {
            rep(j,len)
            {
                rep(k,len)
                {
                    a[i][j]+=mat[i][k]*cosine[j][k];
                }
            }
        }

        cout<<"\n\nOutput:\n";
        rep(i,len)
        {
            rep(j,len)cout<<setw(15)<<setprecision(4)<<a[i][j];
            cout<<"\n";
        }
    }
 };
 void fun()
 {
     cout<<"\nEnter Image dimension(1/2):";
     ll dim;cin>>dim;
     cout<<"\nEnter the size of the image (length):";
     ll len;cin>>len;
     matrix C(len);
     C.set_cosine_matrix();
     C.print_cosine_matrix();

     if(dim==1)
     {
         cout<<"\nEnter 1D image:\n";
         ld* img;
         img=new ld[len];
         rep(i,len)cin>>img[i];
         C.get_transform_1D(img);
     }
     else
     {
         cout<<"\nEnter 2D image:\n";
         ld** img;
         img=new ld*[len];
         rep(i,len)img[i]=new ld[len];

         rep2(i,j,len)cin>>img[i][j];
         C.get_transform_2D(img);
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
