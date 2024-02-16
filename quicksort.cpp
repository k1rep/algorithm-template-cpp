//
// Created on 2022/5/13.
//
#include <iostream>
using namespace std;
int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low;
    for(int j=low;j<high;j++){
        if(a[j] <= pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[high]);
    return i;
}
void quick_sort(int a[], int low, int high){
    // 递归终止条件，数组只剩下一个元素或没有元素
    if(low < high){
        // q是分区后基准元素的索引
        int q = partition(a, low, high);
        quick_sort(a, low, q-1);
        quick_sort(a,q+1, high);
    }
}
int main(){
    int a[8] = {3,1,2,4,5,8,7,6};
    quick_sort(a,0,7);
    for(int i : a)
        cout<<i<<" ";
    return 0;
}