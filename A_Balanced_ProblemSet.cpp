//https://codeforces.com/problemset/problem/1925/B
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n,x;
  cin>>n>>x;

  //find the div and remainder
  int d=n/x;
  int r=n%x;
  
  if(r%d==0)
  {
    cout<<d<<endl;
    return;
  }
  //compute all possible divisor of number n.
  map<int,int> mp;
  for(int i=1; i*i<=n; i++)
  {
    if(n%i==0)
    {
      mp[i]++;
      mp[n/i]++;
    }
  }
  //if i is the gcd then gcd of (x-1) number of i + (d-i)*(x-1)+d+r must be i.
  //we are adding the difference of d and gcd to the last number.
  //if gcd holds true it must be for this as well.
  //Since these gcd factors add upto n this must be a factor of n.
  //its sufficient to check all possible divisors of n to be satisfying gcd or not.
  int num=0;
  for(auto j:mp)
  {
    int i=j.first;
    if(i<=d && __gcd(i,(x-1)*(d-i)+r+d)==i)
    {
      //take maximum.
      num=max(num,i);
    }
  }
  cout<<num<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
