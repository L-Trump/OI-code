#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    int a,b,c,_a,_b,_c;
    bool isFound=0;
    int minn,maxx,sum=0,mult=1;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>a>>b>>c;
    minn=std::min(std::min(a,b),c);
    maxx=std::max(std::max(a,b),c);
    for(int i=123;i<=987;i++){
      if(maxx*i/a>987||minn*i/a<123) continue;
      if(i*b%a!=0||i*c%a!=0) continue;
      sum=0;mult=1;
      _a=i;_b=i*b/a;_c=i*c/a;
      rep(_i,1,3){
        sum+=_a%10+_b%10+_c%10;
        mult*=(_a%10)*(_b%10)*(_c%10);
        _a/=10;_b/=10;_c/=10;
      }
      if(sum==45&&mult==362880){
          isFound=1;
          cout<<i<<" "<<i*b/a<<" "<<i*c/a<<'\n';
      }
    }
    if(!isFound) cout<<"No!!!"<<endl;
    return 0;
}
