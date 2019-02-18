#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using namespace std;
typedef long long ll;
typedef unsigned int ui;

struct node{
    int v,u,in,out;
    bool vis;
    vector<pair<int,int> > edge;
    node(){
      v=u=0;
      in=out=0;
      vis=false;
    }
} e[105];

queue<int> root;
priority_queue<int,vector<int>,greater<int> > last;

inline void createEdge(int a,int b,int w){
    e[a].edge.push_back(make_pair(b,w));
    return;
}

bool isExisted(queue<int> q,int a){
    while(!q.empty()){
      if(a==q.front()) return true;
      q.pop();
    }
    return false;
}

void bfs1(){
    queue<int> q=root;
    int t;
    while(!q.empty()){
      t=q.front();q.pop();
      e[t].vis=true;
      e[t].v-=e[t].u;
      rep(i,0,(int)e[t].edge.size()-1){
        int nxt=e[t].edge[i].first;
        int wid=e[t].edge[i].second;
        if(!e[nxt].vis){
          e[t].out++;
          if(!isExisted(q,nxt)) q.push(nxt);
          e[nxt].in++;
          if(e[t].v>0) e[nxt].v+=e[t].v*wid;
        }
      }
      if(e[t].out==0) last.push(t);
    }
}
/*
void bfs2(){
    queue<int> q=root;
    int t;
    while(!q.empty()){
      t=q.front();q.pop();
      e[t].vis=true;
      //e[t].v-=e[t].u;
      rep(i,0,(int)e[t].edge.size()-1){
        int nxt=e[t].edge[i].first;
        if(!e[nxt].vis){
          e[t].out++;
          if(!isExisted(q,nxt)) q.push(nxt);
          e[nxt].in++;
        }
      }
      if(e[t].out==0) last.push(t);
    }
}
*/
int main(){
    int n,p,t;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    scanf("%d%d",&n,&p);
    rep(i,1,n){
      scanf("%d%d",&e[i].v,&e[i].u);
      if(e[i].v!=0){
        root.push(i);
        e[i].u=0;
      }
    }
    rep(i,1,p){
      int a,b,w;
      scanf("%d%d%d",&a,&b,&w);
      createEdge(a,b,w);
      createEdge(b,a,w);
    }
    bfs1();
    //rep(i,1,n) e[i].vis=false;
    while(!last.empty()){
      t=last.top();
      last.pop();
      if(e[t].v>0)
        printf("%d %d\n",t,e[t].v);
    }
    return 0;
}
