#pragma once
#include <iostream>
using namespace std;


const int ALPHABET_SIZE = 26;
/// <summary>
/// class implements a trie Tree
/// </summary>
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
    /// <summary>
    /// destructor
    /// </summary>
    ~Trie();
    /// <summary>
    /// recursive function to delete all dynamic allocation in a subtree rooted in a node
    /// </summary>
    /// <param name="node - ">  root of subtree</param>
    void clear(TrieNode* node);
    /// <summary>
    /// add a word to a trie Tree
    /// </summary>
    /// <param name="key - "> word to add</param>
    void addWord(string key );
    /// <summary>
    /// delete a word from a trie Tree
    /// </summary>
    /// <param name="key - "> word to delete</param>
    /// <returns> bool - true if deletion was successful, otherwise, false </returns>
    bool deleteWord(string key);
    /// <summary>
    /// search if a word exsist in a trie Tree
    /// </summary>
    /// <param name="key - ">word to search for in tree </param>
    /// <returns> bool - true if word exsist , otherwise, false</returns>
    bool searchWord(string key) { return searchWord(key, root); }
    /// <summary>
    /// print auto Suggestions to fill, to a prefix entered by user
    /// </summary>
    /// <param name="key - "> prefix </param>
    /// <returns> number of suggestions in tree </returns>
    int printAutoSuggestions(string key);
private:
    /// <summary>
    /// private method - called by searchWord public method, sends root of tree to begin
    /// search of word from
    /// </summary>
    /// <param name="key - "> word to search for in tree</param>
    /// <param name="node - "> root of the tree</param>
    /// <returns> bool - true if word was found, otherwise false</returns>
    bool searchWord(string key, TrieNode* node);
    /// <summary>
    /// check if a node in a trie Tree has Children
    /// </summary>
    /// <param name=" node - "> node to check </param>
    /// <returns>bool - true if node has any children </returns>
    bool hasChildren(TrieNode* node);
    /// <summary>
    /// private method called by printAutoSuggestions()
    /// recursive function to print all subtree rooted in a node
    /// </summary>
    /// <param name="node - "> node to print all subtrees from </param>
    /// <param name="wordsArray - "> array to copy word from tree to print</param>
    /// <param name="position - ">position of index currently in array</param>
    /// <param name="count - "> count of printed words by function </param>
    /// <returns> total numbers of words printed</returns>
    int printAllWordFromPrefix(TrieNode*, char* wordsArray,int position, int count =0 );

};