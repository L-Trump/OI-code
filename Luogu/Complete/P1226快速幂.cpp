#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    ll a,k,p,q,ans,base;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    // std::ios::sync_with_stdio(false);
    // cout.tie(0);
    cin>>base>>p>>q;
    a=base;k=p;
    ans=1;
    while(p>0){
      if(p & 1) {
        ans=ans*base%q;
      }
      base=base*base%q;
      p>>=1;
    }
    ans%=q;
    cout<<a<<"^"<<k<<" mod "<<q<<"="<<ans<<endl;
    return 0;
}
