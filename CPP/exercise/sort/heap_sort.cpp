#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
size_t father(size_t i){
    if(i > 0){
        return (i-1) / 2;
    } else {
        return 0;
    }
    // return (i-1)/2 if i > 0 else 0;
}
size_t left_child(size_t i){
    return i*2 + 1;
}
class PriorityQueue{
public:
    std::vector<int> m_nums;
public:
    PriorityQueue(std::vector<int> nums):m_nums(nums){}
    ~PriorityQueue(){
        m_nums.clear();
    }
    // 确保index（一般是根节点）到叶节点的路径上的值都满足堆的规则
    void sift_down(size_t index){
        if(m_nums.size()==0){
            return;
        }
        if(index >= m_nums.size()){
            throw "error index";
        }
        int val = m_nums[index];
        printf("in sift_down, nums:[");
        for(int i=0; i<m_nums.size(); ++i){
            printf("%d ", m_nums[i]);
        }
        printf("]\n");
        while(true){
            // 获取较小的子节点
            size_t child = left_child(index);
            printf("[cmq] index:[%zu], child:[%zu], val:[%d]\n", index, child, val);
            // printf("[cmq] m_nums[index]:[%d] m_nums[child]:[%d]\n", m_nums[index], m_nums[child]);
            if(child < m_nums.size() - 1 && m_nums[child] > m_nums[child+1]){
                ++child;
            }
            // 父节点下移
            if(child < m_nums.size() && val > m_nums[child]){
                m_nums[index] = m_nums[child];
                index = child;
            } else {
                break;
            }
        }
        m_nums[index] = val;
        printf("after sift_down, nums:[");
        for(int i=0; i<m_nums.size(); ++i){
            printf("%d ", m_nums[i]);
        }
        printf("]\n");
    }
    // 确保index（一般是最后一个节点）至root这一条路径上的值都满足堆的规则
    void sift_up(int index){
        if(index >= m_nums.size()){
            throw "error index";
        }
        if(index == 0 || index >= m_nums.size()){
            return;
        }
        int val = m_nums[index];
        // 遍历，直到根节点。
        while(true){
            size_t dad = father(index);
            // 子节点上移
            if(index > 0 && m_nums[dad] > val){
                // swap(m_nums[index], m_nums[dad]);
                m_nums[dad] = m_nums[index];
                index = dad;
            } else {
                break;
            }
        }
        m_nums[index] = val;
        printf("after manage up, nums:[");
        for(int i=0; i<m_nums.size(); ++i){
            printf("%d ", m_nums[i]);
        }
        printf("]\n");
    }
    void insert(int num){
        m_nums.emplace_back(num);
        sift_up(m_nums.size()-1);
    }
    int pop(){
        printf("in pop, m_nums:[");
        for(int i=0; i<m_nums.size(); ++i){
            printf("%d ", m_nums[i]);
        }
        printf("]\n");
        int val = m_nums[0];
        printf("in pop, val:[%d]\n", val);
        m_nums[0] = m_nums.back();
        m_nums.pop_back();
        sift_down(0);
        return val;
    }
    void heapify(){
        for(int i = m_nums.size()/2; i >= 0; --i){
            sift_down(i);
        }
    }
    bool empty(){
        return m_nums.size() == 0;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        PriorityQueue min_heap = PriorityQueue(nums);
        min_heap.heapify();
        std::vector<int> result;
        while(!min_heap.empty()){
            result.emplace_back(min_heap.pop());
        }
        return result;
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
    std::vector<int> nums = {5,2,3,1};
    printf("befor sort, nums:[");
    for(int i=0; i<nums.size(); ++i){
        printf("%d ", nums[i]);
    }
    printf("]\n");
    auto s = Solution();
    std::vector<int> result = s.sortArray(nums);
    // swap(nums[0], nums[4]);
    printf("after sort, result:[");
    for(int i=0; i<result.size(); ++i){
        printf("%d ", result[i]);
    }
    printf("]\n");
    // printf("hello! [%d]\n", random);
    return 0;
}