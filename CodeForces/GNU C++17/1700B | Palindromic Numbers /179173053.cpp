#include<bits/stdc++.h>
using namespace std;
bool allNine(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='9')
        {
            return false;
        }
    }
    return true;
}
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
        if(s[0]=='9')
        {
            int res = 0;
            for(int i=n-1;i>=0;i--)
            {
                int x = s[i]-'0'+res;
                if(x>1)
                {
                    res = 1;
                    x = 11-x;
                    s[i] = x+'0';
                }
                else if(x==1)
                {
                    res = 0;
                    s[i] = '0';
                }
                else
                {
                    res = 0;
                    s[i] = '1';
                }
            }
            for(auto c:s)
                cout<<c;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cout<<9-(s[i]-'0');
            }
        }
        cout<<endl;
    }
}