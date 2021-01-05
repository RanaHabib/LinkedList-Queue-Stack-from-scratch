#include "List.h"
#include <iostream>
using namespace std;
template<class T>
List<T>::List(){
    DummyNode = new Node(0);
    DummyNode->previous = tail;
    DummyNode->next = nullptr;
    head = nullptr;
    tail = nullptr;

}

template<class T>
List<T>::List(T value, int InitialSize){
    DummyNode = new Node(0);
    DummyNode->previous = tail;
    DummyNode->next = nullptr;
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < InitialSize; i++) {
        push_back(value);
    }
}

template<class T>
List<T>::~List() {
    Node * tempNode;

    while(head!=NULL){
        tempNode = head;
        head = head->next;
        delete(tempNode);
    }
    ListSize = 0;
    head = NULL;
    tail = NULL;
    previousNode = NULL;
    currentNode = NULL;
    newNode = NULL;
    nextNode = NULL;
    delete (DummyNode);
}

template<class T>
int List<T>::size() {
    return ListSize;
}

template<class T>
void List<T>::insert(T value, iterator position) {
    ListSize++;
    newNode = new Node(value);

    iterator it = begin();
    currentNode = head;

    while(!(it==position)) {
        ++it;
        if(currentNode != tail){
            previousNode = currentNode;
            currentNode = currentNode->next;

        }
    }

    if(currentNode == head){
        newNode->next = head;
        newNode->previous = nullptr;
        head = newNode;

    }
    else if(currentNode == tail){
        newNode->next = tail;
        newNode->previous = tail->previous;
        previousNode->next = newNode;
        tail->previous = newNode;
    }
    else{
        previousNode->next = newNode;
        newNode->previous = previousNode;
        newNode->next = currentNode;

    }
    tail->next = DummyNode;
    DummyNode->previous = tail;
}

template<class T>
List<T> &List<T>::operator=(const List<T> &another_list) {
    newNode = another_list.getHead();
    previousNode = newNode;
    for (int i = 0; i < another_list.ListSize; ++i) {
        this->push_back(newNode->data);
        newNode = previousNode;
        newNode = newNode->next;
        previousNode = newNode;
    }

    return *this;
}

template<class T>
class List<T>::iterator List<T>::erase(List::iterator position) {

    iterator it = begin();
    currentNode = head;

    while(!(it == position)) {
        ++it;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    try{
        if(currentNode == DummyNode) throw "cannot erase, out of index.\n";
        else{
            ListSize--;
            if(currentNode == tail){
                tail = currentNode->previous;
                tail->next = nullptr;
            }
            else if(currentNode == head){
                head = head->next;
            }
            else{
                previousNode->next = currentNode->next;
            }
        }
    }catch (...){
        cout<<"cannot erase, out of index.\n";
    }


    tail->next = DummyNode;
    DummyNode->previous = tail;
}

template<class T>
class List<T>::iterator List<T>::begin() {
    iterator it;
    it.setPtr(head);
    return it;
}

template<class T>
class List<T>::iterator List<T>::end() {
    iterator it;
    it.setPtr(DummyNode);
    return it;
}

template<class T>
class List<T>::Node *List<T>::getHead() const {
    return head;
}

template<class T>
class List<T>::Node *List<T>::getTail() const {
    return tail;
}

template<class T>
int List<T>::getListSize() const {
    return ListSize;
}

template<class T>
void List<T>::push_back(T value) {
    ListSize++;
    newNode = new Node(value);

    newNode->previous = tail;


    if (head == nullptr)
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;

    tail->next = DummyNode;
    DummyNode->previous = tail;
}

template<class T>
bool List<T>::iterator::operator==( List::iterator &it) {
    return this->ptr == it.ptr;
}

template<class T>
class List<T>::Node *List<T>::iterator::getPtr()  {
    return ptr;
}

template<class T>
void List<T>::iterator::setPtr(List::Node *ptr) {
    iterator::ptr = ptr;
}

template<class T>
void List<T>::iterator::operator++() {
    try {
        if(this->ptr->next == nullptr){
            throw "Out Of Index, already at end";
        }
        else{
            this->ptr = this->ptr->next;
        }
    }
    catch (...){
        cout<<"Out Of Index, already at end\n";
    }
}

template<class T>
void List<T>::iterator::operator--() {
    try {
        if(this->ptr->previous == nullptr){
            throw "Out Of Index, already at begin";
        }
        else{
            this->ptr = this->ptr->previous;
        }
    }
    catch (...){
        cout<<"Out Of Index, already at begin\n";
    }

}

template<class T>
T &List<T>::iterator::operator*() {
    return this->ptr->data;
}

template<class T>
void List<T>::print(){
    cout<<"Printing list\n";

    currentNode = head;
    for (int i = 0; i < ListSize; ++i) {
        cout<<currentNode->data<<"  ";
        currentNode = currentNode->next;
    }
    cout<<endl;
}

int main() {

    List<int> list1(2,2);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    cout<<"Size: "<<list1.size()<<endl;
    List<int>::iterator it1 = list1.begin();
    List<int>::iterator it2 = list1.end();
    cout<<*it1<<endl;
    cout<<*it2<<endl;

    list1.insert(77,it1);
    list1.print();


    //erasing normally.
    list1.erase(it1);
    list1.print();


    //----will throw exception-----
    ++it1;++it1;++it1;++it1;++it1;++it1;
    --it2;--it2;--it2;--it2;--it2;--it2;

    //erasing with exception.
    list1.erase(it1);
    list1.print();


    List<int> list2;
    list2 = list1;
    cout<<"Printing list 2: \n";
    list2.print();

    //editing list2
    list2.push_back(10);
    list2.print();

    List<int>::iterator iterator1 = list2.begin();
    int x = *iterator1;
    cout<<x<<endl;

    *iterator1 = 123;
    list2.print();

    List<int>::iterator iterator2 = list2.begin();
    iterator1 == iterator2? cout<<"EQUAL\n":cout<<"NOT EQUAL\n";
    return 0;
}