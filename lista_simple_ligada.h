#ifndef LISTA_SIMPLE_LIGADA_H
#define LISTA_SIMPLE_LIGADA_H
#include "Usuario.h"
template<class T>
class Node {
public:
    T value;
    Node<T> *next;
    Node();
    explicit Node(T val);
};

template<class T>
Node<T>::Node() {
    next = nullptr;
}

template<class T>
Node<T>::Node(T val) {
    value = val;
    next = nullptr;
}

template<class E>
class LinkedList {
private:
    Node<E> *head;
    int s;
    string area;
public:
    void setarea(string area){
        this->area=area;
    }
    string getarea(){
        return area;
    }
    LinkedList();
    void add(E e);
    void addFirst(E e);
    void addLast(E e);
    void remove(E e);
    bool contains(E e);
    string print();
    string toFile();
};

template<class E>
LinkedList<E>::LinkedList() {
    head = nullptr;
    s = 0;
}
template<class E>
void LinkedList<E>::addFirst(E e) {
    auto *newNode = new Node<E>(e);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    s++;
}

template<class E>
void LinkedList<E>::add(E e) {
    if(contains(e))
        return;
    auto *newNode = new Node<E>(e);
    if (head == nullptr) {
        head = newNode;
        s++;
        return;
    }
    Node<E> *current = head;
    Node<E> *tmp;
    do {
        tmp = current;
        current = current->next;
    } while (current != nullptr);
    tmp->next = newNode;
    s++;
}

template<class E>
void LinkedList<E>::remove(E e) {
    Node<E> *current = head;
    Node<E> *prev = nullptr;
    bool found = false;
    if (current == nullptr) {
        cerr << "Err" << endl;
        return;
    }
    do {
        if (current->value == e) {
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    } while (current != nullptr);
    if (!found) {
        cerr << "Err" << e << endl;
        return;
    }
    if (current == head) {
        prev = head;
        head = current->next;
        delete prev;
        return;
    }
    if (current->next == nullptr) {
        prev->next = nullptr;
        delete current;
        return;
    }
    prev->next = current->next;
    delete current;
    s--;
}

template<class E>
string LinkedList<E>::print() {
    string tostring;
    Node<E> *current = head;
    ifstream fin("Usuarios.bin",ios::binary);
    if(!fin.is_open())
        return area+":\nNoFile";
    Usuario obj;
    tostring= area + ":\n" ;
    while (current != nullptr) {
        fin.seekg(current->value);
        fin.read((char*)(&obj),sizeof(Usuario));
        tostring += obj.getnombre()+"\n";
        current = current->next;
    }
    return tostring;
}

template<class E>
string LinkedList<E>::toFile() {
    string tostring;
    Node<E> *current = head;
    while (current != nullptr) {
        tostring += to_string(current->value)+"\n";
        current = current->next;
    }
    return tostring;
}

template<class E>
void LinkedList<E>::addLast(E e) {
    add(e);
}

template<class E>
bool LinkedList<E>::contains(E e) {
    Node<E> *current = head;

    while (current != nullptr) {
        if (current->value == e) {
            return true;
        }
        current = current->next;
    }
    return false;
}
#endif // LISTA_SIMPLE_LIGADA_H
