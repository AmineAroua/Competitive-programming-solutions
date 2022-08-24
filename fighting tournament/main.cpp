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
    boost;
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        int pre = 0;
        cin>>n>>q;
        deque<int> dq;
        vi v(n);
        vi pref(n+1,n+1);
        vi vic(n+1,0);
        int MAX = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            dq.pb(v[i]);
            MAX = max(MAX,v[i]);
        }
        if(dq.front()==MAX)
        {
            pre++;
        }
        while(dq.front()!=MAX)
        {
            pre++;
            int small = min(dq[0],dq[1]);
            if(small == dq[0])
            {
                vic[dq[1]]++;
                pref[dq[1]]=min(pre-1,pref[dq[1]]);
                dq.pop_front();
                dq.pb(small);
            }
            else
            {
                vic[dq[0]]++;
                pref[dq[0]]=min(pre-1,pref[dq[0]]);
                int targ = dq[0];
                dq.pop_front();
                dq.pop_front();
                dq.pb(small);
                dq.push_front(targ);
            }
        }
        pre--;
        while(q--)
        {
            int i;
            int k;
            cin>>i>>k;
            if(v[i-1]!=MAX)
            {
                if(k>pref[v[i-1]])
                {
                    cout<<min(k-pref[v[i-1]],vic[v[i-1]]);
                }
                else
                {
                    cout<<0;
                }
                cout<<nl;
            }
            else
            {

                cout<<max(k-pre,0)<<nl;

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


