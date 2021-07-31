#include"bits/stdc++.h"

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Trie {

private:
    TrieNode * root;
public:
                    Trie    ();
    void            Insert  ( std::string word);
    std::string     Search  ( std::string key);
    bool            Search  ( std::string key);

};

Trie::Trie() {
    root = new TrieNode();
}

void Trie::Insert( std::string word) {

    TrieNode* current = root;

    for(char c:word)
    {
        int index = c - 'a'; // potienial break
        if(!current->children[index])
        {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];

    }
    current->isEnd = true;
}

std::string Trie::Search(std:: string key) {

    TrieNode* current  = root;
    for(int i = 0; i<key.size();i++) {
        int index = key[i] - 'a';
        if(current->isEnd == true)
            return key.substr(0,i);
        if(!current->children[index])
            return key;
        current = current->children[index];
        
    }
    return key;
}

bool Trie::Search(std::string key)
{
    TrieNode* current = root;

    for(int i = 0; i<key.size();i++)
    {
        int index = key[i] - 'a';
        if(current->isEnd == true)
            return true;
        if(!current->children[index])
            return false;
        current = current->children[index];
    }
    return current->isEnd == true;
}


std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {

    Trie trie;
    for(std::string word :dictionary)
    {
        trie.Insert(word);
    }
    std::string res, cur;
        for(int i = 0, j; i <= sentence.size(); i++) {
            if(i < sentence.size() && !isspace(sentence[i]))
                cur += sentence[i];
            else {
                res += trie.Search(cur) + ' ';
                cur.clear();
            }
        }
    return res.substr(0, res.length() - 1);
}

int main() {
    std::string sentence = "the cattle was rattled by the battery";
    std::vector<std::string> values = {"cat","bat","rat"};

    std::string result = replaceWords(values,sentence);
    std::cout<<result;
    return 0;
}
