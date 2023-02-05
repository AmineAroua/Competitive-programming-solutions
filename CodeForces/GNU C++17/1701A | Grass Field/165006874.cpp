#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a[2][2];
        int z=0,o=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cin>>a[i][j];
                if(a[i][j]==0)z++;
                else o++;
            }
        }
        if(o==1)cout<<1<<endl;
        else
            cout<<o/2<<endl;
    }
}