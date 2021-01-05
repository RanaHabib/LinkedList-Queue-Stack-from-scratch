
template <class T>
class stack {
private:
    T *StackElements;
    int StackSize=10;
public:
    stack();
    stack(T value, int InitialSize);
    ~stack();
    int & top();
    void pop();
    void push(T value);
    int size();
    void print();
};


