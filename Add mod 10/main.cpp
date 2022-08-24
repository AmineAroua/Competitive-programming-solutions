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

const ll MOD = 1e9 + 7;

//variables:


//functions:


ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)

int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl v(n);
        bool div5 = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]%5==0)
            {
                div5=1;
                v[i]+=v[i]%10;
            }
        }
        if(div5)
        {
            bool acc =true;
            for(int i=0;i<n-1;i++)
            {
                if(v[i]!=v[i+1])
                {
                    cout<<"NO"<<nl;
                    acc =false;
                    break;
                }
            }
            if(acc)
            {
                cout<<"YES"<<nl;
            }
            continue;
        }
        int a1=0,a2=0;
        for(int i=0;i<n;i++)
        {
            while(v[i]%10!=2)
            {
                v[i]+=v[i]%10;
            }
            a1+=v[i]%20==2;
            a2+=v[i]%20==12;
        }
        if(a1!=0&&a2!=0)
        {
            cout<<"NO"<<nl;
            continue;
        }
        cout<<"YES"<<nl;
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


