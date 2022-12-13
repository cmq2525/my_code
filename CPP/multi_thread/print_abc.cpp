
#include<iostream>
#include<thread>
#include <mutex>
#include <condition_variable>
#include<chrono>
using namespace std;
std::condition_variable print_a, print_b, print_c;
std::mutex m;
void printA(){
    while(true){
        std::unique_lock<std::mutex> lk(m);
        print_a.wait(lk);
        printf("A\n");
        fflush(stdout);
        lk.unlock();
        print_b.notify_one();
    }
}
void printB(){
    while(true){
        std::unique_lock<std::mutex> lk(m);
        print_b.wait(lk);
        printf("B\n");
        lk.unlock();
        print_c.notify_one();
    }
}
void printC(){
    while(true){
        std::unique_lock<std::mutex> lk(m);
        print_c.wait(lk);
        printf("C\n");
        lk.unlock();
        print_a.notify_one();
    }
}
int main(){
    std::thread t1(printA);
    std::thread t2(printB);
    std::thread t3(printC);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    print_a.notify_one();
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
