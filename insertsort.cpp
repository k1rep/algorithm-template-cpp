//
// Created on 2024/2/17.
//
#include <iostream>
using namespace std;
void insert_sort(int a[], int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void insert_sort_binary(int a[], int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int left = 0;
        int right = i-1;
        while(left<=right){
            int mid = left + ((right-left)>>1);
            if(a[mid]>key){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        for(int j=i-1;j>=left;j--){
            a[j+1] = a[j];
        }
        a[left] = key;
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,4,13,3,12,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    insert_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b[] = {1,2,3,4,5,6,7,8,9,10,4,13,3,12,9,2};
    int m = sizeof(b)/sizeof(b[0]);
    insert_sort_binary(b, m);
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}