#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[2][n];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        vector<vector<pair<int, int>>> pos(2 * n + 2);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                pos[a[i][j]].push_back({i,j});
            }
        }
        
        set<int>indx0,indx1;  // Unselected ones in the range [l,r]
        indx0.insert(n+1);
        indx1.insert(-1);
        for(int i=0;i<n;i++)
        {
            indx0.insert(i);
            indx1.insert(i);
        }

        auto check = [&]() {
            
            if(indx0.count(0) || indx1.count(n-1)) return false;
            if(*indx0.begin() -1 <= *indx1.rbegin()) return false;
            return true;
        };
        // lambda function : & means capture by reference , modifying the original sets indx0,indx1. [] means capture nothing. 
        auto remove = [&](int r){
            
            for(auto p:pos[r])
            {
                if(p.first==0) indx0.erase(p.second);
                else indx1.erase(p.second);
            }
        };
        auto add = [&](int l){
            
            for(auto p:pos[l])
            {
                if(p.first==0) indx0.insert(p.second);
                else indx1.insert(p.second);
            }
        };

        long long ans=0,r=0;
        //Finding tight ranges [l,r] such that all elements can be selected 
        for(int l=1;l<=2*n;l++)
        {
            // r(l) <= r(l+1) 
            while(r<=(2*n) && !check())
            {
                // remove position of element which are in range [l,r] from indx.
                r++;
                remove(r);
            }
            
            if(!check()) break;
            ans += (2*n - r + 1);

            // adding the position of element l to the set indx0,indx1 as l is now out of the range [l+1,r]
            add(l);
        }
        cout<<ans<<endl;
    }
}