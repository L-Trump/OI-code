#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    string com;
    int X,Y,t,times,len;
    X=Y=0;
    cin>>com;
    len=com.length();
    for(int i=0;i<len;i++){
        if(com[i]=='W') X--;
        if(com[i]=='E') X++;
        if(com[i]=='N') Y++;
        if(com[i]=='S') Y--;
    }
    cin>>t;
    times=t/len;
    t%=len;
    X*=times;Y*=times;
    for(int i=0;i<t;i++){
        if(com[i]=='W') X--;
        if(com[i]=='E') X++;
        if(com[i]=='N') Y++;
        if(com[i]=='S') Y--;
    }
    cout<<X<<" "<<Y<<endl;
}
