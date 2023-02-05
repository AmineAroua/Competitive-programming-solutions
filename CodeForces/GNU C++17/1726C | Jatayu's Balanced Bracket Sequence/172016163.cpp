#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans= n;
        for(int i=0;i<n*2-1;i++)
        {
            if(s[i]==')'&&s[i+1]=='(')
            {
                ans--;
            }
        }
        cout<<ans<<endl;
    }
}