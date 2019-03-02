#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    double s,x;
    double dis=7,pos=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>s>>x;
    while(pos<s-x){
      pos+=dis;
      dis*=0.98;
    }
    pos+=dis*0.98;
    if(pos<s+x)cout<<"y";
    else cout<<"n";
    cout<<endl;
    return 0;
}
