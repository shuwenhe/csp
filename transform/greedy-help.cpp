#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std; 

const int maxN = 12, maxM = maxN * 4;

struct edge {
    edge* next; // 指向下一个边的指针
    int t; // 目标节点的标识值
} *v[maxN], e[maxM];

int n;
int ec; // 用于追踪边的计数器，用于确定在数组 e 中的下一个可用位置。
int mat[maxN]; // 存储匹配结果，即哪些节点与哪些节点相匹配
int stack[maxN]; // 存储节点的标识,需要进一步处理的节点标识
int s[maxN][2]; // 存储节点的关联信息
int deg[maxN]; // 每个节点的度数（与之相连的边数）
bool nuked[maxN]; // 标记节点是否已被处理

inline void addEdge(int a, int b) { // 创建一条从节点 a 到节点 b 的边，并且也创建了一条从节点 b 到节点 a 的边，从而模拟了无向边的存在。这样的连接方式用于构建无向图，其中节点之间的边没有方向性，可以同时在两个方向上传递信息。
    e[++ec].next = v[a];//将边数组 e 中的下一个可用位置的 next 指针指向当前节点 a 对应的链表的头部，即将节点 a 连接到这条边上。
    v[a] = e + ec; // 将节点 a 对应的链表头指针 v[a] 指向刚刚添加的边，这样就将节点 a 与节点 b 连接起来。
    v[a]->t = b; // 表示将节点 a 与节点 b 相连的边的目标节点设置为 b，这样就记录了边 a 到 b。

    e[++ec].next = v[b]; // 将边数组 e 中的下一个可用位置的 next 指针指向节点 b 对应的链表的头部，即将节点 b 连接到这条边上。
    v[b] = e + ec; // 将节点 b 对应的链表头指针 v[b] 指向刚刚添加的边，这样就将节点 b 与这条边连接起来。确保这是一条双向边，因为前面已经添加了一条从节点 a 到节点 b 的边。
    v[b]->t = a; // // 表示将节点 b 与节点 a 相连的边的目标节点设置为 a，这样就记录了边 a 到 b。

    ++deg[b]; // 更新了节点 b 的度数 deg 每当一条从节点 a 到节点 b 的边被添加时，节点 b 的度数就会增加 1，因为它与一条新的边相连。这条边是从节点 a 发出的，因此节点 a 的度数不需要增加。
    mat[b] = a; // 设置新添加的边的目标节点为 a，表示这条边从节点 b 指向节点 a。 将节点 a 设置为节点 b 的邻接节点
}

void init() { // 初始化图和相关数据结构
    ifstream fin("transform.in");
    fin >> n;

    int i, d, t1, t2;

    for (i = 1; i <= n; ++i) {
        fin >> d;

        t1 = i + d;
        if (t1 > n){
		t1 -= n;
	} 

        t2 = i - d;
        if (t2 < 1){
		t2 += n;
	} 

        if (t1 < t2){
		s[i][0] = t1;
		s[i][1] = t2;
	}else{
		s[i][0] = t2;
		s[i][1] = t1;
	}

	// 将它们的标识增加 n 来确保它们与原始节点的标识不冲突。
        addEdge(i, s[i][1] += n); // addEdge函数的第一个参数i表示边的起始节点，而第二个参数s[i][1] += n和s[i][0] += n则是边的终止节点。
        addEdge(i, s[i][0] += n); // 节点 i 被连接到了两个不同的节点，分别是 s[i][0] + n 和 s[i][1] + n。
        deg[i] = 2;
    }

    fin.close();
}

void noAnswer() { // 在无解时输出 "No Answer" 并退出程序
	printf("No Answer\n"); 
	exit(0); 
}

inline void match(int i,int j) {
	mat[i] = j; 
	mat[j] = i; 
}

