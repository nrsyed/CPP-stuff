#include <iostream>

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
    length = 0;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node* node = head;
    Node* next;
    while (node) {
        next = node->next;
        delete node;
        node = next;
    }
}

template <class T>
int SinglyLinkedList<T>::size() {
    return length;
}

template <class T>
void SinglyLinkedList<T>::print() {
    Node* node = head;
    while (node) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <class T>
void SinglyLinkedList<T>::insert(int index, T item) {
    index = index < 0 ? length + index : index;
    if (index < 0 || index > length)
        throw std::out_of_range("List index out of range");
    if (!head) {
        head = new Node(item);
    } else {
        Node *node = head;
        Node **pp = &head;
        int i = 0;
        while (i < index) {
            pp = &(node->next);
            node = node->next;
            i++;
        }
        *pp = new Node(item);
        ((*pp)->next) = node;
    }
    length++;
}

template <class T>
void SinglyLinkedList<T>::push(T item) {
    insert(length, item);
}

template <class T>
T SinglyLinkedList<T>::remove(int index) {
    index = index < 0 ? length + index : index;
    if (index < 0 || index >= length || !head)
        throw std::out_of_range("List index out of range");

    Node *node = head;
    Node **pp = &head;
    int i = 0;
    while (i < index) {
        pp = &(node->next);
        node = node->next;
        i++;
    }
    *pp = node->next;
    length--;
    T removedData = node->data;
    delete node;
    return removedData;
}

template <class T>
T SinglyLinkedList<T>::pop() {
    return remove(length - 1);
}

template <class T>
void SinglyLinkedList<T>::swap(int index1, int index2) {
    index1 = index1 < 0 ? length + index1 : index1;
    index2 = index2 < 0 ? length + index2 : index2;
    if (index1 < 0 || index1 >= length || index2 < 0 || index2 >= length) {
        throw std::out_of_range("List index out of range");
    } else if (index1 == index2) {
        return;
    }

    int indexLow = index1 < index2 ? index1 : index2;
    int indexHigh = indexLow == index1 ? index2 : index1;

    Node* ptrLow = head;
    Node* ptrHigh = head;
    Node** ppLow = &head;
    Node** ppHigh = &head;
    Node* temp;

    int i;
    for (i = 0; i < indexLow; i++) {
        ppLow = &(ptrLow->next);
        ptrLow = ptrLow->next;
    }

    ptrHigh = ptrLow;
    ppHigh = ppLow;
    for (; i < indexHigh; i++) {
        ppHigh = &(ptrHigh->next);
        ptrHigh = ptrHigh->next;
    }

    temp = ptrLow->next;
    *ppLow = ptrHigh;
    ptrLow->next = ptrHigh->next;
    if (temp == ptrHigh) {
        ptrHigh->next = ptrLow;
    } else {
        ptrHigh->next = temp;
        *ppHigh = ptrLow;
    }
}

template <class T>
const T& SinglyLinkedList<T>::operator[](int index) const {
    Node* node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

template <class T>
T& SinglyLinkedList<T>::operator[](int index) {
    Node* node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}
