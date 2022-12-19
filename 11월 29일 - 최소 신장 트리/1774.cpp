#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include<cmath>

using namespace std;

typedef tuple<double, int, int> tp;
vector<pair<int, int>> god;
vector<int> parent;

int findParent(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }

    if (parent[px] < parent[py]) {
        parent[px] += parent[py];
        parent[py] = px;
    }
    else {
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

float kruskal(int v, vector<tp>& dist) {
    float sum = 0;
    int n1, n2;
    double d;
    for (int i = 0; i < dist.size(); i++)
    {
        n1 = get<1>(dist[i]);
        n2 = get<2>(dist[i]);
        d = get<0>(dist[i]);
        if (unionNodes(n1, n2)) {
            sum += d;
        }
    }
    return sum;
}

int main() {
    int n, m, x, y;
    cin >> n >> m;

    vector<tp> dist;
    parent.assign(n + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        god.push_back({ x, y });
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        unionNodes(x, y);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dx = pow(god[i].first - god[i].second, 2);
            double dy = pow(god[j].first - god[j].second, 2);
            dist.push_back({ sqrt(dx + dy), i, j });
        }
    }

    sort(dist.begin(), dist.end());
    printf("%.2f", kruskal(m, dist));
    return 0;
}