#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>  

using namespace std;

struct TrieNode {
    bool isEndOfWord = false;
    unordered_map<char, TrieNode*> children;
    int frequency = 0;  
};

class Trie {
private:
    TrieNode* root;

    // Helper: DFS to collect words from current node
    void dfs(TrieNode* node, const string& prefix, vector<pair<string, int>>& results) {
        if (node->isEndOfWord) {
            results.push_back(make_pair(prefix, node->frequency));
        }
        for (unordered_map<char, TrieNode*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
            dfs(it->second, prefix + it->first, results);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (size_t i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        node->frequency++;  // Increase frequency if inserted again
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (size_t i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Suggest top K words with given prefix
    vector<string> suggest(const string& prefix, int k = 5) {
        TrieNode* node = root;
        for (size_t i = 0; i < prefix.size(); ++i) {
            char ch = prefix[i];
            if (!node->children.count(ch))
                return vector<string>();  // no suggestions
            node = node->children[ch];
        }

        vector<pair<string, int>> results;
        dfs(node, prefix, results);

        // Sort by frequency descending
        sort(results.begin(), results.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });

        vector<string> suggestions;
        for (size_t i = 0; i < results.size() && i < (size_t)k; ++i) {
            suggestions.push_back(results[i].first);
        }
        return suggestions;
    }
};

int main() {
    Trie trie;

    // Sample dataset
    vector<string> words = {
        "code", "coder", "coding", "codeforces", "codex",
        "cooking", "cook", "cool", "company", "compare"
    };

    // Insert into trie
    for (size_t i = 0; i < words.size(); ++i) {
        trie.insert(words[i]);
    }

    string prefix;
    cout << "Enter prefix to autocomplete (or type 'exit'): ";
    while (cin >> prefix && prefix != "exit") {
        vector<string> suggestions = trie.suggest(prefix);
        if (suggestions.empty()) {
            cout << "No suggestions found.\n";
        } else {
            cout << "Suggestions:\n";
            for (size_t i = 0; i < suggestions.size(); ++i) {
                cout << " - " << suggestions[i] << '\n';
            }
        }
        cout << "\nEnter another prefix (or type 'exit'): ";
    }

    return 0;
}
