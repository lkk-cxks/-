#include <bits/stdc++.h>

using namespace std;

int m;      //ɫ��
int pointnum;  //����
int edgenum;  //����
int sum = 0;  //������������ɫ��������
int Graph[100][100];  //����֮��Ĺ�ϵ  1���������� 0������Ͽ�
int x[100];      //�洢�������ɫ���


void InPut()
{
    int pos1, pos2;  //��ʼ��
    cout<<"�������ĸ�����ɫ��(p m)��";
    cin>>pointnum>>m;

    cout<<"������ߵĸ���: ";
    cin>>edgenum;
    memset(Graph, 0, sizeof(Graph));

    cout<<"����ߵ���ʼ����Ϣ(��� �յ�)��"<<endl;
    for(int i = 1; i <= edgenum; ++i)
    {
        cin>>pos1>>pos2;
        Graph[pos1][pos2] = Graph[pos2][pos1] = 1;
    }
}

//�жϵ�ǰ�����ɫ�Ƿ�Ϸ��Ϸ�, i ���ǵݹ������Ҳ�����Ѿ���ɫ�Ľڵ�����
bool IsOk(int i)
{
    for(int j = 1; j < i; ++j)
        //���������ͨ��������Χ�����ɫ��ͬ���ͽ����жϣ�������ǰ����ɫѡ�񲻺Ϸ���
        if(Graph[i][j] == 1 && x[j] == x[i])
            return false;
    return true;
}

//���Ĵ���
void BackTrack(int i)
{
    if(i > pointnum)
    {
        sum += 1;
        cout<<"���� "<<sum<<"  :";
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
   cout<<"һ���� "<<sum<<" �ֻ�ɫ����"<<endl;
}
int main()
{
    InPut();
    BackTrack(1);
    OutPut();
}


