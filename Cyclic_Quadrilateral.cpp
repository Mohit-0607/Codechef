#include<bits/stdc++.h>
using namespace std;

string solve(int A,int B, int C, int D){
     if(A+C==180 && B+D==180){
         return "YES";
     }
     return "NO";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,A,B,C,D;
    cin>>T;
    while(T--){
        cin>>A>>B>>C>>D;
        cout<<solve(A,B,C,D)<<"\n";
    }
    return 0;
}
