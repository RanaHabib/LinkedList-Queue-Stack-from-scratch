
template <class T>
class List {
public:
    class Node{
    public:
        Node(T value){
            data = value;
        }
        T data;
        Node *next;
        Node *previous;
    };

    class iterator{
    private:
        Node *ptr;
    public:
        void operator++();
        void operator--();
        T &operator*();
        bool operator==( iterator&it);
        Node *getPtr() ;
        void setPtr(Node *ptr);
    };

    List();
    List(T value, int InitialSize);
    ~List();
    int size();
    void insert(T value, iterator position);
    void push_back(T value);
    List<T>::iterator erase(iterator position);
    List<T>& operator = (const List<T> &another_list);
    List<T>::iterator begin();
    List<T>::iterator end();
    Node *getHead() const;
    Node *getTail() const;
    int getListSize() const;
    void print();

private:
    Node *DummyNode = nullptr;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *newNode = nullptr;
    Node *previousNode = nullptr;
    Node *currentNode = nullptr;
    Node *nextNode = nullptr;
    int ListSize = 0;
};
