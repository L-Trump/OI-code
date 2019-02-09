#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
ll a[1005][1005]={};
int main(){
    int n,m,r,c;
    ll ans=0;
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m>>r>>c;
    rep(i,1,n)
      rep(j,1,m){
        cin>>a[i][j];
        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
      }
    rep(i,1,n-r+1)
      rep(j,1,m-c+1){
        ans=std::max(ans,a[i+r-1][j+c-1]-a[i+r-1][j-1]-a[i-1][j+c-1]+a[i-1][j-1]);
      }
    cout<<ans;
    return 0;
}
