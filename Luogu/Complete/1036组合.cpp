#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define NMAX 20
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
// bool ifzs[XMAX+5][1]={};
ll a[NMAX+5]={};
int K,N,ans=0;
bool zs(int n){//判断是否质数
    int s=sqrt(double(n));
    for(int i=2;i<=s;i++){
        if(n%i==0)return false;
    }
    return true;
}
ll v[NMAX+5]={};
ll sum(){
  int i;
  ll t=0;
  for (i=1;i<=K;i++){
    t+=v[i];
  }
  return t;
}
void dfs(int pos, int last){
    int i;
    if (pos==K+1) {
      if (zs(sum())) ans++;
      return;
    }
    for(i=last+1;i<=N;i++){
        v[pos]=a[i];
        dfs(pos+1, i);
      }
}
int main(){
    int i;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>N>>K;
    for (i=1;i<=N;i++){
      cin>>a[i];
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
