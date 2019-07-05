#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
#define NMAX 100005
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;using std::vector;
typedef long long ll;
int n,m;
std::queue<int> q;
vector<int> e[NMAX];
bool vis[NMAX];
int ans[NMAX];
void read(int &x){
  char c=getchar();x=0;
  while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
  return;
}

void init(){
  int u,v;
  read(n);read(m);
  rep(i,1,m){
    read(u);read(v);
    e[v].push_back(u);
  }
}
int main(){
    int root,cnt=n;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    init();
    per(i,n,1){
      if(vis[i]) continue;
      q.push(i);
      while(!q.empty()){
        root=q.front();q.pop();
        if(vis[root])continue;
        vis[root]=1;
        ans[root]=i;
        rep(j,0,(int)e[root].size()-1){
          q.push(e[root][j]);
        }
      }
    }
    rep(i,1,n) cout<<ans[i]<<" ";
    return 0;
}
