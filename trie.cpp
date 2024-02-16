//
// Created on 2022/5/13.
//
#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode():children(26,nullptr),isEnd(false){}
};

class Trie{
public:
    Trie(){
        root = new TrieNode();
    }

    // 插入一个单词到字典树
    void insert(const string &word) {
        TrieNode* cur = root;
        for (char c : word) {
            int index = c - 'a'; // 计算字符的索引
            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isEnd = true; // 标记单词结束的节点
    }

    bool find(const string &word){
        TrieNode* cur = root;
        for (char c : word) {
            int index = c - 'a';
            if (cur->children[index] == nullptr) {
                return false;
            }
            cur = cur->children[index];
        }
        return cur != nullptr && cur->isEnd;
    }
private:
    TrieNode* root;
};
int main(){
    Trie trie;
    trie.insert("apple");
    cout<<trie.find("apple")<<endl;
    cout<<trie.find("app")<<endl;
    return 0;
}