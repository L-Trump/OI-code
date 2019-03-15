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
struct hole{
    bool isBlack;
    int w;
    int dis;
    hole(){
        w=isBlack=0;
        dis=1000000007;
    }
} h[2*NMAX+5];
struct edge{
    int to;
    int waste;
};
vector<edge> e[2*NMAX+5];
inline void createEdge(int a, int b, int s){
    edge c;
    c.to=b;
    c.waste=s;
    e[a].push_back(c);
}
bool isExist(int a, queue<int> t){
    int temp;
    while(!t.empty()){
        temp=t.front();
        t.pop();
        if(temp==a) return true;
    }
    return false;
}
ll spfa(int root,int last){
    queue<int> q1,q2,emptyq;
    int now=1;
    q1.push(root);
    h[root].dis=0;
    while(!q1.empty()){
        while(!q1.empty()){
            root=q1.front();q1.pop();
            //cerr<<"root is "<<root<<endl;
            //cerr<<"has edges number "<<e[root].size()-1<<endl;
            rep(i,0,(int)e[root].size()-1){
                int waste=e[root][i].waste;
                int to=e[root][i].to;
               // cerr<<root<<" has edges to "<<to<<endl;
                int delta=abs(h[to].w-h[root].w)*(h[root].isBlack-h[to].isBlack)*now;
               // cerr<<"delta is "<<delta<<endl;
                waste+=delta;
                if(waste<0) waste=0;
               // cerr<<"waste is "<<waste<<endl;
                if(h[to].dis>waste+h[root].dis){
                    //if(!isExist(to,q2)){
                        q2.push(to);
                 //       cerr<<to<<" has pushed to q2"<<endl;
                    //}
                    h[to].dis=waste+h[root].dis;
                   // cerr<<"dis to "<<to<<" become "<<waste+h[root].dis<<endl;
                }
            }
        }
        now*=-1;
        q1=q2;
        q2=emptyq;
        //cerr<<q1.size()<<endl;
    }
    return h[last].dis;
}
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("holes.in","r",stdin);
    freopen("holes.out","w",stdout);
    int n,m,stay;
    cin>>n>>m;
    rep(i,1,n){
        cin>>h[i].isBlack;
        h[2*NMAX-i].isBlack=h[i].isBlack;
    }
    rep(i,1,n){
        cin>>h[i].w;
        h[2*NMAX-i].w=h[i].w;
    }
    rep(i,1,n){
        cin>>stay;
        createEdge(i,2*NMAX-i,stay);
    }
    rep(i,1,m){
        int u,v,k;
        cin>>u>>v>>k;
        createEdge(u,v,k);
        createEdge(2*NMAX-u,v,k);
    }
    cout<<spfa(1,n)<<endl;
}
