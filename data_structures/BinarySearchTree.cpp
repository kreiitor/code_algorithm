#include <iostream>
#include "BinaryTree.cpp"

using namespace std;

template<typename T>
class BinarySearchTree : public BinaryTree<T> {
private:
    // 递归插入节点
    TreeNode<T>* insertRecursive(TreeNode<T>* node, T val) {
        if (node == nullptr) {
            return new TreeNode<T>(val);
        }
        
        if (val < node->val) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->val) {
            node->right = insertRecursive(node->right, val);
        }
        // 如果val已经存在，不做任何操作
        
        return node;
    }
    
    // 递归查找节点
    TreeNode<T>* findRecursive(TreeNode<T>* node, T val) const {
        if (node == nullptr || node->val == val) {
            return node;
        }
        
        if (val < node->val) {
            return findRecursive(node->left, val);
        } else {
            return findRecursive(node->right, val);
        }
    }
    
    // 查找最小值节点
    TreeNode<T>* findMin(TreeNode<T>* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // 查找最大值节点
    TreeNode<T>* findMax(TreeNode<T>* node) const {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    
    // 递归删除节点
    TreeNode<T>* removeRecursive(TreeNode<T>* node, T val) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (val < node->val) {
            node->left = removeRecursive(node->left, val);
        } else if (val > node->val) {
            node->right = removeRecursive(node->right, val);
        } else {
            // 找到要删除的节点
            
            // 情况1：节点是叶子节点或只有一个子节点
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }
            
            // 情况2：节点有两个子节点
            // 找到右子树中的最小值节点
            TreeNode<T>* temp = findMin(node->right);
            
            // 用右子树中的最小值替换当前节点的值
            node->val = temp->val;
            
            // 删除右子树中的最小值节点
            node->right = removeRecursive(node->right, temp->val);
        }
        
        return node;
    }
    
public:
    // 构造函数
    BinarySearchTree() : BinaryTree<T>() {}
    
    // 插入节点
    void insert(T val) {
        this->root = insertRecursive(this->root, val);
    }
    
    // 查找节点
    TreeNode<T>* find(T val) const {
        return findRecursive(this->root, val);
    }
    
    // 删除节点
    void remove(T val) {
        this->root = removeRecursive(this->root, val);
    }
    
    // 查找最小值
    T findMin() const {
        if (this->root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        return findMin(this->root)->val;
    }
    
    // 查找最大值
    T findMax() const {
        if (this->root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        return findMax(this->root)->val;
    }
    
    // 检查是否包含某个值
    bool contains(T val) const {
        return find(val) != nullptr;
    }
};

int main() {
    BinarySearchTree<int> bst;
    
    // 测试插入操作
    int values[] = {5, 3, 7, 2, 4, 6, 8, 1, 9};
    for (int val : values) {
        bst.insert(val);
    }
    
    // 测试遍历（中序遍历应该是有序的）
    cout << "BST traversals:" << endl;
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();
    bst.levelOrder();
    
    // 测试查找操作
    cout << endl << "Search operations:" << endl;
    cout << "Contains 5: " << (bst.contains(5) ? "Yes" : "No") << endl;
    cout << "Contains 10: " << (bst.contains(10) ? "Yes" : "No") << endl;
    
    // 测试查找最小值和最大值
    cout << "Min value: " << bst.findMin() << endl;
    cout << "Max value: " << bst.findMax() << endl;
    
    // 测试删除操作
    cout << endl << "Delete operations:" << endl;
    cout << "Delete 1:" << endl;
    bst.remove(1);
    bst.inOrder();
    
    cout << "Delete 5:" << endl;
    bst.remove(5);
    bst.inOrder();
    
    cout << "Delete 9:" << endl;
    bst.remove(9);
    bst.inOrder();
    
    // 测试树的属性
    cout << endl << "BST properties:" << endl;
    cout << "Height: " << bst.getHeight() << endl;
    cout << "Node count: " << bst.getNodeCount() << endl;
    
    return 0;
}
