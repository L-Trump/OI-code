#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;

int main(){
    int n,ans=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    scanf("%d",&n);
    rep(i1,1,3)rep(i2,1,3)rep(i3,1,3)rep(i4,1,3)rep(i5,1,3)
    rep(i6,1,3)rep(i7,1,3)rep(i8,1,3)rep(i9,1,3)rep(i10,1,3)
    if(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10==n)ans++;
    printf("%d\n",ans);
    rep(i1,1,3)rep(i2,1,3)rep(i3,1,3)rep(i4,1,3)rep(i5,1,3)
    rep(i6,1,3)rep(i7,1,3)rep(i8,1,3)rep(i9,1,3)rep(i10,1,3)
    if(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10==n){
      printf("%d %d %d %d %d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6,i7,i8,i9,i10);
    };

    return 0;
}
