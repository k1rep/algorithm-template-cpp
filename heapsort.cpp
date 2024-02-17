//
// Created on 2022/5/12.
//
#include <iostream>
#include <algorithm>
using namespace std;

// 升序采用大根堆，降序采用小根堆
// start是根节点，end是最后一个节点
void max_heapify(int a[], int start, int end) {
    int largest = start; // 初始化最大值的位置为根节点
    int l = start * 2 + 1; // 左子节点
    int r = l + 1; // 右子节点

    // 如果左子节点大于根节点，交换
    if(l < end && a[l] > a[largest]) largest = l;
    // 如果右子节点大于根节点，交换
    if(r < end && a[r] > a[largest]) largest = r;
    // 如果最大值不是根节点，交换
    if(largest != start) {
        swap(a[largest], a[start]);
        // 递归调整其他不符合大根堆的地方
        max_heapify(a, largest, end);
    }
}

void heap_sort(int a[], int n) {
    // 初始化大根堆
    for(int i=n/2-1; i>=0; i--) max_heapify(a, i, n);
    // 交换堆顶和最后一个元素，并且重新调整大根堆
    for(int i=n-1; i>0; i--) {
        swap(a[0], a[i]);
        max_heapify(a, 0, i);
    }
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,4,13,3,12,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    heap_sort(a, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}