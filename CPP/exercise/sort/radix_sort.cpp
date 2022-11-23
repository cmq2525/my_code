#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
class Solution {
public:
    void radix_sort(vector<int>& nums){
        std::vector<int> counter(10);
        std::vector<int> tmp(nums.size());
        // max_num用来获取最大迭代次数（有多少位），min_num用来将负数转换为正数。
        int max_num = 0, min_num = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > max_num) max_num = nums[i];
            if(nums[i] < min_num) min_num = nums[i];
        }
        if(min_num < 0){
            for(int i = 0; i < nums.size(); ++i) nums[i] -= min_num;
            max_num -= min_num;
        }
        printf("after add min_num, nums:[");
        for(int i=0; i<nums.size(); ++i){
            printf("%d ", nums[i]);
        }
        printf("]\n");
        int radix = 1;
        while(max_num > 0){
            for(int j = 0; j<nums.size(); ++j){
                int k = (nums[j] / radix) % 10;
                counter[k] += 1;
            }
            // counter按顺序连在一起
            for(int j = 1; j<10; ++j){
                counter[j] += counter[j-1];
            }
            // 每个counter对应的数字应该先入先出，但counter记录的是个数，因此要逆向遍历
            for(int j = nums.size() - 1; j >= 0; --j){
                int k = (nums[j] / radix) % 10;
                tmp[counter[k] - 1] = nums[j];
                counter[k]--;
            }
            // clear counter
            for(int j = 0; j < 10; ++j){
                counter[j] = 0;
            }
            for(int i = 0; i < nums.size(); ++i){
                nums[i] = tmp[i];
            }
            printf("radix:[%d], nums:[", radix);
            for(int i=0; i<nums.size(); ++i){
                printf("%d ", nums[i]);
            }
            printf("]\n");
            radix *= 10;
            max_num /= 10;
        }
        if(min_num < 0){
            for(int i = 0; i < nums.size(); ++i) nums[i] += min_num;
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        radix_sort(nums);
        return nums;
    }
};

int main(){
    // Providing a seed value
	srand((unsigned) time(NULL));
    int random = rand() % 100;
    // std::vector<int> nums(10);
    // for(int i=0; i<10; ++i){
    //     nums[i] = rand() %100;
    //     // nums[i] = 2;
    // }
    std::vector<int> nums = {-1,2,-8,-10};
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