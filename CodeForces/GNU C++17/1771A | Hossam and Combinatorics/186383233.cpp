#include<bits/stdc++.h>
using namespace std;
bool alleq(vector<long long> v)
{
    bool acc = 1;
    int lst= v[0];
    for(auto x:v)
    {
        if(x!=lst)acc = 0;
    }
    return acc;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long mn = 1e8 , mx = 0;
        vector<long long> v(n);
        for(int i = 0;i<n;i++){
            cin>>v[i];
            mx = max(v[i] , mx);
            mn = min(v[i] , mn);
        }
        sort(v.begin() , v.end());
        if(alleq(v))
        {
            cout<<(n*(n-1))<<endl;continue;
        }
        long long a= 0,b=0;
        for(int i = 0;i<n;i++)
        {
            if(v[i]==mn)a++;
            if(v[i]==mx)b++;
        }
        cout<<a*b*2<<endl;
    }
}