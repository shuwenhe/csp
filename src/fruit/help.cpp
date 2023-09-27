#include <bits/stdc++.h>

#define INF 200010

using namespace std;


int main() {
    ifstream fin("fruit.in");  // 从文件 "fruit.in" 读取输入 12
    ofstream fout("fruit.out"); // 输出结果到文件 "fruit.out" 1 1 0 0 1 1 1 0 1 1 0 0

    int n;
    set<int> s1, s2; // 两个集合，分别存储元素的下标
    fin >> n; // 读取元素数量 n
    s1.clear(); // 清空集合 s1
    s2.clear(); // 清空集合 s2
    int q;
    for (int i = 1; i <= n; ++i) {
        fin >> q; // 读取输入元素 q
        if (q) s1.insert(i); // 若 q 非零，将当前下标 i 插入集合 s1
        else s2.insert(i);    // 若 q 为零，将当前下标 i 插入集合 s2
    }
    s1.insert(INF); // 在集合 s1 中插入 INF，用于防止集合为空
    s2.insert(INF); // 在集合 s2 中插入 INF，用于防止集合为空
    int nw = 0;
    bool p = *s1.begin() < *s2.begin() ? 0 : 1; // 根据两个集合的最小值确定 p 值，表示当前删的是哪个集合

    while (!p && s1.size() > 1 || p && s2.size() > 1) {
        if (!p) {
            nw = *s1.upper_bound(nw); // 找到集合 s1 中下一个大于 nw 的元素
            if (nw == INF) {
                nw = 0;
                p = *s1.begin() < *s2.begin() ? 0 : 1; // 若找不到下一个元素，重新确定 p 值
                fout << endl; // 换行
                continue;
            }
            fout << nw << ' '; // 输出 nw 并删除它
            s1.erase(nw);
            p = !p; // 切换到另一个集合
        } else {
            nw = *s2.upper_bound(nw);
            if (nw == INF) {
                nw = 0;
                p = *s1.begin() < *s2.begin() ? 0 : 1;
                fout << endl;
                continue;
            }
            fout << nw << ' ';
            s2.erase(nw);
            p = !p;
        }
    }
    fout << ""<<endl; // 输出最后一个果篮并换行
    while (s1.size() > 1) fout << *s1.begin() << endl, s1.erase(*s1.begin()); // 逐行输出 s1 剩余元素
    while (s2.size() > 1) fout << *s2.begin() << endl, s2.erase(*s2.begin()); // 逐行输出 s2 剩余元素

    return 0;
}
