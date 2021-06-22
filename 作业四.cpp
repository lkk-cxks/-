#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=0x3f3f3f3f;
int a[maxn],n;
void mergesort(int arr[],int L,int mid,int R){
	int temp[maxn];
	int i=0,p1=L,p2=mid+1;
	while(p1<=mid&&p2<=R){
		if(arr[p1]<arr[p2])
			temp[i++]=arr[p1++];
		else temp[i++]=arr[p2++];
	}
	while(p1<=mid){
		temp[i++]=arr[p1++];
	}
	while(p2<=R){
		temp[i++]=arr[p2++];
	}
	for(int i=0;i+L<=R;i++){
		arr[L+i]=temp[i];
	}
}
void merge(int arr[],int L,int R){
	if(L==R) return ;
	int mid=(R+L)/2;
	merge(arr,L,mid);
	merge(arr,mid+1,R);
	mergesort(arr,L,mid,R);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	merge(a,1,n);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
}
