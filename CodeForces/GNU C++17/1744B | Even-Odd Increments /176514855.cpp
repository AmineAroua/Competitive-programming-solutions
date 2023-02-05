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
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
//variables:
 
 
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vi v(n);
        ll odd = 0,even = 0;
        int no = 0,ne = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            no+=v[i]%2==1;
            ne+=v[i]%2==0;
            if(v[i]%2==0)
            {
                even+=v[i];
            }
            else
            {
                odd+=v[i];
            }
        }
        while(q--)
        {
            int p;
            cin>>p;
            int a;
            cin>>a;
            if(p==0)
            {
                cout<<odd+even+a*ne<<nl;
                if(a%2==0)
                {
                    even+=a*ne;
                }
                else
                {
                    odd+=a*ne+even;
                    even = 0;
                    ne = 0;
                    no = n;
                }
            }
            else
            {
                cout<<even+odd+a*no<<nl;
                if(a%2==0)
                {
                    odd+=a*no;
                }
                else
                {
                    even+=a*no+odd;
                    odd = 0;
                    no = 0;
                    ne = n;
                }
            }
        }
    }
}
 
 
 
 
/*
 
1/2 half of the contest:
 Read the subject in ~2 min
 Reformulate the topic
 solve examples
 Think of the solution 3 min
 Implement the solution for 20 min
 Pseudo-code your algorithm
 Verify your solution
 Code your solution
 Test your solution
 Debug your code
2/2 half of the contest:
 find the easiest subtasks and try to solve them or give up
 if there are many subtasks, the problem is easy
 if the first subtask is difficult with no much points, the problem is difficult
----------------------------
!(: remember, you are the king of competitive programming
*/
 
 