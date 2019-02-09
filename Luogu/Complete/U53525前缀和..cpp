#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    int n;
    int a[105]={};
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    rep(i,1,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
