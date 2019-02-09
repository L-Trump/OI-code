#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
//这段struct用来记录priority_queue自定义用法之一
struct cmp{
    bool operator()(const int& a,const int& b){
      return a>b;
    }
};
std::priority_queue<int,std::vector<int>,cmp> heap;
//std::priority_queue<int,std::vector<int>,std::greater<int>> heap;
//两个同义
int main(){
    int n,opt,k;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    rep(i,1,n){
        cin>>opt;
        if(opt==1){
            cin>>k;
            heap.push(k);
        }
        if(opt==2) cout<<heap.top()<<endl;
        if(opt==3) heap.pop();
    }
    return 0;
}
