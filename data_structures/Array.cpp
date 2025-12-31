#include <iostream>

using namespace std;

template<typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;
    
    // 扩容
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
public:
    // 构造函数
    DynamicArray(int initialCapacity = 10) {
        data = new T[initialCapacity];
        capacity = initialCapacity;
        size = 0;
    }
    
    // 析构函数
    ~DynamicArray() {
        delete[] data;
    }
    
    // 获取数组大小
    int getSize() const {
        return size;
    }
    
    // 获取数组容量
    int getCapacity() const {
        return capacity;
    }
    
    // 判断数组是否为空
    bool isEmpty() const {
        return size == 0;
    }
    
    // 在指定位置插入元素
    void insert(int index, T element) {
        if (index < 0 || index > size) {
            cout << "Index out of range" << endl;
            return;
        }
        
        // 如果容量已满，扩容为原来的2倍
        if (size == capacity) {
            resize(2 * capacity);
        }
        
        // 将元素向后移动
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        
        data[index] = element;
        size++;
    }
    
    // 在数组末尾添加元素
    void addLast(T element) {
        insert(size, element);
    }
    
    // 在数组开头添加元素
    void addFirst(T element) {
        insert(0, element);
    }
    
    // 获取指定位置的元素
    T get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of range" << endl;
            return T();
        }
        return data[index];
    }
    
    // 修改指定位置的元素
    void set(int index, T element) {
        if (index < 0 || index >= size) {
            cout << "Index out of range" << endl;
            return;
        }
        data[index] = element;
    }
    
    // 查找元素是否存在
    bool contains(T element) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == element) {
                return true;
            }
        }
        return false;
    }
    
    // 查找元素的索引
    int find(T element) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == element) {
                return i;
            }
        }
        return -1; // 未找到返回-1
    }
    
    // 删除指定位置的元素
    T remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of range" << endl;
            return T();
        }
        
        T ret = data[index];
        
        // 将元素向前移动
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;
        
        // 如果元素数量小于容量的1/4，缩容为原来的1/2
        if (size > 0 && size == capacity / 4) {
            resize(capacity / 2);
        }
        
        return ret;
    }
    
    // 删除第一个元素
    T removeFirst() {
        return remove(0);
    }
    
    // 删除最后一个元素
    T removeLast() {
        return remove(size - 1);
    }
    
    // 删除指定元素
    void removeElement(T element) {
        int index = find(element);
        if (index != -1) {
            remove(index);
        }
    }
    
    // 打印数组
    void print() const {
        cout << "DynamicArray: size = " << size << ", capacity = " << capacity << endl;
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i != size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    DynamicArray<int> arr;
    
    // 测试添加元素
    for (int i = 0; i < 10; i++) {
        arr.addLast(i);
    }
    arr.print();
    
    // 测试插入元素
    arr.insert(3, 100);
    arr.print();
    
    // 测试删除元素
    arr.remove(5);
    arr.print();
    
    // 测试扩容
    for (int i = 0; i < 10; i++) {
        arr.addLast(i + 10);
    }
    arr.print();
    
    // 测试缩容
    for (int i = 0; i < 15; i++) {
        arr.removeLast();
    }
    arr.print();
    
    return 0;
}
