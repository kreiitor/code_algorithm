#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T val;
    Node<T>* next;
    
    Node(T val) : val(val), next(nullptr) {}
};

template<typename T>
class List {
public:
    Node<T>* head;
    int size;
    
    // 构造函数
    List() {
        head = new Node<T>(T()); // 创建虚拟头结点
        size = 0;
    }
    
    // 析构函数
    ~List() {
        clear();
        delete head;
    }
    
    // 清空链表
    void clear() {
        Node<T>* current = head->next;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head->next = nullptr;
        size = 0;
    }
    
    // 在链表末尾添加元素
    void add(T val) {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(val);
        size++;
    }
    
    // 在指定位置插入元素
    void insert(int index, T val) {
        if (index < 0 || index > size) {
            return;
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        Node<T>* newNode = new Node<T>(val);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    // 删除指定位置的元素
    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        Node<T>* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        size--;
        return true;
    }
    
    // 获取指定位置的元素
    T get(int index) {
        if (index < 0 || index >= size) {
            return T();
        }
        
        Node<T>* current = head->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }
    
    // 反转链表
    void reverseList() {
        Node<T>* pre = nullptr;
        Node<T>* current = head->next;
        
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        
        head->next = pre;
    }
    
    // 打印链表
    void printList() {
        Node<T>* current = head->next;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

template<typename T>
Node<T>* merge2ListBetter(List<T>& A, List<T>& B) {
    Node<T>* p = A.head->next;
    Node<T>* q = B.head->next;
    
    // 创建新的虚拟头结点
    Node<T>* dummy = new Node<T>(T());
    Node<T>* current = dummy;
    
    // 合并两个链表
    while (p && q) {
        if (p->val <= q->val) {
            current->next = p;
            p = p->next;
        } else {
            current->next = q;
            q = q->next;
        }
        current = current->next;
    }
    
    // 连接剩余部分
    current->next = p ? p : q;
    
    // 清空原链表
    A.head->next = nullptr;
    B.head->next = nullptr;
    A.size = 0;
    B.size = 0;
    
    return dummy;
}

int main() {
    List<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.printList();
    
    list.reverseList();
    list.printList();
    
    return 0;
}