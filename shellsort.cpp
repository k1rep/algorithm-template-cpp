//
// Created on 2024/2/17.
//
#include <iostream>
using namespace std;
void shell_sort(int a[], int n){
    for(int gap=n/2;gap>0;gap/=2) {
        for (int i = gap; i < n; i++) {
            int key = a[i];
            int j = i;
            while (j >= gap && a[j-gap] > key) {
                a[j] = a[j-gap];
                j -= gap;
            }
            a[j] = key;
        }
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,4,13,3,12,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    shell_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}