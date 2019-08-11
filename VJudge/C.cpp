#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
// using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
using namespace std;
typedef long long ll;
int main(){
    char s[205];
    double x,ans;
    bool mult,iu;
    stack<double> stk;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    gets(s);
    while(strlen(s)!=1||s[0]!=0){
      x=0;
      mult=0;
      rep(i,0,(int)strlen(s)-1){
        if(s[i]>='0'&&s[i]<='9') x=x*10+s[i]-'0';
        if(s[i]==' '){
          if(ans==0) {ans=x;x=0;} else
          if(mult) {ans*=x;x=0;} else
          if(iu)
        }
        if(s[i]=='+') {stk.push(ans);x=0;}
        if(s[i]=='*') {mult}
      }
    }
    return 0;
}
