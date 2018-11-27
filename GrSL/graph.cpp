#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

bool GrSL:: in(string FN)
{
    ifstream f(FN);
    if (!f) return 0;
    int i, j;
    f >> n >> m;
    if (!init()) return 0;
    for (int k=0; k<m; ++k)
    {
        f >> i >> j;
        ++E[i][0];
        E[i][E[i][0]]=j;
    }
    f.close();
    return 1;
}

bool GrSL:: init()
{
    E = new(nothrow) int* [n];
    if (E==nullptr) return 0;
    for (int i=0; i<n; ++i)
    {
        E[i]=new (nothrow) int[n+1];
        if (E[i]==nullptr)
        {
            for (int j=0; j<i; ++j)
                delete [] E[j];
            return 0;
        }
       // for (int j=1; j<n; ++j)
       //     E[i][j]=-1;
        E[i][0]=0;
    }
    return 1;
}

void GrSL:: out(string FN)
{
    ofstream f(FN);
    f << n << " " << m <<"\n";
    for (int i=0; i<n; ++i)
    {
        //f << i << " " << E[i][0] << "\n ";
        for (int j=1; j<=E[i][0]; ++j)
            f << i << " " << E[i][j] << "\n";
    }
    f.close();
}

GrSL::~GrSL()
{
    for (int i=0; i<n; ++i)
        delete [] E[i];
    delete [] E;
}

bool GrSL::transp(GrSL& a)
{
    n=a.n; m=a.m;
    if (!init()) return 0;
    for (int i=0; i<n; ++i)
        for (int j=1; j<=a.E[i][0]; ++j)
        {
            int t=a.E[i][j];
            ++E[t][0];
            E[t][E[t][0]]=i;
        }
    return 1;
}

bool GrSL::oneArc(ListV& a)
{
    a.nV=0;
    a.l=new int [n];
    for (int i=0; i<n; ++i)
        if (E[i][0]!=1) a.l[a.nV++]=i;
    return (a.nV>0);
}

void GrSL::dfsr(int v, ListV& L, bool* visited)
{
    visited[v]=true;
    for (int i=1; i<=E[v][0]; ++i)
        if (!visited[E[v][i]])
            dfsr(E[v][i],L,visited);
    L.l[L.nV++]=v;
}

void GrSL::getAns(ListV* ans, ListV& s)
{
    int flag=false;
    for (int i=s.nV-1; i>=0; --i)
    {
        if (E[s.l[i]][0]>1) flag=true;
        for (int j=0; j<E[s.l[i]][0]-1; ++j)
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
