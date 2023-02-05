#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int tab[]={a,b,c,d};
        sort(tab,tab+4);
        for(int i=0;i<4;i++){
            if(tab[i]==a){
                cout<<3-i<<endl;
            }
        }
    }
}