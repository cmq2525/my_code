#include<iostream>
#include<atomic>
using namespace std;

class Point{
public:
    Point(){}
    explicit Point(int x, int y, const std::string& name):x(x), y(y), name(name){
        printf("construct Point! name:[%s]\n", name.c_str());
    }
    Point(const Point& p) {
        printf("copy construct! src_name:[%s]\n", p.name.c_str());
        x = p.x;
        y = p.y;
        name = p.name + "copied";
    }
    // Point(Point p){
    //     printf("fake move construct! src_name:[%s]\n", p.name.c_str());
    //     x = p.x;
    //     y = p.y;
    //     name = p.name + "fake moved";
    // }
    // Point& operator=(Point p){
    //     printf("fake move assigned! src_name:[%s]\n", p.name.c_str());
    //     x = p.x;
    //     y = p.y;
    //     name = p.name + "fake move assigned";
    //     return *this;
    // }
    Point& operator=(const Point& p){
        printf("copy assigned! src_name:[%s]\n", p.name.c_str());
        x = p.x;
        y = p.y;
        name = p.name + "copy assigned";
        return *this;
    }
    // Point(Point&& p){
    //     printf("move construct! src_name:[%s]\n", p.name.c_str());
    //     x = p.x;
    //     y = p.y;
    //     name = std::move(p.name);
    //     name += "moved";
    // }
    Point& add_one(){
        printf("call add one!\n");
        ++x;
        ++y;
        return *this;
    }
    ~Point(){
        printf("destroy point! name:[%s]\n", name.c_str());
    }
public:
    int x;
    int y;
    std::string name;
};
Point gen_point(){
    for(int i = 0; i < 100; ++i){
        printf("h");
    }
    Point result(1, 2, "result");
    for(int i = 0; i < 100; ++i){
        printf("y");
    }
    result.x = 100;
    return result;
}
void print_point(Point p){
    printf("do nothing!\n");
}
int main(){
    // Point p1(2, 3, "p1");
    // Point p2(1, 1, "p2");
    // copy
    // print_point(p1);
    // no copy
    // print_point(gen_point());
    // copy
    // print_point(std::move(gen_point()));
    // print_point(gen_point());
    gen_point();
    // Point&& p2 = std::move(p1);
    // copy
    // print_point(std::forward<Point>(gen_point()));

    // print_point(gen_point());
    // p1.add_one();

    // printf("hello![%d]\n", p1.x);
    // std::string s ="hell world";
    // printf("s:[%p], [%s]\n", s.c_str(), s.c_str());
    // auto left = std::move(s);
    // s[0] = 'c';
    // s[1] = 'm';
    // printf("s:[%p], [%s]\n", s.c_str(), s.c_str());
    // printf("[cmq] s.size:[%zu]\n", s.size());
    // printf("left:[%p], [%s]\n", left.c_str(), left.c_str());
    return 0;
}