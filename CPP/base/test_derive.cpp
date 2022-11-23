#include<iostream>
using namespace std;

struct PointA{
public:
    PointA(){printf("construct point A\n"); a = 10;}
    ~PointA(){printf("destroy point A\n");}
    void print_me(){
        printf("this is pointA\n");
    }
public:
    int a;
};
struct PointB: public PointA{
public:
    PointB(){printf("construct point B\n"); b = 20;}
    ~PointB(){printf("destroy point B\n");}
    void print_me(){
        printf("this is pointB\n");
    }
public:
    int b;
};
struct PointC: public PointA{
public:
    PointC(){printf("construct point C\n"); c = 30;}
    ~PointC(){printf("destroy point C\n");}
    void print_me(){
        printf("this is pointC\n");
    }
public:
    int c;
};
struct PointD : public PointB, PointC{
public:
    PointD(){printf("construct point D\n"); c = 40;}
    ~PointD(){printf("destroy point D\n");}
    void print_me(){
        printf("this is pointD, a:[%d]\n", PointC::a);
    }
public:
    int c;
};
int main(){
    PointD p;
    p.print_me();
}