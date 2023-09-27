#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const long long minNum = -1e18;

int n, m;
long long gridValue[1005][1005]; // 二维数组，存储每个格子中的值
long long memorizationTable[1005][1005][2]; // 记忆化表，存储计算结果

inline long long maxNum(long long p, long long q, long long r) {
    return p > q ? (p > r ? p : r) : (q > r ? q : r); // 函数，计算三个值的最大值
}

long long dfs(int x, int y, int from) {
    if (x < 1 || x > n || y < 1 || y > m) {
	    return minNum; // 如果格子越界，返回 minNum
    }

    if (memorizationTable[x][y][from] != minNum){
	    return memorizationTable[x][y][from]; // 如果结果已记忆，返回存储的结果
    } 
    
    if (from == 0){
        memorizationTable[x][y][from] = maxNum(dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + gridValue[x][y];
    }else{
	    memorizationTable[x][y][from] = maxNum(dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + gridValue[x][y];
    }
    
    return memorizationTable[x][y][from]; // 返回当前格子和方向的计算结果
}

int main() {
    ifstream fin("number.in"); // 打开输入文件以供读取
    ofstream fout("number.out"); // 打开输出文件以供写入

    fin >> n >> m; // 读取方格的行数 n 和列数 m
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++) {
            fin >> gridValue[i][j]; // 读取每个格子的值
            memorizationTable[i][j][0] = memorizationTable[i][j][1] = minNum; // 初始化记忆化表为 minNum
        }
    }
    memorizationTable[1][1][0] = memorizationTable[1][1][1] = gridValue[1][1]; // 设置左上角格子的初始值

    fout << dfs(n, m, 1) << endl; // 计算并写入最大和到输出文件
    fin.close(); // 关闭输入文件
    fout.close(); // 关闭输出文件
    return 0; // 返回 0 表示执行成功
}
