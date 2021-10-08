#include "bits/stdc++.h"
using namespace std;

struct node {
    int is_end;
    map<char, node*> mp;

    node() {
        is_end = 0;
        for (int i = 0; i < 26; i++) mp['a' + i] = nullptr;
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root = new node;
    }

    void add(string s) {
        node* cur = root;
        for (char x : s) {
            if (cur->mp[x] == nullptr) cur->mp[x] = new node;
            cur = cur->mp[x];
        }
        cur->is_end = 1;
    }

    bool exists(string word) {
        node* cur = root;
        for (char x : word) {
            if (cur->mp[x] == 0) return 0;
            cur = cur->mp[x];
        }
        return cur->is_end;
    }

    bool startswith(string p) {
        node* cur = root;
        for (char x : p) {
            if (cur->mp[x] == 0) return 0;
            cur = cur->mp[x];
        }
        return 1;
    }
};

int main() {
#ifdef LOCAL
    freopen("/home/sammy/Documents/sublimeCode/input.txt", "r", stdin);
    //freopen("/home/sammy/Documents/sublimeCode/output.txt", "w", stdout);
#endif

    return 0 ;
}