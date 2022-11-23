#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
class Solution {
public:
    void count_sort(vector<int>& nums){
        std::vector<int> counter(10);
        int max_num = 0, min_num = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > max_num) max_num = nums[i];
            if(nums[i] < min_num) min_num = nums[i];
        }
        std::vector<int> bucket(max_num - min_num + 1);
        for(int i = 0; i < nums.size(); ++i){
            bucket[nums[i] - min_num] += 1;
        }
        int count = 0;
        for(int i = 0; i < bucket.size(); ++i){
            for(int j = 0; j < bucket[i]; ++j){
                nums[count++] = i + min_num;
            }
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        count_sort(nums);
        return nums;
    }
};

int main(){
    // Providing a seed value
	srand((unsigned) time(NULL));
    int random = rand() % 100;
    std::vector<int> nums(10);
    for(int i=0; i<10; ++i){
        nums[i] = rand() %100;
        // nums[i] = 2;
    }
    // std::vector<int> nums = {-1,2,-8,-10};
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