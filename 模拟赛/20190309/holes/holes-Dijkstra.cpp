#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define NMAX 5000
#define MMAX 30000
using namespace std;
typedef long long ll;
int n;
struct hole{
    int w;
    int dis;
    hole(){
        w=0;
        dis=1000000007;
    }
} h[2*NMAX+5];
struct edge{
    int to;
    int w;
};
vector<edge> e[2*NMAX+5];
inline void createEdge(int a, int b, int s){
    edge c;
    c.to=b;
    c.w=s;
    e[a].push_back(c);
}

void dijkstra(int root){
    priority_queue<int,vector<int>,greater<int> > q;
    bool vis[2*n+5]={};
    h[root].dis=0;
    q.push(root);
    while(!q.empty()){
        root=q.top();q.pop();
        if(vis[root]) continue;
        vis[root]=true;
        rep(i,0,(int)e[root].size()-1){
            int to=e[root][i].to;
            int w=e[root][i].w;
            if(h[root].dis+w<h[to].dis){
                h[to].dis=h[root].dis+w;
                q.push(to);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("holes.in","r",stdin);
    freopen("holes.out","w",stdout);
    bool isBlack[NMAX+5];
    int m,stay;
    int u,v,k,delta;
    cin>>n>>m;
    rep(i,1,n)
        cin>>isBlack[i];
    rep(i,1,n){
        cin>>h[2*i-1].w;
        h[2*i]=h[2*i-1];
    }
    rep(i,1,n){
        cin>>stay;
        createEdge(2*i-1,2*i,stay); //2*i-1为i的黑状态，2*i是白
        createEdge(2*i,2*i-1,0);
    }
    rep(i,1,m){
        cin>>u>>v>>k;
        if(isBlack[u]==isBlack[v]){
            createEdge(2*u-1,2*v,k);
            createEdge(2*u,2*v-1,k);
        } else {
            delta=abs(h[2*u].w-h[2*v].w);
            createEdge(2*u-1,2*v-1,k+delta);
            createEdge(2*u,2*v,(k-delta>0 ? k-delta : 0));
        }
    }
    int start=isBlack[1]?1:2;
    dijkstra(start);
    cout<<min(h[2*n].dis,h[2*n-1].dis)<<endl;
}
