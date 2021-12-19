  #include<bits/stdc++.h>
  #define max 100000
  using namespace std;
  int flag[max+1]={};

  void sieve()
  {
      memset(flag,-1,sizeof(flag));//to assume everyone is prime

      for(int i=2;i<=max;i++)
      {
          if(flag[i]==-1)// if no is prime
          {
              for(int j=i;j<=max;j+=i)// go to it's multiples
              {
                  if(flag[j]==-1)
                  flag[j]=i;//store the lowest prime factor
              }
          }
      }
  }

  factorize(int n)
  {
      //cout<<flag[n];
      int p=flag[n];
      int c=1;
      n/=flag[n];
      do
      {
          if(flag[n]==p)
          {
              c++;
          }
          else
          {
              cout<<p<<"^"<<c<<endl;
              c=1;
          }
          if(flag[n]==-1)break;
          p=flag[n];
          n/=flag[n];

      }while(n!=1);

      if(n>1)cout<<n<<"^"<<1<<endl;

  }
  int main()
  {
      int n;cin>>n;
      sieve();
      factorize(n);
      return 0;
  }
