#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // 如果没有发生交换，说明数组已经有序
        if (!swapped) {
            break;
        }
    }
}

// 选择排序
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // 找到未排序部分的最小值索引
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 将最小值交换到已排序部分的末尾
        swap(arr[i], arr[minIndex]);
    }
}

// 插入排序
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // 将大于key的元素向右移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

// 快速排序的分区函数
int partition(vector<int>& arr, int low, int high) {
    // 选择最后一个元素作为 pivot
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 获取分区点
        int pi = partition(arr, low, high);
        
        // 递归排序分区点左右两侧的子数组
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// 归并排序的合并函数
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 创建临时数组
    vector<int> L(n1);
    vector<int> R(n2);
    
    // 复制数据到临时数组
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // 合并临时数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // 复制剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void mergeSortHelper(vector<int>& arr, int left, int right) {
    if (left < right) {
        // 计算中间点
        int mid = left + (right - left) / 2;
        
        // 递归排序左右两侧
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        
        // 合并已排序的子数组
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// 测试所有排序算法
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> testArr;
    
    cout << "Original array: " << endl;
    printArray(arr);
    
    // 测试冒泡排序
    testArr = arr;
    bubbleSort(testArr);
    cout << "\nBubble Sort: " << endl;
    printArray(testArr);
    
    // 测试选择排序
    testArr = arr;
    selectionSort(testArr);
    cout << "\nSelection Sort: " << endl;
    printArray(testArr);
    
    // 测试插入排序
    testArr = arr;
    insertionSort(testArr);
    cout << "\nInsertion Sort: " << endl;
    printArray(testArr);
    
    // 测试快速排序
    testArr = arr;
    quickSort(testArr);
    cout << "\nQuick Sort: " << endl;
    printArray(testArr);
    
    // 测试归并排序
    testArr = arr;
    mergeSort(testArr);
    cout << "\nMerge Sort: " << endl;
    printArray(testArr);
    
    return 0;
}
