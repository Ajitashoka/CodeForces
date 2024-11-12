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
  if(n==1)
  {
    cout<<ans[n-1]<<endl;
    return;
  }
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
  for(int i=0; i<n-1; i++)
  {
    if(((res-ans[i])/k)%2!=0)
    {
      cout<<-1<<endl;
      return;
    }
  }
  cout<<res<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
