#include <iostream>
#include <cstdio>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define NMAX 1000000
#define INF 9223372036854775800
using namespace std;
typedef long long ll;
int n,m[NMAX+5];
ll dp[NMAX+5];
ll qMax(int l, int r){
    ll anss=-INF;
    dp[l]=m[l];
    rep(i,l+1,r){
     dp[i]=m[i];
     dp[i]=max(dp[i-1]+dp[i],dp[i]);
    }
    rep(i,l,r) anss=max(anss,dp[i]);
    return anss;
}
void readm(){
    cin>>n;
    //for(M=1;M<=n;M<<=1);
    rep(i,1,n){
        cin>>m[i];
    }
}
ll ans=-INF;
void tryit(){
    rep(i,1,n-2)
        rep(j,i+1,n-1){
            ans=max(ans,qMax(1,i)+qMax(i+1,j)+qMax(j+1,n));
        }
}
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("jx.in","r",stdin);
    freopen("jx.out","w",stdout);
    readm();
    tryit();
    cout<<ans<<endl;
    //cerr<<qMax(1,3);
}
