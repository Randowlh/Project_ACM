#include <iostream>
#include <string>
using namespace std;
/*
class Word{
    public:
    string word;
    int prob;
    Word(string s, int i): word(s), prob(i){

    }
    Word(){

    }
};
*/
//Word dict[1000];

//Word wNull = Word();

class node{
public:
    node* suc[8];
    int maxProb;
    //int depth;
    string maxWord;
    node() {
        //depth = 0;
        maxProb = 0;
        maxWord = "";
        for(int i = 0; i < 8; i++) suc[i] = NULL;
    }
};

class preNode{
public:
    preNode* suc[26];
    int prob;
    preNode(int p): prob(p){
        for(int i = 0; i < 26; i++) suc[i] = NULL;
    }
};

//preNode* dicts[1000];

int toInt(char c){
    if(c >= 'a' && c <= 'c') return 2;
    if(c >= 'd' && c <= 'f') return 3;
    if(c >= 'g' && c <= 'i') return 4;
    if(c >= 'j' && c <= 'l') return 5;
    if(c >= 'm' && c <= 'o') return 6;
    if(c >= 'p' && c <= 's') return 7;
    if(c >= 't' && c <= 'v') return 8;
    if(c >= 'w' && c <= 'z') return 9;
    return 1;
}

int toIdx(int c){
    return toInt(c + 'a');
}

void rct(preNode* pR, node* r, string s = ""){
    for(int i = 0; i < 26; i++){
        if(pR->suc[i] == NULL) continue;
        int idx = toIdx(i) - 2;
        //cout << idx << endl;
        string news = s + (char)(i+'a');
        //cout << news << endl;
        preNode* newpr = pR->suc[i];
        //cout << newpr->prob << endl;
        node* newr = r->suc[idx];
        if(newr == NULL){
            r->suc[idx] = new node();
            newr = r->suc[idx];
            newr->maxProb = newpr->prob;
            newr->maxWord = news;
        }
        else{
            if(newpr->prob > newr->maxProb){
                newr->maxProb = newpr->prob;
                newr->maxWord = news;
            }
        }
        rct(newpr, newr, news);
    }
}

int main() {

    int cases;
    cin >> cases;
    for(int ii = 0; ii < cases; ii++){
        cout << "Scenario #" << (ii+1) << ":" << endl;
        int numW;
        cin >> numW;
        node* root = new node();
        preNode* preRoot = new preNode(0);
        for(int jj = 0; jj < numW; jj++){
            int prob; string s;
            cin >> s >> prob;
            preNode* cur = preRoot;
            int len = s.length();
            for(int i = 0; i < len; i++){
                int idx = s[i] - 'a';
                if(cur->suc[idx] == NULL){
                    cur->suc[idx] = new preNode(prob);
                }
                else{
                    cur->suc[idx]->prob += prob;
                }
                cur = cur->suc[idx];
            }
        }
        rct(preRoot, root);
        int numT;
        cin >> numT;
        for(int j = 0; j < numT; j++){
            string s;
            cin >> s;
            int len = s.length() - 1;
            bool can = true;
            node* cur = root;
            for(int i = 0; i < len; i++){
                int idx = s[i] - '2';
                if(can == true && cur->suc[idx] == NULL) can = false;
                if(can == false) {
                    cout << "MANUALLY" << endl;
                    continue;
                }
                cout << cur->suc[idx]->maxWord << endl;
                cur = cur->suc[idx];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}