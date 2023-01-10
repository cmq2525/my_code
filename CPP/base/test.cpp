#include<iostream>
#include<mutex>
#include<vector>
#include<condition_variable>
using namespace std;
template<typename Iter, class Operation>
void map_f(Iter start, Iter end, Operation f){
    while(start != end){
        *start++ = f(*start);
    }
}
int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5};
    map_f(nums.begin(), nums.end(), [](int x){ return x*2;});
    printf("nums: [");
    for(int i = 0; i < nums.size(); ++i){
        printf("%d ", nums[i]);
    }
    printf("]\n");
    return 0;
}