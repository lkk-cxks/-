#include <bits/stdc++.h>

using namespace std;

class Object
{
public:
    int p;   //价值
    int w;   //重量
    int id;  //物品的id
};
//物品数量 背包容量  当前价值 当前重量 最优值  总重量 总价值
int n, c, cp, cw, bestp, total_w, total_p;
int x[100], best_x[100];    //记录暂时选取状态  记录最优选取状态
Object O[100];   //存储物品的数组
void Input()
{
    cout<<"请输入物品个数和背包容量：";
    cin>>n>>c;
    cout<<"请输入每个物品的价值和重量："<<endl;
    for(int i = 1; i <= n; ++i)
    {
        cin>>O[i].p>>O[i].w;
        O[i].id = i;
    }
}
bool cmp(const Object &a, const Object &b)
{
    return a.p / a.w > b.p / b.w;
}
void Initilize()
{
    cp = cw = total_w = total_p = bestp = 0;
    for(int i = 1; i <= n; ++i)
    {
        total_p += O[i].p;
        total_w += O[i].w;
    }
    //依照物品单位重量价值排序
    sort(O + 1, O + n + 1, cmp);
    //for(int i = 1; i <= n; ++i)
        //cout << O[i].id << endl;
}

//计算up值
int Bound(int i)
{
    int temp_cw = c - cw;
    int temp_cp = cp;
    while(i <= n && temp_cw >= O[i].w)
    {
        temp_cw -= O[i].w;
        temp_cp += O[i].p;
        ++i;
    }
    //装满背包
    if(i <= n)
        temp_cp += O[i].p / O[i].w * temp_cw;
    return temp_cp;


}

void Backtrack(int i)
{
    if(i > n)
    {
        bestp = cp;
        for(int i = 1; i <= n; ++i)
            best_x[i] = x[i];
        return;
    }
    if(cw + O[i].w <= c)
    {
        x[O[i].id] = 1;
        cw += O[i].w;
        cp += O[i].p;
        Backtrack(i + 1);
        cp -= O[i].p;
        cw -= O[i].w;
        x[O[i].id] = 0;
    }
    //向右求解的约束条件
    if(Bound(i + 1) > bestp)
    {
        x[O[i].id] = 0;
        Backtrack(i + 1);
    }
}



void OutPut()
{
    cout<<"bestp = "<<bestp<<endl;;
    cout<<"选取的物品为 : ";
    for(int i = 1; i <= n; ++i)
    {
        if(best_x[i] == 1)
            cout << i << " ";
    }
}
int main()
{
    Input();
    Initilize();
    Backtrack(1);
    OutPut();
}



