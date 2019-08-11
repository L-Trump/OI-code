#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define NMAX 32767
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    int n,m,pos,cnt=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    while(cin>>n>>m){
      cnt++;
      bool isDead[NMAX+NMAX+5]={};
      pos=0;
      rep(i,1,n){
        rep(j,1,m){
          pos++;
          if(pos>n+n) pos=1;
          while(isDead[pos]) {pos++;if(pos>n+n) pos=1;}
        }
        isDead[pos]=1;
      }
      rep(i,1,n+n) {cout<<(isDead[i] ? "B":"G");if(i%50==0) cout<<endl;}
      if(2*n%50!=0)cout<<endl;
      cout<<endl;
    }
    return 0;
}
