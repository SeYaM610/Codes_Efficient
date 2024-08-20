#include <bits/stdc++.h>
using namespace std;

///1<= T <=10^5
///1<= N <=10^5

const int M= 1e9+7;

int main()
{
      int T;
      cin>>T;
      while(T--)
      {
          int N;
          cin>>N;
          long long fact=1;
          for(int i=2;i<=N;i++){
            fact=(fact*i) % M;
          }
          cout<<fact<<endl;
      }
}
/// O(T*N) = O(10^10)

const int M= 1e9+7;
const int N= 1e5+10;
long long fact[N];
int main()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++) fact[i]=(fact[i-1]*i) % M;
    int T;
      cin>>T;
      while(T--)
      {
          int n;
          cin>>n;
          cout<<fact[n]<<endl;
      }
}
/// O(N) + O(T) = O(10^5)
