//https://codeforces.com/contest/2028/problem/C
//PrefixSum+BinarySearch
#include <bits/stdc++.h>
using namespace std;
int bin(vector<int> &ans,int r,int num)
{
  int l=ans.size();
  while(l>r+1)
  {
    int mid=(l+r)/2;
    if(ans[mid]<num)
    l=mid;
    else
    r=mid;
  }
  return r;
}
void preCompute1(vector<int>&ans,int v,vector<int>&prefix)
{
  int i=0;
  int n=ans.size();
  while(i<n)
  {
    int num=ans[i];
    int j=i+1;
    while(j<n && num<v)
    {
      num+=ans[j];
      j++;
    }
    
    if(num>=v)
    prefix[j-1]=1;
    i=j;
  }
  
  for(int i=1; i<n; i++)
  prefix[i]+=prefix[i-1];
}
void preCompute2(vector<int>&ans,int v,vector<int>&prefix)
{
  int n=ans.size();
  int i=n-1;
  while(i>=0)
  {
    int num=ans[i];
    int j=i-1;
    while(j>=0 && num<v)
    {
      num+=ans[j];
      j--;
    }
    
    if(num>=v)
    prefix[j+1]=1;
    i=j;
  }
  
  for(int i=n-2; i>=0; i--)
  prefix[i]+=prefix[i+1];
}
void solve()
{
  int n,m,v;
  cin>>n>>m>>v;
  vector<int> ans(n,0);
  for(int i=0; i<n; i++)
  cin>>ans[i];
  
  vector<int> prefix(n,0);
  vector<int> suffix(n+1,0);
  preCompute1(ans,v,prefix);
  preCompute2(ans,v,suffix);
  
  vector<long long> sum(n,0);
  for(int i=0; i<n; i++)
  {
    if(i!=0)
    sum[i]+=ans[i]+sum[i-1];
    else
    sum[i]=ans[i];
  }
  long long val=-1;
  for(int i=0; i<n; i++)
  {
    int num1=0;
    int num2=0;
    
    if(i>0)
    num1=prefix[i-1];
    
    int in=bin(suffix,i,m-num1);
    if(in<=i)
    {
      if(in==i && suffix[in]>=m-num1)
      val=max(val,1LL*0);
      continue;
    }
    
    if(i==0 && suffix[in]>=m-num1)
    val=max(val,sum[in-1]);
    else if(suffix[in]>=m-num1)
    val=max(val,sum[in-1]-sum[i-1]);
  }
  cout<<val<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
