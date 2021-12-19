  #include<bits/stdc++.h>
  #define max 100000
  using namespace std;

  void factorize(int n)//O(n)
  {
      for(int i=2;i<=n;i++)
      {
          if(n%i==0)
          {
              int c=0;
              while(n%i==0)
              {
                  c++;n/=i;
              }
              cout<<i<<"^"<<c<<endl;
          }
      }
  }

  void optimize(int n)//O(sqrt(n))
  {
      for(int i=2;i*i<=n;i++)//a number has a prime factor below sqrt(n)
      {
          if(n%i==0)
          {
              int c=0;
              while(n%i==0)
              {
                  c++;n/=i;
              }
              cout<<i<<"^"<<c<<endl;
          }
      }
      if(n>1)cout<<n<<"^"<<1<<endl;
  }
  int main()
  {
      int n;cin>>n;
      //factorize(n);
      optimize(n);
      return 0;
  }
