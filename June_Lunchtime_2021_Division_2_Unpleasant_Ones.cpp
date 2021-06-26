#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
         int n,i;
         cin >> n;
         int arr[n],ans[n],p=0,q=n-1;
         for(i=0;i<n;i++)
               cin >> arr[i];
         for(i=0;i<n;i++)
         {
              if(arr[i]%2==0)
              {
                   ans[p]=arr[i];
                   p++;
              }
              else
              {
                   ans[q]=arr[i];
                   q--;
              }
         }
         for(i=0;i<n;i++)
         {
              cout << ans[i] << " ";
          }
          cout <<endl;
    }
}
