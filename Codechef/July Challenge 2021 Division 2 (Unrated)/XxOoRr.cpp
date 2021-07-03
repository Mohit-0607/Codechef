#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt", "w", stdout);
	#endif
	    void calculate(vector<int> &v, int N);
		int test;
		cin >> test;
		while (test--){
		    int N, K;
		    cin >> N >> K;
		    int arr[N];
		    for(int i=0; i<(int)N; i++)
		        cin >> arr[i];
		    vector<int> v(32, 0);
		    for (int i=0; i<N; i++)
		        calculate(v, arr[i]);
		    
		    int res = 0;
		    for (int i=0; i<32; i++){
		        if (v[i] == 0)
		            continue;
		        else if (v[i] % K == 0)
		            res += (v[i] / K);
		        else
		            res += (v[i] / K + 1);
		    }
		    cout << res << endl;
		}
	return 0;
}

void calculate(vector<int> &v, int N){
    string str="";
    int i, j=31;
    while(N > 0){
        str += to_string(N%2);
        N /= 2;
    }
    int size = str.size();
    for (i=0; i<size; i++){
        if (str[i] == '1')
            v[j] += 1;
        j--;
    }
}
