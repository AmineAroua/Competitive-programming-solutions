#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define nl '\n'
#define boost ios::sync_with_stdio(false)
//variables:
 
//functions:
int value(char c)
{
    if(c=='B')
        return 1;
    else
        return 0;
}
int main()
{
    boost;
    int t;cin>>t;
    while(t--)
    {
        int n,k,sum=0;cin>>n>>k;
        string s;cin>>s;
        for(int i=0;i<k;i++)
            if(s[i]=='B')
                sum+=1;
        int maxsum=sum;
        for(int i=k;i<n;i++)
        {
            sum+=value(s[i]);
            sum-=value(s[i-k]);
            maxsum=max(sum,maxsum);
        }
        cout<<k-maxsum<<nl;
    }
}
 
 
 
 
/*
Test 1
INPUT:                              |OUTPUT:
                                    |
                                    |
                                    |
                                    |
                                    |
                                    |
        |
Test 2                              |
INPUT:                              |OUTPUT:
                                    |
                                    |
                                    |
                                    |
                                    |
        |
        |
        |
        |
----------------------------------------------------------------------------------------
 
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
 
 