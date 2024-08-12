#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,round=0,count=0;
        cin>>n;
        for(int i=1;i<=n;i++){
                int j=i;
            while(j){
                if(j%10 != 0) count++;
                j/=10;
                if(count>1) break;
            }
            if(count==1) round++;
            count=0;
        }

        cout<<round<<endl;
    }
}
