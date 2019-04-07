#include <iostream>
#include <cstdio>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
char amap[55][55];
bool people[55][55]={},water[55][55]={};
int xd,yd;
queue<pair<int ,int> > cc,w,cct,wt; //cc和w记录人水位置，cct和wt记录下一轮的
int n,m,cnt=0;
void bfs(){ //宽搜
    bool isFound=false; //标记是否找到
    int x,y;
    pair<int,int> waterp,ccp; //处理用的那个水或人的节点
    while(!isFound&&!cc.empty()){
        cnt++; //每轮计数+1
        while(!w.empty()){ //这一轮的水没走完就继续处理
            waterp=w.front();w.pop();
            x=waterp.first;y=waterp.second;
            //下面是水的流法，边界内只能流向.也就是平原，并且没有流过
            //向四面尝试
            if(x+1<=n && amap[x+1][y]=='.' && !water[x+1][y]  ){
                wt.push(make_pair(x+1,y));
                //尝试成功就把水加到下一轮要尝试的队列里并在图上标记
                water[x+1][y]=1;
            }
            if(x-1>=1 && amap[x-1][y]=='.' && !water[x-1][y] ){
                wt.push(make_pair(x-1,y));
                water[x-1][y]=1;
            }
            if(y+1<=m && amap[x][y+1]=='.' && !water[x][y+1] ){
                wt.push(make_pair(x,y+1));
                water[x][y+1]=1;
            }
            if(y-1>=1 && amap[x][y-1]=='.' && !water[x][y-1] ){
                wt.push(make_pair(x,y-1));
                water[x][y-1]=1;
            }
        }
        //这一轮的水走完了，把下一轮拿上来
        swap(w,wt);

        while(!cc.empty()){//开始走人，基本一样
            ccp=cc.front();
            cc.pop();
            x=ccp.first;y=ccp.second;
            //人的条件是边界内走没有水没有石头并且没走过的地方
            if(x+1<=n && amap[x+1][y]!='X' && !water[x+1][y] && !people[x+1][y] ){
                cct.push(make_pair(x+1,y));
                people[x+1][y]=1;
            }
            if(x-1>=1 && amap[x-1][y]!='X' && !water[x-1][y] && !people[x-1][y] ){
                cct.push(make_pair(x-1,y));
                people[x-1][y]=1;
            }
            if(y+1<=m && amap[x][y+1]!='X' && !water[x][y+1] && !people[x][y+1] ){
                cct.push(make_pair(x,y+1));
                people[x][y+1]=1;
            }
            if(y-1>=1 && amap[x][y-1]!='X' && !water[x][y-1] && !people[x][y+-1] ){
                cct.push(make_pair(x,y-1));
                people[x][y-1]=1;
            }
        }
        swap(cc,cct);
        //人也走完了
        if(people[xd][yd]==1) isFound=1; //如果已经到重点了就标记
    }
    //跳出while后要么是找到了要么是没有地方走了
    //所以下面就可以输出答案了
    if(!isFound) cout<<"ORZ hzwer!!!"<<endl; else cout<<cnt<<endl;

}
void readMap(){
    cin>>n>>m; //读入行数和列数
    rep(i,1,n)
      rep(j,1,m){
        cin>>amap[i][j]; //读地图
        if(amap[i][j]=='D'){xd=i;yd=j;} //记录终点的坐标
        if(amap[i][j]=='*'){
            w.push(make_pair(i,j)); //w队列为当前水的坐标
            water[i][j]=1; //地图标记水是否流过
        }
        if(amap[i][j]=='S'){
            cc.push(make_pair(i,j)); //cc为人的坐标队列
            people[i][j]=1; //标记人是否走过
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("sliker.in","r",stdin);
    freopen("sliker.out","w",stdout);
    readMap();
    bfs();
}
