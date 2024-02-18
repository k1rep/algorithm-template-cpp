//
// Created on 2024/2/18.
//
#include <iostream>
#include <vector>
using namespace std;

class KMP{
private:
    vector<int> next;
    void get_next(const string& p, vector<int>& next){
        int n = p.size();
        next[0] = 0;
        for(int i=1,j=0;i<n;i++){
            while(j>0 && p[i]!=p[j]) j = next[j-1];
            if(p[i] == p[j]) ++j;
            next[i] = j;
        }
    }
public:
    int find_str(const string& s, const string& p){
        int m = s.size(), n = p.size();
        next.resize(n);
        // 计算next数组
        get_next(p, next);
        int i = 0;
        for(int j=0;j<m;j++){
            // 不匹配时按照next数组回溯
            while(i>0 && s[j]!=p[i]) i = next[i-1];
            // 匹配时模式串指针后移
            if(s[j] == p[i]) ++i;
            // 完全匹配时返回下标
            if(i == n) return j - n + 1;
        }
        return -1;
    }
};
int main(){
    KMP kmp;
    string s = "ababababca";
    string p = "abababca";
    cout<<kmp.find_str(s, p)<<endl;
    return 0;
}
