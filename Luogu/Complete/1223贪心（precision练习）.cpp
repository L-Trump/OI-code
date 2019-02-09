#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
//using namespace std;
typedef long long ll;

struct node{
    int v,rank;
    node(){
      v=rank=0;
    }
} t[10005];

bool cmp(node a, node b){
    return a.v<b.v;
}

int main(){
    int n;
    double time=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    rep(i,1,n) {
        cin>>t[i].v;
        t[i].rank=i;
    }
    std::sort(t+1,t+1+n,cmp);
    rep(i,1,n){
        cout<<t[i].rank<<" ";
    }
    cout<<endl;
    rep(i,1,n){
        time+=t[i].v*(n-i);
    }
    //time/=n;
    //cout.setf(std::ios::fixed)
    cout<<std::fixed<<std::setprecision(2)<<time/n<<endl;
    return 0;
}
