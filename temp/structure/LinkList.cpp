// 双链表
#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif

template <typename E> class MyLinkList {
    struct Node {
        E val;
        Node *next;
        Node *prev;
        Node(E value) : val(value), next(nullptr), prev(nullptr) {};
    };
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkList() {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    ~MyLinkList() {
        while (size > 0) {
            removeFirst();
        }
        delete head;
        delete tail;
    }
    //*-------添加---------*/
    void addLast(E e) {
        Node *x = new Node(e);
        Node *temp = tail->prev;
        // temp <-> x
        temp->next = x;
        x->prev = temp;
        // x <->tail
        x->next = tail;
        tail->prev = x;
        size++;
    }
    void addFirst(E e) {
        Node *x = new Node(e);
        Node *temp = head->next;
        // x <-> temp
        temp->prev = x;
        x->next = temp;
        // head <-> x
        x->prev = head;
        head->next = x;
        size++;
    }
    void add(int index, E e) {
        checkPositionIndex(index);
        if (index == size) {
            addLast(e);
            return;
        }
        // 找到index对应的结点p
        Node *p = getNode(index);
        Node *temp = p->prev;
        Node *x = new Node(e);
        // temp <-> x
        temp->next = x;
        x->prev = temp;
        // x <-> p
        x->next = p;
        p->prev = x;
        size++;
    }
    //*--------删除-----------*/
    E removeLast() {
        if (isEmpty())
            throw std::out_of_range("No elements to remove.");
        // temp <-> x <-> tail
        Node *x = tail->prev;
        Node *temp = x->prev;
        temp->next = tail;
        tail->prev = temp;
        E val = x->val;
        x->next = nullptr;
        x->prev = nullptr;
        delete x;
        size--;
        return val;
    }
    E removeFirst() {
        if (isEmpty())
            throw std::out_of_range("No elements to remove.");
        // head <-> x <->temp
        Node *x = head->next;
        Node *temp = x->next;
        temp->prev = head;
        head->next = temp;
        E val = x->val;
        x->next = nullptr;
        x->prev = nullptr;
        delete x;
        size--;
        return val;
    }
    E remove(int index) {
        checkElementIndex(index);
        // prev <-> x <-> next
        Node *x = getNode(index);
        Node *prev = x->prev;
        Node *next = x->next;
        prev->next = next;
        next->prev = prev;
        E val = x->val;
        x->next = nullptr;
        x->prev = nullptr; // 修正了这里的拼写错误
        delete x;
        size--;
        return val;
    }
    //*--------查找---------*/
    E getFirst() {
        if (size < 1)
            throw std::out_of_range("No elements in the list.");
        return head->next->val;
    }
    E getLast() {
        if (size < 1)
            throw std::out_of_range("No elements in the list.");
        return tail->prev->val;
    }
    E get(int index) {
        checkElementIndex(index);
        Node *p = getNode(index);
        return p->val;
    }
    //*--------改------------*/
    E set(int index, E e) {
        checkElementIndex(index);
        Node *p = getNode(index);
        E oldVal = p->val;
        p->val = e;
        return oldVal;
    }
    //*------工具函数--------*/
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    void display() {
        std::cout << "size = " << size << std::endl;
        for (Node *p = head->next; p != tail; p = p->next) {
            std::cout << p->val << " <-> ";
        }
        std::cout << std::endl;
    }

private:
    Node *getNode(int index) {
        checkElementIndex(index);
        Node *p;
        // 如果index靠近头部，从head->next正向遍历，否则从tail->prev反向遍历
        if (index < size / 2) {
            p = head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
        } else {
            p = tail->prev;
            for (int i = size - 1; i > index; i--) {
                p = p->prev;
            }
        }
        return p;
    }
    bool isElementIndex(int index) const { return index >= 0 && index < size; }
    bool isPositionIndex(int index) const {
        return index >= 0 && index <= size;
    }

    void checkElementIndex(int index) const {
        if (!isElementIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) +
                                    ", Size: " + std::to_string(size));
    }
    void checkPositionIndex(int index) const {
        if (!isPositionIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) +
                                    ", Size: " + std::to_string(size));
    }
};
