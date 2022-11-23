#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
class Solution {
public:
    void insert_sort(vector<int>& nums){
        // 每次把a[i]插到合适的位置（前面所有比它大的要后移）
        for(int i = 1; i < nums.size(); ++i){
            int val = nums[i], j = i - 1;
            while(j >= 0 && nums[j] > val){
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = val;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        insert_sort(nums);
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
    // std::vector<int> nums = {5,1,1,2,0,0};
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