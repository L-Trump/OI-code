//我真的是不小心用的......
// (写这道题的时候还不知道啥是记忆化搜索)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin; using std::cout; using std::cerr; using std::endl;
typedef long long ll;
#define NMAX 1000
int N,ans=0;
int a[NMAX+5]={};
ll dfs(int k){
    int t=0;
    if(a[k]!=0){
      return a[k];
    }
    for (int i=1;i<=k/2;i++){
      t+=dfs(i);
    }
    a[k]=t+1;
    return a[k];
}
int main(){
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>N;
    std::cout << dfs(N) << '\n';
    return 0;
}
