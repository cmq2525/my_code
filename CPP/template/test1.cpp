#include<iostream>
// 类模板
template <class T1, class T2>
class A{
    T1 data1;
    T2 data2;
public:
    void print_me(){
        printf("this is A<T1, T2>\n");
    }
};

// 全特化
template <>
class A<int, double>{
    int data1;
    double data2;
public:
    void print_me(){
        printf("this is A<int, double>\n");
    }
};

// //偏特化
// template <class T2>
// class A<int, T2>{
//     ...
// };
int main(){
    A<int, int> cmq;
    cmq.print_me();
}