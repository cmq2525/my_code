#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
class Solution {
public:
    std::tuple<int, int> partition(vector<int>& nums, int start, int end){
        int left = start, right = end;
        // left、mid、right，取中间值作为pivot，尽可能让pivot_index靠近(left + right) >> 2，让递归树深度接近。
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) swap(nums[mid], nums[right]);
        if (nums[left] > nums[right]) swap(nums[left], nums[right]);
        // 至此，right是最大的
        if (nums[left] < nums[mid]) swap(nums[left], nums[mid]);
        // 至此，left是中间值
        int pivot = nums[left];
        printf("call partition, left:[%d], right:[%d], pivot:[%d]\n", left, right, pivot);
        printf("in partition, nums:[");
        for(int i=0; i<nums.size(); ++i){
            printf("%d ", nums[i]);
        }
        printf("]\n");
        while(left < right){
            // 找到第一个小于等于pivot的值，放到pivot左侧
            while(left < right && nums[right] > pivot) right--;
            if(left < right){
                nums[left] = nums[right];
            }
            // 找到第一个大于pivot的值，放到右侧。
            while(left < right && nums[left] <= pivot) left++;
            if(left < right){
                nums[right] = nums[left];
            }
            printf("left:[%d], right:[%d]\n", left, right);
            fflush(stdout);
        }
        nums[left] = pivot;
        int same_as_pivot = 0;
        // partition后，[left+1, end]都比pivot大，而[start, left -1]可能和pivot的值相同。
        for (int i = left - 1; i >= start && nums[i] == pivot; --i) ++same_as_pivot;
        return std::make_tuple(left, same_as_pivot);
    }
    void quick_sort(vector<int>& nums, int left, int right){
        if (left < right){
            std::tuple<int, int> tup = partition(nums, left, right);
            int index = std::get<0>(tup);
            int same_as_pivot = std::get<1>(tup);
            printf("[cmq] index:[%d], same_as_pivot:[%d]\n", index, same_as_pivot);
            quick_sort(nums, left, index - 1 - same_as_pivot);
            quick_sort(nums, index + 1, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(){
    // Providing a seed value
	srand((unsigned) time(NULL));
    int random = rand() % 100;
    // std::vector<int> nums(10);
    // for(int i=0; i<10; ++i){
    //     // nums[i] = rand() %100;
    //     nums[i] = 2;
    // }
    std::vector<int> nums = {5,1,1,2,0,0};
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