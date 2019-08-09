#include <cstdio>
#include <set>
#include <stack>
using namespace std;
 multiset<int> s1,s2;
stack<int> st;
char s[100];
int get() {
    return *s1.rbegin();
}

void add(int x) { //add x

    if (s1.size() == s2.size()) {
        s2.insert(x);
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }
    else {
        s1.insert(x);
        s2.insert(*s1.rbegin());
        s1.erase(s1.find(*s1.rbegin()));
    }

}

void remove(int x) {
    multiset<int>::iterator t1 = s1.find(x),t2 = s2.find(x);
    if (s1.size() == s2.size()) {
        if (t2 != s2.end()) {
            s2.erase(t2);
        }
        else {
            s1.erase(t1);
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    }
    else if (t1 != s1.end()) {
        s1.erase(t1);
    }
    else {
        s2.erase(t2);
        s2.insert(*s1.rbegin());
        s1.erase(s1.find(*s1.rbegin()));
    }
}

int main() {
    int n;

    for (scanf("%d",&n);n;--n) {
        scanf("%s",s);
        if (s[1] == 'u') {
            int x;
            scanf("%d",&x);
            st.push(x);
            add(x);
        }
        else if (st.empty()) {
            puts("Invalid");
        }
        else if (s[1] == 'o') {
            printf("%d\n",st.top());
            remove(st.top());
            st.pop();
        }
        else {
            printf("%d\n",get());
        }

    }
    return 0;
}
