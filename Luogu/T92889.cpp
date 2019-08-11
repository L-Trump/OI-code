#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
bool map[505][505];
int n,m;
void init(){
    char c;
    cin>>n>>m;
    rep(i,1,n)
      rep(j,1,m){
        cin>>c;
        map[i][j]=(c=='.'?1:0);
      }
}
int aq(int x, int y, int X, int Y){
    return (X-x)*(X-x)+(Y-y)*(Y-y);
}
int xa,ya,xb,yb;
struct node{
    int x,y;
    node(){
      x=y=0;
    }
    node(int _x,int _y){
      x=_x;
      y=_y;
    }
    bool operator<(const node &b) const{
      return aq(this->x,this->y,xb,yb)>aq(b.x,b.y,xb,yb);
    }
};
bool search(int x1,int y1,int x2,int y2){
    bool vis[505][505]={};
    if(!map[x1][y1]||!map[x2][y2]) return false;
    std::priority_queue<node> q;
    xa=x1;ya=y1;xb=x2;yb=y2;
    q.push(node(xa,ya));
    vis[xa][ya]=1;
    node root;
    while(!q.empty()){
      root=q.top();q.pop();
      if(root.x==x2&&root.y==y2){
        return true;
        // flag=1;
        break;
      }
      int xx=root.x,yy=root.y;
      if(!vis[xx+1][yy]&&map[xx+1][yy]&&xx+1<=x2){
        q.push(node(xx+1,yy));
        vis[xx+1][yy]=1;
      }
      if(!vis[xx][yy+1]&&map[xx][yy+1]&&yy+1<=y2){
        q.push(node(xx,yy+1));
        vis[xx][yy+1]=1;
      }
    }
    return false;
}
int main(){
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int Q,x1,x2,y1,y2;
    init();
    cin>>Q;
    rep(i,1,Q){
      cin>>x1>>y1>>x2>>y2;
      cout<<(search(x1,y1,x2,y2) ? "Yes" : "No")<<endl;
    }
    return 0;
}
