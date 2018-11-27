#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

using namespace std;
class GrA
{
    protected:
        int n,m;
    public:
        GrA():n(0), m(0) {};
        virtual bool in(string FN)=0;
        virtual void out(string FN)=0;
        virtual bool oneArc(int* ans)=0;
};

class GrM: public GrA
{
    protected:
        int* E [10000];
        bool init();
    public:
        GrM(): E({nullptr}) {for(int i=0; i<10000; ++i) E[i]=nullptr;};
        ~GrM();
        bool in(string FN);
        void out(string FN);
        bool oneArc(int* ans);
        //op =
};

class GrSL: public GrA
{
    protected:
        int** E;
        bool init();
    public:
        GrSL():E(nullptr) {};
        ~GrSL();
        bool in(string FN);
        void out(string FN);
        bool oneArc(int* ans);
        void transp(GrSL& a);
        void ch();

      //  op =
};

struct ListV
{
    int nV;
    int* l;
};
void ansOut1(ListV a, string FN);

#endif // GRAPH_H_INCLUDED
