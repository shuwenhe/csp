#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream fin("point.in");  // 打开输入文件
    ofstream fout("point.out");  // 打开输出文件

    int n, k;
    fin >> n >> k;  // 读取点的数量和参数 k
    int ans = 0;  // 用于记录最大可包含的点的数量

    vector<pair<int, int>> points(n);  // 存储点的坐标信息，使用 pair 存储 x 和 y 坐标
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;  // 读取点的坐标
        points[i] = {x, y};  // 将坐标存入 vector
    }

    sort(points.begin(), points.end());  // 根据 x 坐标排序

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));  // 动态规划数组dp[i]，表示以第i个点结尾的满足条件的最长序列长度。
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = j + 1;  // 以第i个点结尾并且加j个点能构成的序列的最大长度
            for (int t = 0; t < i; t++) { // 遍历已经处理过的点，t表示当前已经处理过的点的索引
                pair<int, int> &A = points[i];  // 当前点A的坐标
                pair<int, int> &B = points[t];  // 已处理过的点B的坐标
                if (A.second >= B.second) {  // 如果 A 点的 y 坐标大于等于 B 点的 y 坐标
                    int d = A.first - B.first + A.second - B.second - 1;  // 计算距离 d
                    if (j >= d) {  // 如果参数 j 大于等于距离 d
                        dp[i][j] = max(dp[i][j], dp[t][j - d] + d + 1);  // 更新 dp[i][j]，考虑包含当前点 A 的情况
                    }
                }
            }
            ans = max(ans, dp[i][j]);  // 更新最大包含数量
        }
    }
    fout << ans << endl;  // 输出结果到文件

    fin.close();  // 关闭输入文件
    fout.close();  // 关闭输出文件
    return 0;  // 返回 0 表示成功执行
}
