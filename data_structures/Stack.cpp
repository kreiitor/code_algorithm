#include <iostream>
#include "Array.cpp"

using namespace std;

template<typename T>
class Stack {
private:
    DynamicArray<T> array;
    
public:
    // 构造函数
    Stack(int capacity = 10) : array(capacity) {}
    
    // 获取栈的大小
    int getSize() const {
        return array.getSize();
    }
    
    // 判断栈是否为空
    bool isEmpty() const {
        return array.isEmpty();
    }
    
    // 获取栈的容量
    int getCapacity() const {
        return array.getCapacity();
    }
    
    // 入栈操作
    void push(T element) {
        array.addLast(element);
    }
    
    // 出栈操作
    T pop() {
        return array.removeLast();
    }
    
    // 获取栈顶元素
    T peek() const {
        return array.get(array.getSize() - 1);
    }
    
    // 打印栈
    void print() const {
        cout << "Stack: size = " << array.getSize() << ", capacity = " << array.getCapacity() << endl;
        cout << "[";
        for (int i = 0; i < array.getSize(); i++) {
            cout << array.get(i);
            if (i != array.getSize() - 1) {
                cout << ", ";
            }
        }
        cout << "] top" << endl;
    }
};

int main() {
    Stack<int> stack;
    
    // 测试入栈操作
    for (int i = 0; i < 10; i++) {
        stack.push(i);
        stack.print();
    }
    
    // 测试出栈操作
    for (int i = 0; i < 5; i++) {
        stack.pop();
        stack.print();
    }
    
    // 测试获取栈顶元素
    cout << "Top element: " << stack.peek() << endl;
    
    return 0;
}
