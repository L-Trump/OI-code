#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define NMAX 20000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
bool isPrime[NMAX+5]={},vis[NMAX+5]={};
int prime[NMAX+5]={};
int cnt=0;
void checkPrime(){
    rep(i,2,NMAX){
      if(!vis[i]){
        isPrime[i]=true;
        prime[++cnt]=i;
      }
      for(int j=1;j<=cnt&&i*prime[j]<=NMAX;j++){
        vis[i*prime[j]]=true;
        if(i%prime[j]==0) break;
      }
    }
}
int main(){
    int n;

    std::ios::sync_with_stdio(false);
    cout.tie(0);
    checkPrime();
    cin>>n;
    rep(i,1,cnt){
      if(prime[i]>n/3) break;
      rep(j,i,cnt){
        if(prime[j]>(n-prime[i])/2) break;
        if(isPrime[n-prime[i]-prime[j]]){
          cout<<prime[i]<<" "<<prime[j]<<" "<<n-prime[i]-prime[j];
          return 0;
        }
      }
    }
    // while(cin>>n){
    //   cout<<isPrime[n]<<endl;
    // }
    return 0;
}
