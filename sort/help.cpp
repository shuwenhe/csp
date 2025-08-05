#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct node {
    int id;
    int num;
};

node a[8010];
int b[8010];
int n, q;

void change(int pos) {
    while (pos > 1) {
        if (a[pos].num == a[pos - 1].num && a[pos].id > a[pos - 1].id) break;
        if (a[pos].num > a[pos - 1].num) break;
        swap(a[pos], a[pos - 1]);
        b[a[pos].id] = pos;
        pos--;
    }
    while (pos < n) {
        if (a[pos].num == a[pos + 1].num && a[pos].id < a[pos + 1].id) break;
        if (a[pos].num < a[pos + 1].num) break;
        swap(a[pos], a[pos + 1]);
        b[a[pos].id] = pos;
        pos++;
    }
}

bool cmp(node a, node b) {
    if (a.num == b.num){
        return a.id < b.id;
    }else{
        return a.num < b.num;
    } 
}

int main() {
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    fin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fin >> a[i].num;
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        b[a[i].id] = i;
    }

    while (q--) {
        int op, x, v;
        fin >> op;
        if (op == 1) {
            fin >> x >> v;
            a[b[x]].num = v;
            change(b[x]);
            for (int i = 1; i <= n; i++) {
                b[a[i].id] = i;
            }
        }else{
            fin >> x;
            fout << b[x] << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
