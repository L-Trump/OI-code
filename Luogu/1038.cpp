#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using namespace std;
typedef long long ll;
typedef unsigned int ui;

struct node{
    int v,u;
    queue<pair<node,int>> edge;
    node(){
      v=u=0;
    }
} e[105];

queue<int> root;

inline void createEdge(node a,node b,int w){
    a.edge.push(make_pair(b,w));
    return;
}
int main(){
    int n,p;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    scanf("%d%d",&n,&p);
    rep(i,1,n){
      scanf("%d%d",&e[i].v,&e[i].u);
      if(e[i].v!=0) root.push(i);
    }
    rep(i,1,p){
      int a,b,w;
      scanf("%d%d%d",&a,&b,&w);
      createEdge(e[a],e[b],w);
      createEdge(e[b],e[a],w);
    }
    return 0;
}
