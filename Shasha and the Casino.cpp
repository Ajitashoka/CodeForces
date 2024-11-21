https://codeforces.com/problemset/problem/1929/C
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  //take input.
  int k,x,n;
  cin>>k>>x>>n;
  //There are x consecutive hurdles that Shasha has to cross,if he has enough coins at each step he can win.
  //The first step to win requires just one coin,if he wins at the first step itself he can achieve any n.
  //For next step we compute the minimum number of coins required to win.
  //Similary at each step we compute minimum coins required,ensuring he wins.
  //If he can win at each step,implies that at whichever point casino decide to choose WIN,Shahsa is benifitted.
  int req=0;
  for(int i=1; i<=x; i++)
  {
    //Total coins left
    int num=n-req;

    //Required no of coins
    int p;
    if((req+1)%(k-1)==0)
    p=(req+1)/(k-1);
    else
    p=(req+1)/(k-1)+1;

    //If leftover coins are insufficient print NO.
    if(num-p<=0)
    {
      cout<<"NO"<<endl;
      return;
    }
     req+=p;
  }

  //If after X consecutive rounds,leftover coins are enough to register a WIN,here we go he has INFINITE coins.
  if(1LL*(n-req)*k>n)
  cout<<"YES"<<endl;
  else
  cout<<"NO"<<endl;
}
int main() 
{
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
  solve();
}
