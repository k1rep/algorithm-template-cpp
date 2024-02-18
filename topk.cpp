//
// Created on 2024/2/18.
//
#include <iostream>
#include <vector>
using namespace std;
class TopK{
public:
    vector<int> nums;
    int k;
    TopK():nums({}), k(0){}
    // 全局排序
    int getKth_sort(){
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    // 冒泡局部排序
    int getKth_bubble(){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < nums.size() - i - 1; j++){
                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums[nums.size() - k];
    }
    // 堆排序
    int getKth_nth_element(){
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
        return nums[nums.size() - k];
    }
    // 随机选择
    int getKth_random_select(int l, int r, int k){
        if(l == r){
            return nums[l];
        }
        int pivot = [this](int l, int r){
            int pivot = nums[l];
            while(l < r){
                while(l < r && nums[r] >= pivot){
                    r--;
                }
                nums[l] = nums[r];
                while(l < r && nums[l] <= pivot){
                    l++;
                }
                nums[r] = nums[l];
            }
            nums[l] = pivot;
            return l;
        }(l, r);
        int sl = pivot - l + 1;
        if(k == sl){
            return nums[nums.size()-pivot-1];
        }else if(k < sl){
            return getKth_random_select(l, pivot - 1, k);
        }else{
            return getKth_random_select(pivot + 1, r, k - sl);
        }
    }
};
int main(){
    TopK topK;
    topK.nums = {3,2,1,5,6,4};
    topK.k = 2;
    cout<<topK.getKth_sort()<<endl;
    cout<<topK.getKth_bubble()<<endl;
    cout<<topK.getKth_nth_element()<<endl;
    cout<<topK.getKth_random_select(0, topK.nums.size() - 1, topK.k)<<endl;
    return 0;
}