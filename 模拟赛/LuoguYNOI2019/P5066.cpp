#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
#define NMAX 1000000
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int n,M;
bool a[4*NMAX+5]={};
std::vector<int> opt[4*NMAX+5];
void buildZFW(){
    for(M=1;M<=n;M<<=1);
    rep(i,M+1,M+n) cin>>a[i];
    per(i,M-1,1) a[i]=a[i<<1]+a[i<<1|1];
}
ll qSum(int l, int r){
    ll ans;
    for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
      if(~l&1) ans+=a[l^1];
      if(r&1) ans+=a[r^1];
      //ans+=a[r];
    }
    return ans;
}
void changeTo0(int l, int r){
    for(l+=M-1,r+=M+1;)
}
int main(){
    int m;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m;
    buildZFW();
    return 0;
}
