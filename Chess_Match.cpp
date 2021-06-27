#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(ll n,ll a,ll b){
    ll turnTime=2*(180+n);
    ll totalLeft=a+b;
    return turnTime-totalLeft;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T,n,a,b;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        cout<<solve(n,a,b)<<"\n";
    }
    return 0;
}
