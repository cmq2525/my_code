#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
class Solution {
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int cnt = 0;
        // 把[left, mid] [mid+1, right] merge到tmp
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        // [left, mid]中可能有剩余的部分
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        // [mid+1, right]中可能有剩余的部分
        while (j <= right) {
            tmp[cnt++] = nums[j++];
        }
        // 把tmp中的数据放到nums中
        for (int i = 0; i < right - left + 1; ++i) {
            nums[left + i] = tmp[i];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
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