
#include<iostream>
#include<thread>
#include <mutex>
#include <condition_variable>
#include<chrono>
#include<tuple>
using namespace std;

template<int N>
class Placeholder{
};
template<typename T, typename Other>
int print(T&& lhs, Other&& rhs){
    printf("calling print v1\n");
    return 0;
}

template<int N, typename Other>
int print(Placeholder<N>& lhs, Other&& rhs){
    printf("calling print v2\n");
    return 0;
}

template<typename... Args>
void test_print_2(Args&&... args){}

template<typename... Args>
void test_print(Args&&... args) {
    // test_print_2(print(std::forward<Args>(args), 1)...);
    auto a = { print(std::forward<Args>(args), 1)... };
}

void test(){
    Placeholder<1> p_1; Placeholder<2> p_2; Placeholder<3> p_3; Placeholder<4> p_4; Placeholder<5> p_5;
    test_print(p_1, 1, p_2, 2.0, p_3);
    // auto tup_2 = std::make_tuple(1, 2, 3, 4, 5);

}
int main(){
    test();
    return 0;
}