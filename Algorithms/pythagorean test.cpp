  #include<iostream>
  #include<math.h>

  using namespace std;
  int main()
  {
      long long int N,m;cin>>N;
      int x;
      int r1=0,r2=0,r3=0;

     if(N>0){

      if(N%2==0)
      {
          m=N/2;
          x=0;
      }
      else
      {
          m=sqrt(N+1);
          x=1;
      }


      for(int i=1;i<m*m-1;i++)
      {
          if(i*i==m*m-1)
            r1=1;
            break;
      }

      for(int i=1;i<2*m;i++)
      {
          if(i*i==2*m)
            r2=1;
            break;
      }

      for(int i=1;i<m*m+1;i++)
      {
          if(i*i==m*m+1)
            r3=1;
            break;
      }

      if(r1&&r2&&r3&&x==1)
        cout<<"\n"<<2*m<<" "<<m*m+1;
      else
      if(r1&&r2&&r3&&x==0)
        cout<<"\n"<<m*m-1<<" "<<m*m+1;
      else
        cout<<"\n-1";
      }
  }
