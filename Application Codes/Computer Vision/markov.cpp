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
 #define float_vec vector<float>
 #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 using namespace std;
 //to multiply two given matrix
    vector<float_vec > multiply(vector<float_vec > A, vector<float_vec > B, int N) {
       vector<float_vec > C(N, float_vec(N, 0));
       for (int i = 0; i < N; ++i)
          for (int j = 0; j < N; ++j)
             for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
       return C;
    }
    //to calculate power of matrix
    vector<float_vec > matrix_power(vector<float_vec > M, int p, int n) {
       vector<float_vec > A(n, float_vec(n, 0));
       for (int i = 0; i < n; ++i)
          A[i][i] = 1;
       while (p) {
          if (p % 2)
             A = multiply(A, M, n);
          M = multiply(M, M, n);
          p /= 2;
       }
       return A;
    }
    //to calculate probability of reaching from initial to final
    float calc_prob(vector<float_vec > M, int N, int F, int S, int T) {
       vector<float_vec > matrix_t = matrix_power(M, T, N);
       return matrix_t[F - 1][S - 1];
    }
 void fun()
 {
     cout<<"\nNumber of states:";
     ll N;cin>>N;
     vector<float_vec> G;
     cout<<"\nEnter "<<N<<"X"<<N<<" Grid:\n";
     rep(i,N)
     {
         vector<float> temp;
         rep(j,N)
         {
             float x;cin>>x;
             temp.pb(x);
         }
         G.pb(temp);
     }

     cout<<"\nStart State:";ll S;cin>>S;
     cout<<"\nFinal State:";ll F;cin>>F;
     cout<<"\nTime:";ll T;cin>>T;

     cout << "\nProbability of reaching: " << F << " in time " << T << " after starting from: " << S << " is " << calc_prob(G, N, F, S, T);
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
