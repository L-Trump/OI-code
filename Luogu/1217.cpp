#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define NMAX 10000000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
bool vis[NMAX+5]={},isPrime[NMAX+5]={};
int prime[NMAX+5]={};
bool isHui(int a){
    int b=a, t=0;
    while(a!=0){
      t=t*10+a%10;
      a/=10;
    }
    if(t==b) return true;
    else return false;
}
int main(){
    int a,b;
    int cnt=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    //cout<<isHui(121)<<endl;
    //cerr<<isHui(3)<<endl;
    cin>>a>>b;
    if(b>10000000) b=10000000;
    rep(i,2,b){
      if(!vis[i]) {prime[++cnt]=i;isPrime[i]=1;}
      for(int j=1;j<=cnt&&i*prime[j]<=b;j++){
        vis[i*prime[j]]=true;
        if(i%prime[j]==0) break;
      }
    }
    rep(i,a,b){
      //cerr<<"prime: "<<prime[i]<<'\n';
      if(i>NMAX) break;
      if(isHui(i)&&isPrime[i]) cout<<i<<'\n';
    }
    return 0;
}
