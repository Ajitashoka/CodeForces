//https://codeforces.com/contest/2127/problem/C
// Editorial--->
// Sort the array of vector containing a and b according to max of a and b at first element. Now if max is same for few elements then we can realize that the
// absolute sum of difference doesn't change for any pair of indices. Other think we can realize by this fact that sum always increase if we select two pair of
// indices whose max is different.
// The player playing first can always aim to minimize the sum under the constraint of the problem by select the pair of indices that does not increase the sum.
// Else otherwise he select the pair at consecutive places after sorting to check which pair results in minimum sum.

// Idea
// ----> sort 
//   ----> Compute prefix and suffix sum
// ----> Check if two elements with equal max is present , return the original sum.
//   -----> return the minumum sum using prefix and suffix sum  by arranging the selected pair in sorted manner and return the palindrome-style-sum+pre+suf.
#include <bits/stdc++.h>
using namespace std;
long long fun(vector<vector<int>>&v)
{
  int n=v.size();
  long long final=1e18;
  vector<long long> pre(n,0);
  vector<long long> suf(n,0);
  pre[0]=abs(v[0][1]-v[0][2]);
  suf[n-1]=abs(v[n-1][1]-v[n-1][2]);
  
  for(int i=1; i<n; i++)
  pre[i]=pre[i-1]+abs(v[i][1]-v[i][2]);
  
  for(int i=n-2; i>=0; i--)
  suf[i]=suf[i+1]+abs(v[i][1]-v[i][2]);
  
  for(int i=0; i<n-1; i++)
  {
    vector<int> v1;
    v1.push_back(v[i][1]);
    v1.push_back(v[i][2]);
    v1.push_back(v[i+1][1]);
    v1.push_back(v[i+1][2]);
    sort(v1.begin(),v1.end());
    long long total=v1[3]-v1[0]+v1[2]-v1[1];
    long long a=0,b=0;
    if(i-1>=0)
    a=pre[i-1];
    if(i+2<n)
    b=suf[i+2];
    final=min(final,a+b+total);
  }
  return final;
}
void solve()
{
  int n,k;
  cin>>n>>k;
  
  vector<int> a(n,0);
  for(int i=0; i<n; i++)
  cin>>a[i];
  vector<int> b(n,0);
  for(int i=0; i<n; i++)
  cin>>b[i];
  
  long long sum=0;
  
  for(int i=0; i<n; i++)
  sum+=abs(a[i]-b[i]);
  
  vector<vector<int>> v;
  for(int i=0; i<n; i++)
  v.push_back({max(a[i],b[i]),a[i],b[i]});
  sort(v.begin(),v.end());
  for(int i=0; i<n-1; i++)
  {
    if(v[i+1][0]==v[i][0])
    {
      cout<<sum<<endl;
      return;
    }
  }
  cout<<fun(v)<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
