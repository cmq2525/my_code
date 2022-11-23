#include<iostream>
using namespace std;
class Singleton{
public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
private:
    Singleton() = default;
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;
};
int main(){
    Singleton& cmq = Singleton::getInstance();
    return 0;
}