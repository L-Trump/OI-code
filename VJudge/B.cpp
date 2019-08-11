#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using namespace std;
typedef long long ll;
int main(){
    char str[1005];
    int T;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    cin>>T;
    getchar();
    rep(i,1,T){
      std::stack<char> stk;
      gets(str);
      rep(j,0,(int)strlen(str)-1){
        if(str[j]!=' ') stk.push(str[j]);
        else{
          while(!stk.empty()){
            cout<<stk.top();
            stk.pop();
          }
        cout<<" ";
       }
      }
      while(!stk.empty()){cout<<stk.top();stk.pop();}
      cout<<endl;
    }
    return 0;
}
