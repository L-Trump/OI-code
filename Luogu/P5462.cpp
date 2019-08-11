#include <cstdio>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <deque>
#include <stack>
#define NMAX 100000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::string;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
void read(int &x){
    char c=getchar();x=0;
    while(c<='9' && c>='0') {x=x*10+c-'0';c=getchar();}
    return;
}
struct cmp{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
      return a.first<b.first;
    }
};
std::priority_queue<pair<int,int>,std::vector<pair<int,int> >, cmp > q;
int main(){
    int n,x,front[NMAX+5],to[NMAX+5],ans[NMAX+5]={},a[NMAX+5],cnt=0;
    bool vis[NMAX+5]={};
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    read(n);
    rep(i,1,n){
      read(x);
      a[i]=x;
      to[i]=i+1;
      front[i+1]=i;
      q.push(make_pair(x,i));
    }
    to[n]=-1;
    pair<int, int> root;
    while(!q.empty()){
      root=q.top();q.pop();
      if(vis[root.second]||to[root.second]==-1)continue;
      ans[++cnt]=root.first;
      ans[++cnt]=a[to[root.second]];
      vis[root.second]=vis[to[root.second]]=1;
      to[front[root.second]]=to[to[root.second]];
      front[to[to[root.second]]]=front[root.second];
    }
    rep(i,1,cnt) printf("%d ",ans[i]);
    return 0;
}
