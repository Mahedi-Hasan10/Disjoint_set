/*
     Author : Mahedi-Hasan10
     Date : 11-04-2023
     Topic: Cycle Detection using Disjoint set
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edge_list;
vector<int> parent;

int findParent(int x)
{
    if (parent[x] == -1)
    {
        return x;
    }
    return findParent(parent[x]);
}

void unionOperation(int a, int b)
{
    int parentA = findParent(a);
    int parentB = findParent(b);
    parent[b] = a;
}
int main()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n, -1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    bool cycle = false;
    for (int i = 0; i < edge_list.size(); i++)
    {
        pair<int, int> pr = edge_list[i];

        int a = pr.first;
        int b = pr.second;

        int parentA = findParent(a);
        int parentB = findParent(b);
        if (parentA == parentB)
        {
            cycle = true;
            break;
        }
        else
        {
            unionOperation(a, b);
        }
    }

    if (cycle == true)
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";
    return 0;
}

/*
4 4

2 3
0 1
0 2
1 2
*/