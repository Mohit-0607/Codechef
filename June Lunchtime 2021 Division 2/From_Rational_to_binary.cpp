#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define mod 1000000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w", stdout);
#endif

    fast;

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll x = log2(b);
        ll c = 1; ll d = 2;
        for (int i = 1; i <= x; i++)
        {
            c = c * d;
        }

        if (c == b)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}