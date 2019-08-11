#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    int n;
    bool map[1027][1027];
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    memset(map,0,sizeof(map));
    n=1<<n;
    rep(i,1,n){
      rep(j,1,n){
        if(i+j<=n){cout<<"0 ";map[i][j]=0;continue;}
        if(j==n){cout<<"1";map[i][j]=1;continue;}
        map[i][j]=map[i-1][j]^map[i-1][j+1];
        cout<<map[i][j]<<" ";
      }

      cout<<endl;
    }
    return 0;
}
