#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, C;
vector<int> cows;

bool canAssign(int maxWaitTime) {
    int buses = 1;
    int lastCowTime = cows[0];
    for (int i = 1; i < N; i++) {
        if (i - (buses - 1) * C >= C || cows[i] - lastCowTime > maxWaitTime) {
            buses++;
            lastCowTime = cows[i];
        }
    }
    return buses <= M;
}

int main() {
    ifstream fin("convention.in");
    ofstream fout("convention.out");

    fin >> N >> M >> C;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    int left = 0;
    int right = cows[N - 1] - cows[0];
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAssign(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}
