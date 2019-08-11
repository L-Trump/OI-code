#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int Const[2][10]={{0,0,-2,-1,1,2,2,1,-1,-2},{0,0,1,2,2,1,-1,-2,-2,-1}};
ll DP[21]={1};
bool mark[25][25];
int main() {
    int nx,ny,hx,hy;
    cin>>nx>>ny>>hx>>hy;
    for(int i=1;i<=9;i++)
        if(hx+Const[0][i]>=0&&hx+Const[0][i]<=nx&&hy+Const[1][i]>=0&&hy+Const[1][i]<=ny)
            mark[hx+Const[0][i]][hy+Const[1][i]]=1;
    for(int i=0,j;i<=nx;i++)
        for(DP[0]*=!mark[i][0],j=1;j<=ny;j++){
            DP[j]+=DP[j-1];
            DP[j]*=!mark[i][j];
        }
    cout<<DP[ny];
    return 0;
}
