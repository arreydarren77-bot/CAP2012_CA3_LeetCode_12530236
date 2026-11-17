#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        int size = q.size();

        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.top() << endl;

    cout << "Removed Element: " << st.pop() << endl;

    cout << "New Top: " << st.top();

    return 0;
}
