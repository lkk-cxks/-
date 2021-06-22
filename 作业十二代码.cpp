#include <bits/stdc++.h>

using namespace std;

int m;      //色数
int pointnum;  //点数
int edgenum;  //边数
int sum = 0;  //符合条件的着色方案数量
int Graph[100][100];  //各点之间的关系  1：两点连接 0：两点断开
int x[100];      //存储各点的着色情况


void InPut()
{
    int pos1, pos2;  //起始点
    cout<<"请输入点的个数和色数(p m)：";
    cin>>pointnum>>m;

    cout<<"请输入边的个数: ";
    cin>>edgenum;
    memset(Graph, 0, sizeof(Graph));

    cout<<"输入边的起始点信息(起点 终点)："<<endl;
    for(int i = 1; i <= edgenum; ++i)
    {
        cin>>pos1>>pos2;
        Graph[pos1][pos2] = Graph[pos2][pos1] = 1;
    }
}

//判断当前点的着色是否合法合法, i 就是递归层数，也表明已经着色的节点索引
bool IsOk(int i)
{
    for(int j = 1; j < i; ++j)
        //两点如果相通并且与周围点的着色相同，就结束判断，表明当前的颜色选择不合法。
        if(Graph[i][j] == 1 && x[j] == x[i])
            return false;
    return true;
}

//核心代码
void BackTrack(int i)
{
    if(i > pointnum)
    {
        sum += 1;
        cout<<"方法 "<<sum<<"  :";
        for(int j = 1; j <= pointnum; ++j)
        {
           cout<<x[j];
        }
        cout<<endl;
        return;
    }
    else
    {
        for(int j = 1; j <= m; ++j)
        {
            x[i] = j;
            if(IsOk(i))
                BackTrack(i + 1);
            x[i] = 0;
        }
    }
}
void OutPut()
{
   cout<<"一共有 "<<sum<<" 种绘色方案"<<endl;
}
int main()
{
    InPut();
    BackTrack(1);
    OutPut();
}


