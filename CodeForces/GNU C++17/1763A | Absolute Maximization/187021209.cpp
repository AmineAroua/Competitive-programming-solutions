#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define pb push_back
#define ll long long
#define ld long double
#define nl '\n'
#define boost ios::sync_with_stdio(false)
#define mp make_pair
#define se second
#define fi first
#define forr(i, x, y) for(ll i = x; i <= y; i++)
#define forn(i, x, y) for(ll i = x; i >= y; i--)
#define all(v) (v.begin(),v.end())
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
// HERE IS THE SOLUTION
int n;
vi v(513);
string bin(int x)
{
    string s = "";
    while(x)
    {
        s+=(char)(x%2+48);
        x/=2;
    }
    reverse(s.begin() , s.end());
    return s;
}
int toint(string s)
{
    int x = 0;
    reverse(s.begin() , s.end());
    for(int i = 0;i<s.size();i++)
    {
        x+=((int)pow(2,i))*(s[i]-48);
    }
    return x;
}
bool srch(int q)
{
    for(int i = 0;i<n;i++)
    {
        int x = v[i];
        string s = bin(x);
        reverse(s.begin() , s.end());
        for(int j = 0;j<s.size();j++)
        {
            if(s[q]=='1')
            {
                return 1;
            }
        }
    }
    return 0;
}
bool srchh(int q)
{
    for(int i = 0;i<n;i++)
    {
        int x = v[i];
        string s = bin(x);
        reverse(s.begin() , s.end());
        for(int j = 0;j<s.size();j++)
        {
            if(s[q]=='0')
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
 
        cin>>n;
        for(int i =0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin() , v.begin()+n);
        int mx = v[n-1];
        string s = bin(mx);
        for(int q=0;q<s.size();q++)
        {
            if(s[q]=='0')
            {
                if(srch(s.size()-q-1))
                    s[q] = '1';
            }
        }
        mx = toint(s);
        int mn = v[0];
        string ss = bin(mn);
        for(int q=0;q<ss.size();q++)
        {
            if(ss[q]=='1')
            {
                if(srchh(ss.size()-q-1))
                    ss[q] = '0';
            }
        }
        mn = toint(ss);
        cout<<mx-mn<<nl;
    }
}
 
 