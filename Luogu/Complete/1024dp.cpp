#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
struct obj{
    int t,v;
    obj(){
      t=v=0;
    }
} o[105];
int dp[1005]={};
int main(){
    int t,n;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>t>>n;
    rep(i,1,n)
      cin>>o[i].t>>o[i].v;
    rep(i,1,n)
      per(j,t,o[i].t)
        dp[j]=std::max(dp[j],dp[j-o[i].t]+o[i].v);
    cout<<dp[t]<<endl;
    return 0;
}
