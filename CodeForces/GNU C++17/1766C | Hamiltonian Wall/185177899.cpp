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
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        string s,t ;
        cin>>s>>t;
        for(int i = 0;!s.empty()&&i<s.size()-1;i++)
        {
            if(s[i]=='B'&&s[i+1]=='B'&&t[i]=='B'&&t[i+1]=='B')
            {
                s.erase(i+s.begin(),i+2+s.begin());
                t.erase(i+t.begin(),i+2+t.begin());
                i--;
            }
        }
        bool acc =1;
        for(int i = 0;!s.empty()&&i<s.size()-1;i++)
        {
            if(s[i]==t[i+1]&&s[i]=='B'&&s[i+1]==t[i]&&t[i]=='W')
            {
                acc = 0;
                break;
            }
            if(t[i]==s[i+1]&&t[i]=='B'&&t[i+1]==s[i]&&s[i]=='W')
            {
                acc = 0;
                break;
            }
        }
        for(int i = 1;!s.empty()&&i<s.size()-1;i++)
        {
            if(s[i]=='B'&&s[i+1]=='W'&&s[i-1]=='W'&&t[i]=='B')
            {
                acc = 0;
                break;
            }
            if(t[i]=='B'&&t[i+1]=='W'&&t[i-1]=='W'&&s[i]=='B')
            {
                acc = 0;
                break;
            }
        }
        if(acc)
        {
            cout<<"YES"<<nl;
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }
}
 
 