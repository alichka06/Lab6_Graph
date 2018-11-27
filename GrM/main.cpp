#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

int main()
{
    GrM a;
    string FN;
    bool flag;
    time_t timer;
    cout << "Alina Fedyna. Lab 2-5. Graphen(GrM)\n";
    do
    {
        cout << "Enter path to input file: ";
        cin >> FN;
        timer=clock();
        flag=a.in(FN);
        double seconds = double(clock() - timer) / CLOCKS_PER_SEC;
        double miliseconds = seconds * 1000;
        cout << "Time for reading: " << seconds << "s, " << miliseconds << "ms.\n";
    } while (!flag);

    cout << "Enter path to output file: ";
    cin >> FN;

    ListV ans;
    timer=clock();
    if (a.oneArc(ans))
        ansOut(&ans, FN, 1, timer);
    else
        ansOut(a.dfs(), FN, 2, timer);
    return 0;
}

void ansOut(ListV* a, string FN, int k, time_t timer)
{
    double seconds = double(clock() - timer) / CLOCKS_PER_SEC;
    double miliseconds = seconds * 1000;
    cout << "Time for processing: " << seconds << "s, " << miliseconds << "ms.";
    ofstream f(FN);
    if (k==1) f << "-1\n";
    else f << a->nV << "\n";
    for (int i=0; i< a->nV; ++i)
        f << a->l[i] << " ";
    f.close();
}
