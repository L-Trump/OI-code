#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
struct circle{
    circle *head, *next;
    bool final, visited;
    int x,y,z;
    circle(){
      next=head=NULL;
      z=x=y=0;
      final=false;
      visited=false;
    }
};
circle *e[1005];
circle *down[1005];

circle* create(){
    return new circle;
}

double dis(circle* a, circle* b){
    double x1=(double)a->x,x2=(double)b->x,y1=(double)a->y,y2=(double)b->y;
    double z1=(double)a->z,z2=(double)b->z;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

void newEdge(circle* a, circle* b){
      if(a->head!=NULL){
        b->next=a->head;
      }
      a->head=b;
      //printf("%d %d %d -> %d %d %d\n", a->x,a->y,a->z,b->x,b->y,b->z);
}



bool bfs(circle *root){
    std::queue<circle*> q;
    if(root->visited) return false;
    q.push(root);
    while(!q.empty()){
      root=q.front();
      q.pop();
      if(root->visited) continue;
      root->visited=true;
      if(root->final) return true;
      for(circle* p=root->head;p!=NULL;p=p->next){
        q.push(p);
      }
    }
    return false;
}


int main(){
    int T,n,h,r,x,y,z;
    int cntd;
    bool found;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>T;
    rep(i,0,1005) e[i]=down[i]=NULL;
    rep(k,1,T){
        cntd=0;found=false;
        cin>>n>>h>>r;
        rep(i,1,n){
          e[i]=create();
          cin>>x>>y>>z;
          e[i]->x=x;e[i]->y=y;e[i]->z=z;
          if (z<=r) down[++cntd]=e[i];
          if (h-z<=r) e[i]->final=true;
          rep(j,1,i-1){
          //  cerr<<"distance of "<<j<<" and "<<i<<" is "<<dis(e[1],e[i])<<endl;
            if(dis(e[j],e[i])<=2*r){ //z低位指向高位，同位互指
              if(e[i]->z>e[j]->z) {
                newEdge(e[j],e[i]);
                // cerr<<"connect: "<<j<<"->"<<i<<endl;
              }
              if(e[i]->z<e[j]->z) {
                newEdge(e[i],e[j]);
                // cerr<<"connect: "<<i<<"->"<<j<<endl;
              }
              if(e[i]->z==e[j]->z){
                newEdge(e[i],e[j]);
                newEdge(e[j],e[i]);
                // cerr<<"connect: "<<i<<" and "<<j<<endl;
              }
            }
          }
        } //建图
        //cerr<<"down count="<<cntd<<endl;
        //cerr<<"e[2]'s final is "<<e[2]->final<<endl;
        //cerr<<down[1]->x<<" "<<down[1]->y<<" "<<down[1]->z<<endl;
        rep(i,1,cntd){ //广搜
          if(bfs(down[i])){
              found=true;
              cout<<"Yes"<<endl;
              break;
          }
        }
        if(!found) cout<<"No"<<endl;
        rep(i,1,n){
          delete e[i];
          down[i]=e[i]=NULL;
        }

    }
    return 0;
}
