#include <bits/stdc++.h>
#include "graph.h"

using namespace std;
/*
void dfs1(int v, int used[], int k)
{
    used[v]=k;
    for (int i=1; i<=E[i][0]; ++i)

}*/

int main()
{
    GrM a;
    string FN;
    bool flag;
    do
    {
        cout << "Enter path to input file";
        cin >> FN;
        flag=a.in(FN);
    } while (!flag);

    /*int * comp;
    int used[n]={0};
    int k=0;
    for (int i=0; i<n; ++i)
    {
        if (!used[i])
    }*/



    return 0;
}
