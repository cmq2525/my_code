#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
class Solution {
public:
    void select_sort(vector<int>& nums){
        // 每次找到[i, end]中最小的元素num[pos]，把它和num[i]交换。
        for(int i = 0; i < nums.size(); ++i){
            int pos = i;
            for(int j = i+1; j < nums.size(); ++j){
                if(nums[j] < nums[pos]){
                    pos = j;
                }
            }
            swap(nums[i], nums[pos]);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        select_sort(nums);
        return nums;
    }
};

int main(){
    // Providing a seed value
	srand((unsigned) time(NULL));
    // int random = rand() % 100;
    // std::vector<int> nums(10);
    // for(int i=0; i<10; ++i){
    //     nums[i] = rand() %100;
    //     // nums[i] = 2;
    // }
    std::vector<int> nums = {1,3,2,5};
    printf("befor sort, nums:[");
    for(int i=0; i<nums.size(); ++i){
        printf("%d ", nums[i]);
    }
    printf("]\n");
    auto s = Solution();
    s.sortArray(nums);
    // swap(nums[0], nums[4]);
    printf("after sort, nums:[");
    for(int i=0; i<nums.size(); ++i){
        printf("%d ", nums[i]);
    }
    printf("]\n");
    // printf("hello! [%d]\n", random);
    return 0;
}