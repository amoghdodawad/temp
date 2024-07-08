#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() {
            isEnd = false;
            children.resize(26,NULL);
        }
};

class Trie{
    TrieNode *root;
    public:
        Trie(){
            this->root = new TrieNode();
        }
        void insertWord(string word){
            TrieNode *temp = this->root;
            for(int i=0;i<word.length();i++){
                if(temp->children[word[i]-'a'] == NULL) temp->children[word[i]-'a'] = new TrieNode(); 
                temp = temp->children[word[i]-'a'];
            }
            temp->isEnd = true;
        }

        bool searchWord(string word){
            TrieNode *temp = this->root;
            for(int i=0;i<word.length();i++){
                if(temp->children[word[i]-'a'] == NULL) return false;
                temp = temp->children[word[i]-'a'];
            }
            return temp->isEnd;
        }
};

int main(){
    Trie t;
    t.insertWord("apple");
    // t.insertWord("app");

    cout << t.searchWord("apple"); // return true;
    cout << t.searchWord("app"); // return false, if uncommented returns true;

    return 0;

}