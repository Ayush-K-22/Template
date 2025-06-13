/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vb vector<bool>

class Trie {
private:
    struct Node {
        vector<int> next;
        int count, prefixCount;

        Node() {
            next.resize(26, -1);
            count = 0;
            prefixCount = 0;
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
            int idx = ch - 'a';
            if (trie[node].next[idx] == -1) {
                trie[node].next[idx] = trie.size();
                trie.push_back(Node());
            }
            node = trie[node].next[idx];
            trie[node].prefixCount++;
        }

        if (trie[node].count == 0) uniqueWordCount++;
        trie[node].count++;
        wordCount++;
    }

    void del(string &s) {
        int node = 0;
        vector<int> path = {0};
        for (char ch : s) {
            int idx = ch - 'a';
            if (trie[node].next[idx] == -1)
                return;
            node = trie[node].next[idx];
            path.push_back(node);
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
            int idx = ch - 'a';
            if (trie[node].next[idx] == -1)
                return 0;
            node = trie[node].next[idx];
        }
        return trie[node].count;
    }

    int prefCount(string &s) {
        int node = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            if (trie[node].next[idx] == -1)
                return 0;
            node = trie[node].next[idx];
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}