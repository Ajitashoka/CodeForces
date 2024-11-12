//https://codeforces.com/problemset/problem/1993/C
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int> ans(n,0);
  for(int i=0; i<n; i++)
  cin>>ans[i];
  sort(ans.begin(),ans.end());
  // If there is single light source print its initial switch time.
  if(n==1)
  {
    cout<<ans[n-1]<<endl;
    return;
  }
  //Start to find the minimum time for all the switches that were turned on before the last switch such that they are ON.
  //A nice way to find it to binary search within the time frame in which last light is turned on.
  int res=0;
  for(int i=0; i<n-1; i++)
  {
    int l=ans[n-1]-1;
    int r=ans[n-1]+k;
    
    if(((l+1-ans[i])/k)%2==0)
    {
      res=max(res,l+1);
      continue;
    }
    //Binary Search Implementation
    while(r>l+1)
    {
      int mid=(l+r)/2;
      if(((mid-ans[i])/k)%2==0)
      r=mid;
      else
      l=mid;
    }
    if(r!=ans[n-1]+k && ((r-ans[i])/k)%2==0)
    res=max(res,r);
    else
    {
      cout<<-1<<endl;
      return;
    }
  }
  // Check if the time works well for all the lights
  for(int i=0; i<n-1; i++)
  {
    if(((res-ans[i])/k)%2!=0)
    {
      cout<<-1<<endl;
      return;
    }
  }
  //ON Alright,lets print it.
  cout<<res<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
