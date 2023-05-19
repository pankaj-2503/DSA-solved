#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;

    //constructor
    TrieNode(char ch){
       data=ch;
       for(int i=0;i<26;i++){
        children[i]=NULL;
       }
       isTerminal=true;
    }
};

class Trie{
     public:
     TrieNode*root;
     //constructor
     Trie(){
        root=new TrieNode('\0');
     }

    void insertUtil(TrieNode*root,string word){
        if(word.length()==0) {
            root->isTerminal=true;
            return;
        }
        //assuming word to be caps
        int index=word[0]-'A';
        TrieNode*child;
        if(root->children[index]!=NULL){ //present
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]); //absent ,creating new node and moving its pointer 
            root->children[index]=child;
        }

        insertUtil(child,word.substr(1));  //Recursion
    }
    void insertWord(string word){
        insertUtil(root,word);
    }

     bool searchUtil(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'A';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else return false;

        return searchUtil(child,word.substr(1));
     }

     bool searchWord(string word){
        return searchUtil(root,word);
     }
};





int main(){
    Trie*t= new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    return 0;
}