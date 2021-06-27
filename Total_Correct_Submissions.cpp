#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int>&a,pair<string,int>&b){
    return a.second<b.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
          
          int n;
          cin>>n;
          map<string,int> ma; vector<pair<string,int>> vec;
          for(int i=1;i<=n*3;i++){ 
              string s; int x;
              cin>>s>>x;
               
              auto it=ma.find(s);
              if(it!=ma.end()){
                  
                  ma[s]=it->second+x;
              }else{
                  ma[s]=x;
              }
          }
        for(auto & it:ma){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end(),cmp);
          for(auto&it:vec){
              cout<<it.second<<" ";
          }
          cout<<"\n";
    }
    return 0;
}
