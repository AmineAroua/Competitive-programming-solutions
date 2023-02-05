#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define boost ios::sync_with_stdio(false)
bool allZero(int n,ll a[])
{
    for(int i=0;i<n;i++){
        if(a[i]!=0)
            return false;
    }
    return true;
}
bool verifydiff(int k,ll diff[])
{
    for(int i=0;i<=k-2;i++)
    {
        if(diff[i]!=diff[i+1])
            return false;
    }
    return true;
}
bool verifydzero(int k,int h,ll diff[],ll dzero[])
{
    if(!verifydiff(k,diff))
        return false;
    else
    {
        for(int i=0;i<h;i++)
        {
            if(dzero[i]>diff[0])
                return false;
        }
        return true;
    }
}
int main()
{
    boost;
    int t;cin>>t;
    while(t--)
    {
        int n,h=0,k=0;
        cin>>n;
        bool access=true;
        ll a[n],b[n],diff[n],dzero[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        if(n==1)
        {if(a[0]>=b[0])
        {
            cout<<"YES"<<'\n';
            access=false;
        }
        else{
            cout<<"NO"<<'\n';
            access=false;
        }}
        if(access)
        {for(int i=0;i<n;i++)
        {
            if(b[i]>a[i])
            {
                cout<<"NO"<<'\n';
                access=false;
                break;
            }
            if(b[i]==0)
            {
                dzero[h]=a[i];h++;
            }
            else{
                diff[k]=a[i]-b[i];k++;
            }
        }}
        if(allZero(n,b)&&access)
        {
            cout<<"YES"<<endl;
            access=false;
        }
        if(access)
        {
            if(verifydzero(k,h,diff,dzero))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
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