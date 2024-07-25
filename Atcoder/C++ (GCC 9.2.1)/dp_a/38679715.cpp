#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  	map<int,int> mp;
  	vector<int> v(n);
  	for(int i=0;i<n;i++){
      cin>>v[i];
      mp[v[i]]++;
    }
  int c=0;
  	for(auto it=mp.begin();it!=mp.end();it++){
      if(it->second>=it->first){c+=it->second-it->first;}
      else{
      	c+=it->second ;} 
      
    }
  cout<<c;
}