#include<iostream>
#include<math.h>  //�������
#include<time.h>  //��������ʱ��
#include<fstream>  //�ļ�����
#include<algorithm>  //����
 
using namespace std;
#define MAX 0x3f3f3f3f  //���������
#define M 99999
 
struct point {
  double x, y;
}p[M];
 
int a[M];// �������������
 
int cmpx(const point& a, const point& b)  //��������
{  
  return a.x < b.x;
}
 
int cmpy(int &a, int &b)   //��������
{
  return p[a].y < p[b].y;
}
 
inline double min(double a, double b)   //��������ֵ�н�С��
{
	return a < b ? a : b;
}
inline double dist(const point& a, const point& b)
{
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double closeset(int low, int high)
{
	if (low == high)   
		return MAX;
	if (low + 1 == high)  //��n=2����������֮��ľ���
		return dist(p[low], p[high]);
	int mid = (low + high)>>1;  //����һλ���൱�ڳ���2�������Ƶ������ٶȸ��죬��ʹ��(low+high)/2���м�λ���������
	double ans = min(closeset(low, mid), closeset(mid+1, high));  //�ݹ����������С����
	int i, j, c = 0;
	for (i = low; i <= high; i++) //ͳ����Щ��λ���������ڣ�����¼
	{
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			a[c++] = i;
	}
	sort(a, a + c, cmpy);
	for(i = 0; i < c; i++)//�Ƚ�s1�������ڵĵ��s2�������ڵĵ�ľ����Ƿ������С��������С�Ե�
	{
		int k = i+7 > c ? c : i+7;  
		for (j = i+1; j < k; j++)
		{
			if (p[a[j]].y - p[a[i]].y > ans)  //���λ����λ������ĵ�ľ������anx��������һ��ѭ��
				break;
			ans = min(dist(p[a[i]], p[a[j]]), ans);   //�����������С�����������ԣ���ѡ����С�ĵ�
		}
	}
	return ans;
}
 
int main()
{
	clock_t start;
	double totaltime;
	start=clock();
	int n;  //һ�����ٸ���
	double dmin;
	ifstream read_in;
	read_in.open("close.txt");
	read_in >> n;
	cout<<"�������Ϊ��"<<n<<endl;
	cout<<"�������Ϊ��"<<endl;
	for(int i=0;i<n;i++)  //ѭ�������ļ�
	{
		cout<<"p"<<i+1<<":";
		read_in>>p[i].x>>p[i].y;
		cout<<p[i].x<<" "<<p[i].y<<endl;
	}
	sort(p,p+n,cmpx); //����x������
	dmin=closeset(0, n-1);
	cout<<"����ľ����ǣ�"<<dmin<<endl;
	clock_t end=clock();
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"��������ʱ���ǣ�"<<totaltime<<endl;
	return 0;
}
