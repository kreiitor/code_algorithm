#include <iostream>
#include <vector>

using namespace std;

// 线性查找
int linearSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // 返回目标元素的索引
        }
    }
    return -1; // 未找到目标元素
}

// 二分查找（迭代版本）
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // 避免整数溢出
        
        if (arr[mid] == target) {
            return mid; // 找到目标元素
        } else if (arr[mid] < target) {
            left = mid + 1; // 目标元素在右半部分
        } else {
            right = mid - 1; // 目标元素在左半部分
        }
    }
    
    return -1; // 未找到目标元素
}

// 二分查找（递归版本）
int binarySearchRecursiveHelper(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // 未找到目标元素
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursiveHelper(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursiveHelper(arr, target, left, mid - 1);
    }
}

int binarySearchRecursive(const vector<int>& arr, int target) {
    return binarySearchRecursiveHelper(arr, target, 0, arr.size() - 1);
}

// 测试所有查找算法
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;
    
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Target: " << target << endl;
    
    // 测试线性查找
    int linearResult = linearSearch(arr, target);
    cout << "\nLinear Search: " << endl;
    if (linearResult != -1) {
        cout << "Element found at index: " << linearResult << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    // 测试二分查找（迭代版本）
    int binaryIterativeResult = binarySearchIterative(arr, target);
    cout << "\nBinary Search (Iterative): " << endl;
    if (binaryIterativeResult != -1) {
        cout << "Element found at index: " << binaryIterativeResult << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    // 测试二分查找（递归版本）
    int binaryRecursiveResult = binarySearchRecursive(arr, target);
    cout << "\nBinary Search (Recursive): " << endl;
    if (binaryRecursiveResult != -1) {
        cout << "Element found at index: " << binaryRecursiveResult << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    // 测试未找到的情况
    target = 10;
    cout << "\n\nTarget: " << target << endl;
    
    linearResult = linearSearch(arr, target);
    cout << "\nLinear Search: " << endl;
    if (linearResult != -1) {
        cout << "Element found at index: " << linearResult << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    binaryIterativeResult = binarySearchIterative(arr, target);
    cout << "\nBinary Search (Iterative): " << endl;
    if (binaryIterativeResult != -1) {
        cout << "Element found at index: " << binaryIterativeResult << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
