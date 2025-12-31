#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class TreeNode {
public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    
    TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
protected:
    TreeNode<T>* root;
    
    // 递归前序遍历
    void preOrderRecursive(TreeNode<T>* node) const {
        if (node == nullptr) {
            return;
        }
        cout << node->val << " ";
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }
    
    // 递归中序遍历
    void inOrderRecursive(TreeNode<T>* node) const {
        if (node == nullptr) {
            return;
        }
        inOrderRecursive(node->left);
        cout << node->val << " ";
        inOrderRecursive(node->right);
    }
    
    // 递归后序遍历
    void postOrderRecursive(TreeNode<T>* node) const {
        if (node == nullptr) {
            return;
        }
        postOrderRecursive(node->left);
        postOrderRecursive(node->right);
        cout << node->val << " ";
    }
    
    // 递归计算树的高度
    int getHeightRecursive(TreeNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeightRecursive(node->left);
        int rightHeight = getHeightRecursive(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    
    // 递归计算节点数量
    int getNodeCountRecursive(TreeNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + getNodeCountRecursive(node->left) + getNodeCountRecursive(node->right);
    }
    
    // 递归销毁树
    void destroyTree(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    
public:
    // 构造函数
    BinaryTree() : root(nullptr) {}
    
    // 析构函数
    ~BinaryTree() {
        destroyTree(root);
    }
    
    // 获取根节点
    TreeNode<T>* getRoot() const {
        return root;
    }
    
    // 设置根节点
    void setRoot(TreeNode<T>* node) {
        root = node;
    }
    
    // 前序遍历
    void preOrder() const {
        cout << "Pre-order traversal: ";
        preOrderRecursive(root);
        cout << endl;
    }
    
    // 中序遍历
    void inOrder() const {
        cout << "In-order traversal: ";
        inOrderRecursive(root);
        cout << endl;
    }
    
    // 后序遍历
    void postOrder() const {
        cout << "Post-order traversal: ";
        postOrderRecursive(root);
        cout << endl;
    }
    
    // 层序遍历
    void levelOrder() const {
        if (root == nullptr) {
            return;
        }
        
        queue<TreeNode<T>*> q;
        q.push(root);
        
        cout << "Level-order traversal: ";
        while (!q.empty()) {
            TreeNode<T>* current = q.front();
            q.pop();
            cout << current->val << " ";
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
    
    // 获取树的高度
    int getHeight() const {
        return getHeightRecursive(root);
    }
    
    // 获取节点数量
    int getNodeCount() const {
        return getNodeCountRecursive(root);
    }
    
    // 判断树是否为空
    bool isEmpty() const {
        return root == nullptr;
    }
};

int main() {
    // 创建一个简单的二叉树
    BinaryTree<int> tree;
    
    // 手动构建二叉树
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node2 = new TreeNode<int>(2);
    TreeNode<int>* node3 = new TreeNode<int>(3);
    TreeNode<int>* node4 = new TreeNode<int>(4);
    TreeNode<int>* node5 = new TreeNode<int>(5);
    TreeNode<int>* node6 = new TreeNode<int>(6);
    TreeNode<int>* node7 = new TreeNode<int>(7);
    
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    
    tree.setRoot(root);
    
    // 测试遍历
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    tree.levelOrder();
    
    // 测试属性
    cout << "Tree height: " << tree.getHeight() << endl;
    cout << "Node count: " << tree.getNodeCount() << endl;
    cout << "Is empty: " << (tree.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
