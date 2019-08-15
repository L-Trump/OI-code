// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
typedef long long ll;
struct edge;
struct node{
    int tag,siz,dep;
    bool vis;
    node *fa,*top,*maxson;
    edge* head;
    node(){
      tag=siz=dep=0;
      fa=NULL;
      vis=0;
      top=this;
      head=NULL;
    }
} a[500010];
struct edge{
    node* to;
    bool enable;
    edge* nxt;
    edge(){
      to=NULL;
      enable=0;
      nxt=NULL;
    }
};
inline void createEdge(node* u, node* v){
    edge* e=new edge;
    e->to=v;
    e->nxt=u->head;
    u->head=e;
}
void dfs1(node* root){
    if(root->fa) root->dep=root->fa->dep+1;
    for(edge* i=root->head;i;i=i->nxt){
      if(i->to->vis) continue;
      i->to->vis=1;
      i->enable=1;
      i->to->fa=root;
      dfs1(i->to);
      root->siz+=i->to->siz;
      if(!root->maxson) root->maxson=i->to;
      else if(i->to->siz>root->maxson->siz) root->maxson=i->to;
      i->to->vis=0;
    }
}
void dfs2(node* root){
    for(edge* i=root->head;i;i=i->nxt){
      if(!i->enable) continue;
      // i->to->vis=1;
      if(i->to==root->maxson) i->to->top=root->top;
      dfs2(i->to);
      // i->to->vis=0;
    }
}
node* lca(node* u, node* v){
  while(u->top!=v->top)
    // cout<<"HERE"<<endl;
    if(u->top->dep>v->top->dep)u=u->top->fa; else v=v->top->fa;

  return u->dep<v->dep?u:v;
}
int main(){
    int n,m,rt,u,v;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    scanf("%d%d%d",&n,&m,&rt);
    rep(i,1,n){
      a[i].tag=i;
      a[i].siz=1;
    }
    rep(i,1,n-1){
      scanf("%d%d",&u,&v);
      createEdge(&a[u],&a[v]);
      createEdge(&a[v],&a[u]);
    }
    a[rt].dep=1;
    a[rt].vis=1;
    dfs1(&a[rt]);
    dfs2(&a[rt]);
    // rep(i,1,n) if(a[i].fa) cout<<a[i].fa->tag<<" ";
    rep(i,1,m){
      scanf("%d%d",&u,&v);
      printf("%d\n",lca(&a[u],&a[v])->tag);
    }
    return 0;
}
