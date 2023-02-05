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
 
double dist(double xi,double yi , double x,double y)
{
    double X = (xi-x)*(xi-x);
    double Y = (yi-y)*(yi-y);
    return sqrt(X+Y);
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    double xh,yh;
    double xu,yu;
    cin>>xh>>yh>>xu>>yu;
    int n;
    cin>>n;
    vector<double> v(3);
    vector<vector<double>> line(n,v);
    for(int i=0;i<n;i++)
    {
        cin>>line[i][0]>>line[i][1]>>line[i][2];
    }
    double a,b,c;
    if(xh==xu&&yh==yu)
    {
        cout<<0<<nl;
        return 0;
    }
    if(xh==xu)
    {
        b = 0;
        c= -xh;
        a = 1;
    }
    else if(yh==yu)
    {
        a = 0;
        b = 1;
        c = -yh;
    }
    else
    {
        b = -1;
        a = (yh-yu)/(xh-xu);
        c = yh-xh*a;
    }
    int ans = 0;
    for(auto l:line)
    {
        double A = l[0],B = l[1],C=l[2];
        double x,y;
        if(a!=0&&A!=0)
        {
            y = (c/a - C/A)/(B/A-b/a);
            x = (((-1)*c)-b*y)/a;
        }
        else if(a==0)
        {
            y = ((-1)*c)/b;
            x = (((-1)*C)-B*y)/A;
        }
        else
        {
            y = ((-1)*C)/B;
            x = (((-1)*c)-b*y)/a;
        }
        if((xu-xh)*(x-xh)>=0&&(yu-yh)*(y-yh)>=0)
        {
            if(dist(xh,yh,xu,yu)>dist(xh,yh,x,y))
            {
                ans++;
            }
        }
    }
    cout<<ans<<nl;
    return 0;
}
 
 