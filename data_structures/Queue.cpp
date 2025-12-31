#include <iostream>
#include "Array.cpp"

using namespace std;

template<typename T>
class Queue {
private:
    DynamicArray<T> array;
    
public:
    // 构造函数
    Queue(int capacity = 10) : array(capacity) {}
    
    // 获取队列的大小
    int getSize() const {
        return array.getSize();
    }
    
    // 判断队列是否为空
    bool isEmpty() const {
        return array.isEmpty();
    }
    
    // 获取队列的容量
    int getCapacity() const {
        return array.getCapacity();
    }
    
    // 入队操作
    void enqueue(T element) {
        array.addLast(element);
    }
    
    // 出队操作
    T dequeue() {
        return array.removeFirst();
    }
    
    // 获取队首元素
    T front() const {
        return array.get(0);
    }
    
    // 打印队列
    void print() const {
        cout << "Queue: size = " << array.getSize() << ", capacity = " << array.getCapacity() << endl;
        cout << "front [";
        for (int i = 0; i < array.getSize(); i++) {
            cout << array.get(i);
            if (i != array.getSize() - 1) {
                cout << ", ";
            }
        }
        cout << "] tail" << endl;
    }
};

int main() {
    Queue<int> queue;
    
    // 测试入队操作
    for (int i = 0; i < 10; i++) {
        queue.enqueue(i);
        queue.print();
    }
    
    // 测试出队操作
    for (int i = 0; i < 5; i++) {
        queue.dequeue();
        queue.print();
    }
    
    // 测试获取队首元素
    cout << "Front element: " << queue.front() << endl;
    
    return 0;
}
