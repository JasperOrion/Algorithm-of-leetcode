#include <iostream>
#include <stdexcept>
// *单链表
template <typename E> class LinkList {
private:
    struct Node {
        E val;
        Node *next;
        Node(E value) : val(value), next(nullptr) {}
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkList() {
        head = new Node(E());
        tail = head;
        size = 0;
    }
    ~LinkList() {
        while (size > 0) {
            removeFirst();
        }
        delete head;
    }
    //*--------添加-----------*/
    void addLast(E e) {
        Node *x = new Node(e);
        // tail -> x
        tail->next = x;
        tail = x;
        size++;
    }
    void addFirst(E e) {
        Node *x = new Node(e);
        x->next = head->next;
        head->next = x;
        if (size == 0)
            tail = x;
        size++;
    }
    void add(int index, E e) {
        checkPositionIndex(index);
        if (index == size) {
            addLast(e);
            return;
        }
        // 找到index对应的结点p的前驱节点
        Node *prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node *newNode = new Node(e);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }
    // *---------删除------------*/
    E removeLast() {
        if (isEmpty())
            throw std::out_of_range("No elements to remove");
        Node *prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        E oldVal = tail->val;
        prev->next = tail->next;
        delete tail;
        tail = prev;
        size--;
        return oldVal;
    }
    E removeFirst() {
        if (isEmpty())
            throw std::out_of_range("No elements to remove");
        Node *first = head->next;
        head->next = first->next;
        if (first == tail)
            tail = head;
        E oldVal = first->val;
        delete first;
        size--;
        return oldVal;
    }
    E remove(int index) {
        checkElementIndex(index);
        Node *prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node *oldNode = prev->next;
        E oldVal = oldNode->val;
        prev->next = oldNode->next;
        delete oldNode;
        size--;
        return oldVal;
    }
    //*------------查找----------*/
    E getFirst() {
        if (isEmpty())
            throw std::out_of_range("No elements in the list.");
        return head->next->val;
    }
    E getLast() {
        if (isEmpty())
            throw std::out_of_range("No elements in the list.");
        return tail->val;
    }
    E get(int index) {
        checkElementIndex(index);
        Node *cur = head->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    E set(int index, E e) {
        checkElementIndex(index);
        Node *cur = head->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        E oldVal = cur->val;
        cur->val = e;
        return oldVal;
    }

    //*----------工具函数---------*/
    int getSize() const { return size; }
    int isEmpty() const { return size == 0; }
    void display() {
        std::cout << "size = " << size << std::endl;
        for (Node *p = head->next; p != nullptr; p = p->next) {
            std::cout << p->val << "  -> ";
        }
        std::cout << std::endl;
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

int main() {
    LinkList<int> list;
    std::cout << "初始链表: ";
    list.display();

    // 测试 addFirst, addLast
    list.addFirst(10);
    list.addLast(20);
    list.addFirst(5);
    list.addLast(30);
    std::cout << "添加元素后: ";
    list.display();

    // 测试 add(index, e)
    list.add(2, 15);
    std::cout << "在索引2插入15后: ";
    list.display();

    // 测试 getFirst, getLast, get
    std::cout << "第一个元素: " << list.getFirst() << std::endl;
    std::cout << "最后一个元素: " << list.getLast() << std::endl;
    std::cout << "索引2的元素: " << list.get(2) << std::endl;

    // 测试 set
    int old = list.set(2, 99);
    std::cout << "将索引2的元素改为99，原值为: " << old << std::endl;
    list.display();

    // 测试 removeFirst, removeLast, remove(index)
    std::cout << "移除第一个元素: " << list.removeFirst() << std::endl;
    list.display();
    std::cout << "移除最后一个元素: " << list.removeLast() << std::endl;
    list.display();
    std::cout << "移除索引1的元素: " << list.remove(1) << std::endl;
    list.display();

    // 测试 getSize, isEmpty
    std::cout << "当前链表大小: " << list.getSize() << std::endl;
    std::cout << "链表是否为空: " << (list.isEmpty() ? "是" : "否")
              << std::endl;

    // 清空链表
    while (!list.isEmpty()) {
        list.removeFirst();
    }
    std::cout << "清空后链表: ";
    list.display();
    std::cout << "链表是否为空: " << (list.isEmpty() ? "是" : "否")
              << std::endl;

    // 异常测试
    try {
        list.removeFirst();
    } catch (const std::exception &e) {
        std::cout << "异常捕获: " << e.what() << std::endl;
    }
    try {
        list.get(0);
    } catch (const std::exception &e) {
        std::cout << "异常捕获: " << e.what() << std::endl;
    }
    try {
        list.add(-1, 1);
    } catch (const std::exception &e) {
        std::cout << "异常捕获: " << e.what() << std::endl;
    }

    return 0;
}
