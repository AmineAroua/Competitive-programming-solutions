#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n;
    cin>>n;
    int tab[n];
    int occ[n+1]={0};
    
    for (int i = 0 ; i<n ; i++)
    {
       cin>>tab[i];
       occ[tab[i]]++;
    }
    
    bool check = true;
    for (int i = 1 ; i<=n ; i++)
    {
        if (occ[i]>=2)
        {
            check = false ;
        }
    }
    
    if (check)
        cout<<"Yes";
    else
        cout<<"No";
}
