  #include<bits/stdc++.h>
  using namespace std;
  //O(sqrt(n))
  void primality_test(int n)
  {
      if(n==1)cout<<"Not Prime";

      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0)
          {
              cout<<"Not prime";
              return;
          }
      }
      cout<<"Prime";
  }
  int main()
  {
      int n;cin>>n;
      primality_test(n);
      return 0;
  }
