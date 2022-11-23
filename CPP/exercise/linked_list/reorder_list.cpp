#include<iostream>
using namespace std;
struct ListNode {
    int val;  
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print_me(){
        printf("node value: %d\n", val);
    }
    void print_list(){
        printf("Print LinkedList:\n");
        print_me();
        ListNode* tmp = next;
        while(tmp){
            tmp->print_me();
            tmp = tmp->next;
        }

    }
};

class Solution {
public:
    int getLength(ListNode *head){
        int count = 0;
        while(head){
            head = head->next;
            ++count;
        }
        return count;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return false;
        }
        int length = getLength(head);
        // find middle node && reverse first half
        ListNode* quick = head, *slow = head, *prev = nullptr;
        while(quick){
            quick = quick->next;
            if(quick == nullptr){
                break;
            }
            quick = quick->next;
            if(quick == nullptr){
                break;
            }
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        printf("now, print prev\n");
        prev->print_list();

        ListNode* right_half = slow->next, *left_half = nullptr;
        if(length & 1 == 1){
            left_half = prev;
        } else{
            slow->next = prev;
            left_half = slow;
        }
        printf("now, print left_half\n");
        left_half->print_list();
        printf("now, print right_half\n");
        right_half->print_list();
        while(left_half && right_half){
            if(left_half->val != right_half->val){
                return false;
            }
            left_half = left_half->next;
            right_half = right_half->next;
        }
        return true;
        
    }
};
int main(){
    ListNode l1(1), l2(0), l3(0), l4(4);
    l1.next = &l2;
    l2.next = &l3;
    // l3.next = &l4;
    Solution s;
    s.isPalindrome(&l1);
    // l1.print_list();
    return 0;
}