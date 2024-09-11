#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        n = arr.size();
        pointer = -1;
    }
    
    bool hasNext() {
        return pointer < n - 1;
    }

    int next() {
        pointer++;
        return arr[std::min(n - 1, pointer)];
    }

    bool hasPrev() {
        return pointer > 0;
    }

    int prev() {
        pointer--;
        return arr[std::max(pointer, 0)];
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
private:
    std::vector<int> arr;
    int n;
    int pointer;
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;
    std::cout << obj->hasNext() << std::endl;
    std::cout << obj->next() << std::endl;

    return 0;
}
