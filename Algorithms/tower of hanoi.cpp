 #include<bits/stdc++.h>

 using namespace std;
 void hanoi(int n,char source,char helper,char destination)
 {
     if(n==0)return;
     hanoi(n-1,source,destination,helper);
     cout<<"\nMove "<<n<<" disk from "<<source<<" to "<<destination;
     hanoi(n-1,helper,source,destination);
 }
 int main()
 {
     int n;cin>>n;
     hanoi(n,'A','B','C');
     return 0;
 }
