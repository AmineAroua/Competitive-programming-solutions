#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    bool access=true;
    char c;cin>>c;
    char grid[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    if(m!=1)
    {for(int i=0;i<m;i++){
        if(grid[n-1][i]!=c){
            access=false;
            break;
        }
    }
    if(access)cout<<"YES";
    else cout<<"NO";
    }
    else{
        for(int i=0;i<n;i++){
            if(grid[i][0]!=c){
                access=false;
                break;
            }
        }
        if(access)cout<<"YES";
        else cout<<"NO";
    }
}
