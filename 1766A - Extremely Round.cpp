#include <bits/stdc++.h>
using namespace std;

//const int m=1000001;     // In case of global array, size has to be Const Variable
int a[1000001];
int psum[1000001];

int func(int x)
{
    int count=0;
    while(x){
        if(x%10 != 0) count++;
                x/=10;
                if(count>1) break;
    }
    if(count>1) return 0;
    else return 1;
}

int main()
{
  /*  int a[1000001];    " We cant take array of size (around 10^6) locally. So we've to take it globally. "
    int psum[1000001];
    */
    psum[0]=0;
    a[0]=0;
    for(int i=1;i<1000001;i++){
        a[i]=func(i);
        psum[i]=psum[i-1]+a[i];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<psum[n]<<endl;
    }
}
