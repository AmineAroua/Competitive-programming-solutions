#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int s;cin>>s;
        vector<int> v;
        for(int i=9;i>0;i--)
        {
            if(s>=i)
            {
                v.push_back(i);
                s-=i;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i];
        cout<<endl;
    }
}