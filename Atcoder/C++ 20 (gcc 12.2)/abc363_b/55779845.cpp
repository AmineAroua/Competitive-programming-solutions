#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n , k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin() , s.end());
    int ans = 0;
    do
    {
        int add = 1;
        for(int i = 0 ; i + k - 1 < n; i++)
        {
            int ok = 1;
            for(int j = i ; j <= i + k - 1 ; j++)
                ok&=(s[j] == s[i + k - 1 - (j - i)]);
            if(ok == 1)
            {
                add = 0;
                break;
            }
        }
        ans+=add;
    }
    while(next_permutation(s.begin() , s.end()));
    cout<<ans<<'\n';
}
