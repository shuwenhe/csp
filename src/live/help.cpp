#include <bits/stdc++.h>
using namespace std;

/*
1.获奖人数为k = max(1, int(p × w%))
2.选手的成绩均为不超过 600 的非负整数
思路：使用数组统计每个分值得分的人数
从大到小统计出k个人，最后一次循环对应的分值就是要求的获奖分数
*/
int n,w,x;
int a[610]; // 统计每个成绩出现的次数

int main(){
    ifstream fin("live.in");
    ofstream fout("live.out");
    fin >> n >> w; // n选手总数,w获奖率
    int k;//获奖人数
    int ans;//统计人数
    for(int i = 1;i <= n;i++){//读入n个人的分数，读一个算一个
        fin >> x; // 读取每个选手的成绩
        a[x]++;//统计每个分值对应的人数
        k = max(1,int(i * w / 100.0)); // 计算当前位置的计划获奖人数
        ans = 0;
        for(int j = 600;j >= 0;j--){//从最高分的人数向下统计出>=k个人
            if(ans + a[j] < k) {
                ans += a[j];
            }else{
                fout << j << " ";
                break;
            }
        }
    }
    fout<<"\n";

    fin.close();
    fout.close();
    return 0;
}
