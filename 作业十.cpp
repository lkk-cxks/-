#include <bits/stdc++.h>

using namespace std;

class Object
{
public:
    int p;   //��ֵ
    int w;   //����
    int id;  //��Ʒ��id
};
//��Ʒ���� ��������  ��ǰ��ֵ ��ǰ���� ����ֵ  ������ �ܼ�ֵ
int n, c, cp, cw, bestp, total_w, total_p;
int x[100], best_x[100];    //��¼��ʱѡȡ״̬  ��¼����ѡȡ״̬
Object O[100];   //�洢��Ʒ������
void Input()
{
    cout<<"��������Ʒ�����ͱ���������";
    cin>>n>>c;
    cout<<"������ÿ����Ʒ�ļ�ֵ��������"<<endl;
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
    //������Ʒ��λ������ֵ����
    sort(O + 1, O + n + 1, cmp);
    //for(int i = 1; i <= n; ++i)
        //cout << O[i].id << endl;
}

//����upֵ
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
    //װ������
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
    //��������Լ������
    if(Bound(i + 1) > bestp)
    {
        x[O[i].id] = 0;
        Backtrack(i + 1);
    }
}



void OutPut()
{
    cout<<"bestp = "<<bestp<<endl;;
    cout<<"ѡȡ����ƷΪ : ";
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



