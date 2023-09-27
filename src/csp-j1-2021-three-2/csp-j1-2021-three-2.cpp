// （矩形计数）平面上有n个关键点，求有多少个四条边都和x轴或者y轴平行的矩形，
// 满足四个顶点都是关键点。给出的关键点可能有重复，但完全重合的矩形只计一次。

#include <iostream>

using namespace std;

struct point{ // 平面上的一个点
	int x,y,id; // id标识点的编号
};

bool equals(point a, point b){ // 判断2个点是否相等
	return a.x == b.x && a.y == b.y;
}

bool cmp(point a,point b){
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

void sort(point A[],int n){ // 冒泡排序
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			if(cmp(A[j],A[j - 1])){
				point t = A[j];
				A[j] = A[j - 1];
				A[j - 1] = t;
			}
		}
	}
}

// 用于去除数组中的重复点，并返回去重后的点个数。
int unique(point A[],int n){
	int t = 0;
	for(int i = 0; i < n;i++){
		if(!equals(A[i],A[i-1])){
			A[t++] = A[i];	
		}
	}
	return t;
}

// 二分查找,用于在已排序的点数组中查找给定的点。
bool binary_search(point A[],int n,int x,int y){
	point p;
	p.x = x;
	p.y = y;
	p.id = n;

	int a = 0, b = n - 1;
	while(a < b){
		int mid = (a+b)/2;
		if(cmp(A[mid],p))
			a = mid + 1;
		else
			b = mid;
	}
	return equals(A[a],p);
}

// 用于存储输入的关键点。
const int MAXN = 1000;
point A[MAXN];

int main(){
	int n; // 读取输入的关键点个数 n。
	cin >> n;
	// 读取输入的关键点坐标和编号，并存入点数组 A。
	for(int i = 0;i < n; i++){ 
		cin >> A[i].x >> A[i].y;
		A[i].id = 1;
	}
	// 对点数组 A 进行排序，排序规则为先按 x 坐标递增排序，若 x 坐标相同则按 y 坐标递增排序。
	sort(A,n);
	n = unique(A,n); // 对排序后的点数组 A 进行去重，得到去重后的点个数 n。
	int ans = 0; // 定义变量 ans 用于记录满足条件的矩形个数，初始化为0。
	// 遍历所有可能的点对，即遍历所有的矩形的两个顶点。
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n;j++){
			if(A[i].x < A[j].x && A[i].y<A[j].y&&
					binary_search(A,n,A[i].x,A[j].y)&&
					binary_search(A,n,A[j].x,A[i].y)){
				ans++; // 找到一个满足条件的矩形
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

