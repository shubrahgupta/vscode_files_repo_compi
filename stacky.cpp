#include<bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> s;

    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }

    int getMin()
    {
        int x = s.top();
        int min = s.top();
        vector<int> y;
        while (!s.empty())
        {
            x = s.top();
            if (x <= min)
            {
                min = x;
            }

            y.push_back(x);
            s.pop();
        }
        for (int i = y.size()-1; i >= 0; i--)
        {
            s.push(y[i]);
        }
        return min;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    // cout << minStack->getMin() << endl; // return -3
    // minStack->pop();


    // cout << minStack->top() << endl; // return 0
    // cout << minStack->getMin() << endl; // return -2
    while(!minStack->empty()) {
        cout << minStack->top() << endl;
        cout << "Min: " << minStack->getMin() << endl;
        minStack->pop();
    }

}
