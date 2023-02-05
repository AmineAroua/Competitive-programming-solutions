#include<bits/stdc++.h>
using namespace std;
bool diff(int j,int i,int num[64][2],int z){
    for(int k=0;k<z;k++){
        if(j==num[k][0]&&i==num[k][1])return false;
    }
    return true;
}
int main(){
    int t;cin>>t;
    while(t--){
        char tab[8][8];
        int num[64][2];
        for(int j=0;j<8;j++){
            for(int i=0;i<8;i++){
                cin>>tab[j][i];
            }
        }
        int z=0,y=0;
        bool access=true;
        for(int j=0;j<8;j++){
            for(int i=0;i<8;i++){
                if(tab[j][i]=='#'&&y<=1&&diff(j,i,num,z)){
                    int h=i;
                    y++;
                    if(tab[j+1][i+1]=='#'){
                    for(int k=j;k<8;k++){
                        if(h>=8)break;
                        num[z][0]=k;
                        num[z][1]=h;
                        z++;
                        h++;
                    }}
                    else{
                        for(int k=j;k<=8;k++){
                        if(h<0)break;
                        num[z][0]=k;
                        num[z][1]=h;
                        z++;
                        h--;
                    }
                    }
                }}
                if(y>1){j=8;break;}
            }
            int a[8][8];
            for(int i=0;i<8;i++){for(int j=0;j<8;j++)a[i][j]=0;}
            for(int i=0;i<z;i++)
            {
                a[num[i][0]][num[i][1]]++;
            }
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]>=2){
                        cout<<i+1<<" "<<j+1<<endl;
                        i=8;
                        break;
                    }
                }
            }
        }
    }
 