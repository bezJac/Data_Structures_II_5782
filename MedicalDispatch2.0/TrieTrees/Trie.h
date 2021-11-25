#pragma once
#include <iostream>
#include <vector>
using namespace std;
const int ALPHABET_SIZE = 26;
class Trie
{
public:
    class TrieNode
    {
    public:
       
        TrieNode* children [ALPHABET_SIZE] ;
        TrieNode* parent;
        // isEndOfWord is true if the node
        // represents end of a word
        bool isEndOfWord;
    public:
        TrieNode() { parent = NULL; isEndOfWord = false; };
        TrieNode(TrieNode* p) { parent = p; isEndOfWord = false;}
    };
    TrieNode* root;
public:
    Trie();
    void addWord(string);
    bool deleteWord(string);
    bool searchWord(string key) { return searchWord(key, root); }
    int printAutoSuggestions(string key);
private:
    bool searchWord(string, TrieNode*);
    bool hasChildren(TrieNode*);
    int printAllWordFromPrefix(TrieNode*, char* wordsArray,int position, int count =0 );

};