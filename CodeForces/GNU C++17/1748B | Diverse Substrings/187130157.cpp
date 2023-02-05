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
ll ans = 0;
void substrings(string str)
{
 
    for (int i = 0; i < str.size(); i++) {
        string subStr="";
        vi occ(10 , 0);
        set<char> st;
        for (int j = i; j < min(i+100,(int)str.size()); j++) {
            subStr += str[j];
            occ[str[j]-48]++;
            st.insert(str[j]);
            int d = st.size();
            bool acc = 1;
            for(auto x:occ)
            {
                if(x>d)
                {
                    acc = 0;
                    break;
                }
            }
            if(acc)ans++;
        }
    }
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
        ans = 0;
        int n;
        cin>>n;
        string s;
        cin>>s;
        substrings(s);
        cout<<ans<<nl;
    }
}
 
 