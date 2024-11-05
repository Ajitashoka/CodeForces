//https://codeforces.com/problemset/problem/2007/C
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n,a,b;
  cin>>n>>a>>b;
  //Adding a and b to some two numbers implies that we can add the gcd of a and b to the smaller number
  int g=__gcd(a,b);
  vector<int> ans(n,0);
  map<int,int> mp;
  //in order to find the minimum range we can find the remainder that we can get from the array for the given gcd g.
  //A nice way to think is that we can construct the array from the remainders using a and b.
  for(int i=0; i<n; i++)
  {
    cin>>ans[i];
    mp[ans[i]%g]++;
  }
  vector<int> ans1;
  for(auto j:mp)
  ans1.push_back(j.first);
  n=ans1.size();
  int d=ans1[n-1]-ans1[0];
  //Once we have remainder add g to the smallest number,that becomes largest and next one is smallest,find the range.
  //Reason being the map gives sorted array.
  for(int i=1; i<n; i++)
  {
    d=min(d,ans1[i-1]+g-ans1[i]);
  }
  cout<<d<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
