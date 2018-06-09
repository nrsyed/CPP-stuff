#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/*!
@brief Simple templatized implementation of a singly linked list.
*/
template <class T>
class SinglyLinkedList {
    private:
    struct Node {
        T data;
        Node *next;
        Node(T x) : data(x), next(nullptr) {};
    };
    Node *head;
    int length;

    public:

    /*! @brief Return the item at \p index.

        Example:
        @code
        SinglyLinkedList<int> s;
        s.push(10);
        s.push(12);
        int x = s[1];
        @endcode

        @param index: Index of item to return.
        @return Reference to item.
    */
    const T& operator[](int index) const;

    /*! @brief Modify the item at \p index.
        
        Example:
        @code
        SinglyLinkedList<int> s;
        s.push(10);
        s.push(12);
        s[1] = 5;
        @endcode

        @param index: Index of item to modify.
        @return Reference to item.
    */
    T& operator[](int index);

    /*! @brief Constructor for a new list.

        Specify type in declaration, e.g.:
        @code
        SinglyLinkedList<int> s;
        @endcode
    */
    SinglyLinkedList();

    ~SinglyLinkedList();

    /*! @brief Returns the size of the list.
        @return Number of elements in the list.
    */
    int size(void);

    /*! @brief Prints each element of the list to stdout.
        
        Requires the type of list members to be compatible with stream output
        operator ("<<").
    */
    void print(void);

    /*! @brief Inserts a new item at the given index.
        @param index: Index at which to insert item.
        @param item: Item to insert.
    */
    void insert(int index, T item);

    /*! @brief Appends a new item to the end of the list.
        @param item: Item to append.
    */
    void push(T item);

    /*! @brief Removes and returns the item at the given index.
        @param index: Index of the item to remove.
        @return The item at \p index that was removed.
    */
    T remove(int index);

    /*! @brief Removes and returns the last item in the list.

        @return The last item in the list.
    */
    T pop(void);

    /*! @brief Swaps the positions of the two items at the given indices.

        After the swap, the item previously at \p index1 will now be located at
        \p index2, and the item previously at \p index2 will now be located at
        \p index1.

        @param index1: Index of the first item.
        @param index2: Index of the second item.
    */
    void swap(int index1, int index2);
};

// Template class declarations in a header are not compiled when the header
// is included in a source file. A workaround is to include the implementation
// source in the header, as below.
#include "SinglyLinkedList.cpp"
#endif
