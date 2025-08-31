#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct Node {
        int left, right, count, prefixCount;

        Node() {
            left = -1, right = -1;
            count = 0, prefixCount = 0;
        }
    };

    vector<Node> trie;
    int wordCount = 0;
    int uniqueWordCount = 0;

public:
    Trie() {
        trie.resize(1);
    }

    void add(string &s) {
        int node = 0;
        for (char ch : s) {
            if (ch == '0') {
                if (trie[node].left == -1) {
                    trie[node].left = trie.size();
                    trie.push_back(Node());
                }
                node = trie[node].left;
                trie[node].prefixCount++;
            } else {
                if (trie[node].right == -1) {
                    trie[node].right = trie.size();
                    trie.push_back(Node());
                }
                node = trie[node].right;
                trie[node].prefixCount++;
            }
        }

        if (trie[node].count == 0) uniqueWordCount++;
        trie[node].count++;
        wordCount++;
    }

    void del(string &s) {
        int node = 0;
        vector<int> path = {0};
        for (char ch : s) {
            if (ch == '0') {
                if (trie[node].left == -1)
                    return;
                node = trie[node].left;
                path.push_back(node);
            } else {
                if (trie[node].right == -1)
                    return;
                node = trie[node].right;
                path.push_back(node);
            }
        }

        if (trie[node].count == 0) return;

        trie[node].count--;
        wordCount--;
        if (trie[node].count == 0) uniqueWordCount--;

        for (int i = 1; i < path.size(); ++i)
            trie[path[i]].prefixCount--;
    }

    int count(string &s) {
        int node = 0;
        for (char ch : s) {
            if (ch == '0') {
                if (trie[node].left == -1)
                    return 0;
                node = trie[node].left;
            } else {
                if (trie[node].right == -1)
                    return 0;
                node = trie[node].right;
            }
        }
        return trie[node].count;
    }

    int prefCount(string &s) {
        int node = 0;
        for (char ch : s) {
            if (ch == '0'){
                if (trie[node].left == -1)
                    return 0;
                node = trie[node].left;
            } else {
                if (trie[node].right == -1)
                    return 0;
                node = trie[node].right;
            }
        }
        return trie[node].prefixCount;
    }

    int totalWords() {
        return wordCount;
    }

    int totalUniqueWords() {
        return uniqueWordCount;
    }

    void clear() {
        trie.clear();
        trie.resize(1);
        wordCount = 0;
        uniqueWordCount = 0;
    }
};