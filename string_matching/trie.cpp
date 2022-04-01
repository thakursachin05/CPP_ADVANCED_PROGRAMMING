#include<bits/stdc++.h>

using namespace std;

int cnt = 0;

struct node {
    node *nxt[26];
    bool is_end;
    node(){
        for(int i=0;i<26;i++) nxt[i] = NULL;
            is_end = false;
            cnt++;
    }
};
node *root;

void insert_trie(string s){
    node *cur = root;
    for(int i=0;i<s.size();i++){
        int imap = s[i] - 'a';
        //new node
        if(cur->nxt[imap] == NULL){
            cur->nxt[imap] = new node();

        }
        //goto that node
        cur = cur->nxt[imap];
    }
    // cur->last node
    cur->is_end= true;

}

// O(|s|)
bool search_trie(string s){
    node *cur = root;
    for(int i=0;i<s.size();i++){
        int imap = s[i] - 'a';
        //new node
        if(cur->nxt[imap] == NULL) return false;
        //goto that node
        cur = cur->nxt[imap];
    }
    // cur->last node
    return cur->is_end;
}

int main() {
    
    root = new node();

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert_trie(s);
    }
    if(search_trie("apar")){
        cout<<"found"<<endl;
    }
    else {
        cout<<"Not found"<<endl;
    }
    cout<<cnt;

    return 0;
}