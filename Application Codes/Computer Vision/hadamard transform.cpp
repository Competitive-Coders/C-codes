 #include<bits/stdc++.h>
 #define mod 1000000007
 #define small INT_MIN
 #define large INT_MAX
 #define inl long long
 #define ll int
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
    ll len;
    ll** hadamard;
     matrix(ll len)
     {
         this->len=len;
         hadamard=new ll*[len];
         rep(i,len)hadamard[i]=new ll[len];
     }
    void set_hadamard_matrix()
    {
        hadamard[0][0]=1;
        for(ll x=1;x<len;x+=x)
        {
            rep2(i,j,x)
            {
                hadamard[i+x][j]=hadamard[i][j];
                hadamard[i][j+x]=hadamard[i][j];
                hadamard[i+x][j+x]=-hadamard[i][j];
            }
        }
    }

    void print_hadamard_matrix()
    {
        cout<<"\nHadmard matrix:\n";
        rep(i,len)
        {
            rep(j,len)cout<<setw(5)<<hadamard[i][j];
            cout<<"\n";
        }
    }

    void get_transform_1D(ll *a)
    {
        ll mat[len]={};
        rep(i,len)
        {
            ll temp=0;
            rep(j,len)
            {
                temp+=a[j]*hadamard[i][j];
            }
            mat[i]=temp;
        }

        cout<<"\n\nOutput:\n";
        rep(i,len)cout<<mat[i]<<" ";
    }

    void get_transform_2D(ll** a)
    {
        ll mat[len][len]={};
        rep(i,len)
        {
            rep(j,len)
            {
                rep(k,len)
                {
                    mat[i][j]+=hadamard[i][k]*a[k][j];
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
                    a[i][j]+=mat[i][k]*hadamard[k][j];
                }
            }
        }

        cout<<"\n\nOutput:\n";
        rep(i,len)
        {
            rep(j,len)cout<<setw(5)<<a[i][j];
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
     matrix H(len);
     H.set_hadamard_matrix();
     //H.print_hadamard_matrix();

     if(dim==1)
     {
         cout<<"\nEnter 1D image:\n";
         ll* img;
         img=new ll[len];
         rep(i,len)cin>>img[i];
         H.get_transform_1D(img);
     }
     else
     {
         cout<<"\nEnter 2D image:\n";
         ll** img;
         img=new ll*[len];
         rep(i,len)img[i]=new ll[len];
         rep2(i,j,len)cin>>img[i][j];
         H.get_transform_2D(img);
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
