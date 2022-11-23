class TrieNode{
public: 
    TrieNode(){
        children.resize(26);
    }
public:
    std::vector<TrieNode*> children;
    bool is_word = false;
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        for(char c:word){
            int idx = c - 'a';
            if(tmp->children[idx]){
                tmp = tmp->children[idx];
            } else {
                TrieNode* next = new TrieNode();
                tmp->children[idx] = next;
                tmp = next;
            }
        }
        tmp->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = root;

        for(char c: word){
            int idx = c - 'a';
            if(tmp->children[idx]){
                tmp = tmp->children[idx];
            } else {
                return false;
            }
        }
        return tmp->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tmp = root;

        for(char c: prefix){
            int idx = c - 'a';
            if(tmp->children[idx]){
                tmp = tmp->children[idx];
            } else {
                return false;
            }
        }
        return true;
    }
    
public:
    TrieNode* root = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */