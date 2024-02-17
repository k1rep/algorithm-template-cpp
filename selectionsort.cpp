//
// Created on 2024/2/17.
//
#include <iostream>
using namespace std;
void selection_sort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,4,13,3,12,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    selection_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}