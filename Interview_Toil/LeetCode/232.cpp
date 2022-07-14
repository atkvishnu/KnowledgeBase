// Sol 1:
// class MyQueue {
// public:
//     MyQueue() {}

//     void push(int x) {
//         s1.push(x);
//     }

//     int pop() {
//         shiftStack();
//         int x = s2.top();
//         s2.pop();
//         return x;
//     }

//     int peek() {
//         shiftStack();
//         return s2.top();
//     }

//     bool empty() {
//         if(s1.empty() && s2.empty()) return true;
//         else return false;
//     }
//     void shiftStack() {
//         if (!s2.empty()) return;
//         while (!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//     }
// private:
//     stack<int> s1;
//     stack<int> s2;
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Sol 2:
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stack<int> tmp;
        while (!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int val = st.top();
        st.pop();
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        return st.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return st.empty();
    }

private:
    stack<int> st;
};
