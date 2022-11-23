#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if(root == nullptr){
            return result;
        }
        std::stack<TreeNode*> node_stack;
        while(root != nullptr || !node_stack.empty()){
            // 左子树进栈
            while(root){
                node_stack.push(root);
                root = root->left;
            }
            root = node_stack.top();
            node_stack.pop();
            result.emplace_back(root->val);
            root = root->right;
        }
        return result;
    }
};
int main(){
    TreeNode l1(1), l2(0), l3(0), l4(4);
    l1.right = &l2;
    l2.left = &l3;
    // l3.next = &l4;
    Solution s;
    std::vector<int> result = s.inorderTraversal(&l1);
    printf("result:[");
    for(int i=0; i<result.size(); ++i){
        printf("%d ", result[i]);
    }
    printf("]\n");
    return 0;
}