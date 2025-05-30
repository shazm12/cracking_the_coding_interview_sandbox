#include <bits/stdc++.h>
using namespace std;


void sortInsert(stack<int> &st, int x) {
    if(st.empty() || x > st.top()) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    sortInsert(st,x);
    st.push(temp);

}
 

void sort(stack<int> &st) {
    if(!st.empty()) {
        int x = st.top();
        st.pop();
        sort(st);
        sortInsert(st,x);
    }
}

int main() {
stack<int> st;

    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);

    sort(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
