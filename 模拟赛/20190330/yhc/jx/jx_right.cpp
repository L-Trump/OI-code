#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define NMAX 1000000
using namespace std;
long long a[NMAX+5], f[NMAX+5][4][2], n;

int main()
{
    freopen("jx.in","r",stdin);
    freopen("jx.out","w",stdout);
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++) //这里区间最大值是3，所以就从1到3
        {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
            f[i][j][1] = max(max(f[i - 1][j - 1][1], f[i - 1][j - 1][0]), f[i - 1][j][1]) + a[i];
            //转移方程
        }
    cout<<max(f[n][3][0], f[n][3][1])<<endl; //最后记得比较一下末尾的两个状态
    return 0;
}
