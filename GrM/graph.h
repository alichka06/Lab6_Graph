#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

using namespace std;

struct ListV
{
    int nV;
    int* l;
};

class GrA
{
    protected:
        int n,m;
        virtual void dfsr(int v, ListV& L, bool* visited)=0;
    public:
        GrA():n(0), m(0) {};
        virtual bool in(string FN)=0;
        virtual void out(string FN)=0;
        virtual bool oneArc(ListV& ans)=0;
        virtual void getAns(ListV* ans, ListV& s)=0;
        ListV* dfs();
};

class GrM: public GrA
{
    protected:
        int* E [10000];
        int deg[10000];
        bool init();
        void dfsr(int v, ListV& L, bool* visited);
        void getAns(ListV* ans, ListV& s);
    public:
        GrM(): E({0}), deg({0}) {};
        ~GrM();
        bool in(string FN);
        void out(string FN);
        bool oneArc(ListV& a);
};


void ansOut(ListV* a, string FN, int k, time_t timer);

#endif // GRAPH_H_INCLUDED