void prune() { // 修剪不可能的匹配，将无法匹配的节点标记为无解
	int stop = 0,i,j; // ，以及两个迭代变量 i 和 j。 

	for (i = 1;i <= n; i++) { 
		if (deg[i + n] == 0){ // 如果节点 i 对应的度数为0，表示该节点无法匹配任何节点，因此调用 noAnswer() 函数，表示无解。
			noAnswer(); 
		}else if(deg[i + n] == 1){//如果节点 i 对应的度数为1，表示该节点只有一个可能的匹配，因此将节点 i 的标识（即 i + n）添加到 stack 数组中，以便后续处理。
			stack[++stop] = i + n; 
		}
	}

	while(stop){ // 处理 stack 中的节点，直到 stack 为空为止
		i = stack[stop--]; // 从 stack 中取出一个节点标识，并减小 stop 计数器,下一个要处理的节点.
		nuked[i] = true; // 标记节点 i 为已处理,避免重复处理.
		// 在与节点 i 相连的边中找到一个可以匹配的节点 j。
		for (edge *e=v[i];e;e=e->next) { // 寻找节点 i 可以匹配的节点 j，即通过遍历与节点 i 相连的边，找到未被标记的节点。
			j = e->t; // 获取当前边 e 的目标节点标识，即节点 i 通过边 e 连接到的另一个节点 j。
			if (!nuked[j]){ // 已经找到了一个未处理的与节点 i 相连的节点 j。
				break; // 退出循环
			} 
		} 

		match(i,j); // 将节点 i 与节点 j 匹配。
		i = j; // 更新 i 为 j，继续寻找节点 j 可以匹配的下一个节点。
		nuked[i] = true; // 标记节点 j 为已处理。

		for (edge *e=v[i];e;e=e->next) { // 用于遍历与节点 i 相关联的所有边。v[i] 表示与节点 i 相关联的边的链表的头部。 
			j = e->t; // 将变量 j 设置为边 e 的目标节点。也就是说，j 是节点 i 通过边 e 连接到的另一个节点。
			if (!nuked[j]) { // 用于检查节点 j 是否已经被标记为已处理。如果节点 j 尚未被处理（即 nuked[j] 为假），则执行以下操作： 
				deg[j]--; // 将节点 j 的度数减1。度数表示与节点相关联的边的数量，因此减少度数表示节点 j 失去了一条连接。
				if(deg[j] == 0){ // 检查节点 j 的度数是否变为0。如果节点 j 的度数变为0，意味着节点 j 无法再与其他节点匹配，因此调用 noAnswer() 函数，表示无法找到有效的匹配。
					noAnswer(); 
				}else if(deg[j] == 1){ // 如果节点 j 的度数变为1，表示节点 j 只有一条可能的匹配。在这种情况下，将节点 j 的标识添加到 stack 数组中，以便稍后处理。
					stack[++stop] = j; 
				} 
			} 
		} 
	} 
}

// 深度优先搜索，它以节点 i 为起点，递归地探索图中的路径，并在需要时尝试匹配节点。这是解决二分图匹配问题的关键步骤之一，它会不断地深入探索图中的节点，直到找到匹配或无法继续探索为止。
void dfs(int i,bool s) { // 深度优先搜索算法，用于查找匹配 i 是当前正在考虑的节点，s 是一个布尔值，表示是否要尝试匹配节点 i。
	nuked[i] = true; // 将节点 i 标记为已处理，以避免重复处理。
	int j; // 存储相邻节点的标识
	for (edge *e=v[i];e;e=e->next) { // 遍历与节点 i 相关联的所有边。v[i] 表示与节点 i 相关联的边的链表的头部。
		j = e->t; // 将变量 j 设置为边 e 的目标节点。也就是说，j 是节点 i 通过边 e 连接到的另一个节点。
		if(!nuked[j]){ // 用于检查节点 j 是否已经被标记为已处理。如果节点 j 尚未被处理（即 nuked[j] 为假），则执行以下操作：
			dfs(j,!s); // 递归调用 dfs 函数，将节点 j 作为新的当前节点，并将 s 取反。这表示在深度优先搜索中继续处理节点 j，并尝试匹配它，如果 s 为真的话。
			if(s){// 如果 s 为真，表示在深度优先搜索中需要尝试匹配节点 i 和节点 j
				match(i,j); // 如果需要尝试匹配，调用 match 函数将节点 i 与节点 j 匹配。这表示它们之间建立了一条匹配。
			}
			break; // 出当前的 for 循环，因为已经找到了一个未处理的相邻节点 j 进行递归。
		} 
	} 
}

void solve() { 
	prune(); 
	for (int i=1;i <= n;i++) { 
		if (!nuked[i]){
			dfs(i,true); 
		} 
	}
}

void print() {
    ofstream fout("transform.out");

    int i;
    for(i = 1; i < n; i++){
	    fout << mat[i] - n - 1 << " ";
    }

    fout << mat[i] - n - 1 << "\n";
    fout.close();
}

int main() {
    init();
    solve();
    print();
    return 0;
}
