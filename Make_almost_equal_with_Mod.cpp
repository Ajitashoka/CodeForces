//https://codeforces.com/problemset/problem/1909/B
#include <bits/stdc++.h>
using namespace std;
// helper function to compute number of remainder
bool df(vector<long long>&ans,long long g)
{
  map<long long,int> mp;
  for(int i=0; i<ans.size(); i++)
  mp[ans[i]%g]++;
  
  if(mp.size()==2)
  return true;
  return false;
}
void solve()
{
  int n;
  cin>>n;
  vector<long long> ans(n,0);
  for(int i=0; i<n; i++)
  cin>>ans[i];
  
  sort(ans.begin(),ans.end());
  //take consecutive difference of first few numbers
  //it will surely contain numbers with same remainder.
  if(n==2)
  {
    cout<<setprecision(20)<<pow(10,18)<<endl;
    return;
  }
  
  vector<long long> v;
  for(int i=0; i<n && i<20; i++)
  {
    for(int j=i+1; j<n && j<20; j++)
    {
      v.push_back(abs(ans[i]-ans[j]));
    }
  }
  //Since the multiplication factor could be different take their GCD!!
  for(int i=0; i<v.size(); i++)
  {
    for(int j=i+1; j<v.size(); j++)
    {
      if(df(ans,__gcd(v[i],v[j])))
      {
        cout<<__gcd(v[i],v[j])<<endl;
        return;
      }
    }
    //check if the number holds the condition
    //if yes print!!
    if(df(ans,v[i]))
    {
      cout<<v[i]<<endl;
      return;
    }
  }
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
