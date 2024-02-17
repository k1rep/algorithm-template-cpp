//
// Created on 2024/2/17.
//
#include <iostream>
using namespace std;
void counting_sort(int a[], int n){
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    int *count = new int[max+1];
    for(int i=0;i<=max;i++){
        count[i] = 0;
    }
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i] += count[i-1];
    }
    int *temp = new int[n];
    for(int i=n-1;i>=0;i--){
        temp[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for(int i=0;i<n;i++){
        a[i] = temp[i];
    }
    delete[] count;
    delete[] temp;
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,4,13,3,12,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    counting_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}