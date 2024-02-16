//
// Created on 2022/5/13.
//

#include <iostream>
using namespace std;
// 合并两个子数组
// 第一个子数组是a[l...q]
// 第二个子数组是a[q+1...r]
void merge(int a[], int l, int q, int r){
    int i, j, k;
    int n1 = q-l+1;
    int n2 = r-q;

    int L[n1], R[n2];

    // 将a[l...q]复制到L[0...n1-1]
    for(i=0;i<n1;i++){
        L[i] = a[l+i];
    }
    // 将a[q+1...r]复制到R[0...n2-1]
    for(j=0;j<n2;j++){
        R[j] = a[q+1+j];
    }
    // 合并L和R到a[l...r]
    i = 0; // 初始化第一个子数组的索引
    j = 0; // 初始化第二个子数组的索引
    k = l; // 初始化合并子数组的索引
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k++] = L[i++];
        }else{
            a[k++] = R[j++];
        }
    }
    // 将L中剩余的元素复制到a
    while(i<n1){
        a[k++] = L[i++];
    }
    // 将R中剩余的元素复制到a
    while(j<n2){
        a[k++] = R[j++];
    }
}
void merge_sort(int a[], int l, int r) {
    // 边界：只有一个元素
    if(l < r) {
        int q = l + ((r - l) >> 1);
        merge_sort(a, l, q);
        merge_sort(a, q + 1, r);
        merge(a, l, q, r);
    }
}
int main(){
    int a[8] = {3,1,2,4,5,8,7,6};
    merge_sort(a, 0,7);
    for(int i : a){
        cout << i << " ";
    }
    return 0;
}