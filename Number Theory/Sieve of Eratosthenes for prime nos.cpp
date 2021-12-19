  #include<bits/stdc++.h>
  #define max 100000
  using namespace std;
    //O n(log(log(n)))

  int is_prime[100001]={};

  void sieve()
  {
      memset(is_prime,1,sizeof(is_prime));
      is_prime[0]=is_prime[1]=0;

      for(int i=2;i*i<=max;i++)
      {
          if(is_prime[i])
          {
              for(int j=i*i;j<=max;j+=i)
              {
                  is_prime[j]=0;
              }
          }
      }
  }
  int main()
  {
      int n;cin>>n;
      sieve();

      for(int i=0;i<=n;i++)
      {
          if(is_prime[i])cout<<i<<" ";
      }
      return 0;
  }
