#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

GrM::~GrM()
{
    for (int i=0; i<n; ++i)
        delete [] E[i];
}

bool GrM:: in(string FN)
{
    ifstream f(FN);
    if (!f) return 0;
    int i, j;
    f >> n >> m;
    if (!init()) return 0;
    for (int k=0; k<m; ++k)
    {
        f >> i >> j;
        E[i][j]=1;
        ++deg[i];
    }
    f.close();
    return 1;
}

bool GrM:: init()
{
    for (int i=0; i<n; ++i)
    {
        E[i]=new (nothrow) int[n];
        if (E[i]==nullptr)
        {
            for (int j=0; j<i; ++j)
                delete [] E[j];
            return 0;
        }
        for (int j=0; j<n; ++j)
            E[i][j]=0;
    }
    return 1;
}

void GrM::out(string FN)
{
    ofstream f(FN);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
            cout << E[i][j] << " ";
        cout << "\n";
    }
    f << n << " " << m << "\n";
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (E[i][j]==1) f << i << " " << j << "\n";
    f.close();
}

bool GrM::oneArc(ListV& a)
{
    a.nV=0;
    a.l=new int [n];
    for (int i=0; i<n; ++i)
    {
        int k=0;
        for (int j=0; j<n; ++j)
            if (E[j][i]==1) ++k;
        if (k!=1) a.l[a.nV++]=i;
    }
    return (a.nV>0);
}

void GrM::dfsr(int v, ListV& L, bool* visited)
{
    visited[v]=1;
    for (int w=0; w<n; ++w)
        if (E[v][w] && !visited[w])
            dfsr(w,L,visited);
    L.l[L.nV++]=v;
}

void GrM::getAns(ListV* ans, ListV& s)
{
    int flag=false;
    for (int i=s.nV-1; i>=0; --i)
    {
        if (deg[s.l[i]]>1) flag=true;
        for (int j=0; j<deg[s.l[i]]-1; ++j)
                ans->l[ans->nV++]=s.l[i];
    }
    if (!flag) ans->l[ans->nV++]=s.l[0];
}


ListV* GrA::dfs()
{
    ListV L;
    ListV * ans= new ListV;
    ans->nV=0;
    ans->l=new int[n];
    bool* visited=new bool [n];
    for (int v=0; v<n; ++v)
        visited[v] = 0;
    L.nV=0;
    L.l=new int[n];
    for (int v=0; v<n; ++v)
        if (!visited[v])
            dfsr(v,L,visited);
    for (int v=0; v<n; ++v)
        visited[v] = 0;
    for (int i=n-1; i>=0; i--)
    {
        int v = L.l[i];
        if (!visited[v])
        {
            ListV Q;
            Q.nV=0;
            Q.l=new int[n];
            dfsr(v,Q,visited);
            getAns(ans, Q);
            delete [] Q.l;
        }
    }
    delete [] L.l;
    delete [] visited;
    return ans;
}
