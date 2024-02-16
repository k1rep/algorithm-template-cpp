//
// Created on 2022/6/21.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucket_sort(double a[], int n){
    // 创建n个空桶
    vector<double> bucket[n];

    // 将数据分配到桶中
    for(int i=0;i<n;i++){
        // 映射函数f(x)=int(x)
        int bucket_index = int(a[i]);
        bucket[bucket_index].push_back(a[i]);
    }

    // 桶内排序
    for(int i=0;i<n;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }

    // 合并桶
    int index = 0;
    for(int i=0;i<n;i++){
        for(double j : bucket[i]){
            a[index++] = j;
        }
    }
}

int main(){
    double a[] = {1,2,3.11,4,5.3,6,7,8,9,10,4,13,3,12.1,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    bucket_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}