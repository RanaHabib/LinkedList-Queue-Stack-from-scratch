#include "Queue.h"

int main() {
    // Default constructor
    Queue<int> test_def;
    // Paramterized constructor
    Queue<int> test_param(3, 3);
    //////////////////////////////////////////////////////////////////////////////
    // .size() test
    cout << "Queue with paramterized constructor's size: " << test_param.size() << endl;
    // .front() and .pop() test
    for (int i = 0; !test_param.empty(); i++) {
        cout << test_param.front() << ' ';
        test_param.pop();
    }
    cout << endl;
    //////////////////////////////////////////////////////////////////////////////
    // .push(T) test
    test_def.pop();
    for (int i = 0; i < 3; i++) test_def.push(i);

    for (int i = 0; !test_def.empty(); i++) {
        cout << test_def.front() << ' ';
        test_def.pop();
    }
    cout << endl;

    cout << "Queue with default constructor's size: " << test_def.size() << endl;
    //////////////////////////////////////////////////////////////////////////////
    // End of test; destructor called
    return 0;
}
