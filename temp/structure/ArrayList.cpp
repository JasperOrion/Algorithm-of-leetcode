// *动态数组实现
#include <iostream>
#include <stdexcept>
#include <vector>
template <typename E> class MyArrayList {
private:
    E *data;
    // 当前元素个数
    int size;
    // 最大容量
    int cap;
    // 默认初始容量
    static const int INIT_CAP = 1;

public:
    MyArrayList() {
        this->data = new E[INIT_CAP];
        this->size = 0;
        this->cap = INIT_CAP;
    }
    MyArrayList(int initCapactity) {
        this->data = new E[initCapactity];
        this->size = 0;
        this->cap = initCapactity;
    }
    // *-----------增加-----------
    // 尾插
    void addLast(E e) {
        // 判断是否已满
        if (size == cap)
            resize(2 * cap);
        data[size] = e;
        size++;
    }
    // 指定下标插入
    void add(int index, E e) {
        // 下标是否越界
        checkPositionIndex(index);
        // 是否已满
        if (size == cap) {
            resize(2 * cap);
        }
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }
    // 头插
    void addHead(E e) { add(0, e); }
    // *------------删除-------------//
    // 尾删
    E removeLast() {
        // 数组是否为空
        if (size == 0)
            throw std::out_of_range("NoSuchElementException");
        E deleteVal = data[size - 1];
        // 将最后一个元素重置为默认值
        data[size - 1] = E();
        size--;
        // 可以缩减容量
        if (size > 0 && size == cap / 4) {
            resize(cap / 2);
        }
        return deleteVal;
    }
    // 指定结点删除
    E remove(int index) {
        checkElementIndex(index);
        E deleteVal = data[index];
        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        data[size - 1] = E();
        size--;
        if (size > 0 && size == cap / 4) {
            resize(cap / 2);
        }
        return deleteVal;
    }
    // 头删
    E removeHead() { return remove(0); }

    // *-----------查找,更改-------------*/
    E get(int index) {
        checkElementIndex(index);
        return data[index];
    }
    E set(int index, E e) {
        checkElementIndex(index);
        E oldVal = data[index];
        data[index] = e;
        return oldVal;
    }

    //*----------判空,求长---------------*/
    bool isEmpty() { return size == 0; }
    int Size() { return size; }

    //*------------改变容量--------------*/
    void resize(int newCap) {
        E *temp = new E[newCap];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        cap = newCap;
    }
    //*----------判断下标范围------------*/
    // 元素下标
    bool isElementIndex(int index) { return index >= 0 && index < size; }
    // 元素之间的空余位置
    bool isPositionIndex(int index) { return index >= 0 && index <= size; }
    // 检查index 索引位置是否可以添加元素
    void checkPositionIndex(int index) {
        if (!isPositionIndex(index))
            throw std::out_of_range("Index out of bounds");
    }
    // 检查index索引位置是否可以添加元素
    void checkElementIndex(int index) {
        if (!isElementIndex(index)) {
            throw std::out_of_range("Index out of nounds");
        }
    }
    // *-----------遍历展示--------------*/
    void display() {
        std::cout << "size = " << size << " cap = " << cap << std::endl;
        for (int i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    ~MyArrayList() { delete[] data; }
};

int main() {
    MyArrayList<int> arr;

    // 测试判空
    std::cout << "isEmpty: " << arr.isEmpty() << std::endl;

    // 测试尾插
    arr.addLast(10);
    arr.addLast(20);
    arr.addLast(30);
    arr.display();

    // 测试头插
    arr.addHead(5);
    arr.display();

    // 测试指定位置插入
    arr.add(2, 15); // [5,10,15,20,30]
    arr.display();

    // 测试get和set
    std::cout << "arr.get(2): " << arr.get(2) << std::endl;
    std::cout << "arr.set(2, 99): " << arr.set(2, 99) << std::endl;
    arr.display();

    // 测试尾删
    std::cout << "removeLast: " << arr.removeLast() << std::endl;
    arr.display();

    // 测试头删
    std::cout << "removeHead: " << arr.removeHead() << std::endl;
    arr.display();

    // 测试指定位置删除
    std::cout << "remove(1): " << arr.remove(1) << std::endl;
    arr.display();

    // 测试扩容
    for (int i = 0; i < 20; ++i)
        arr.addLast(i + 100);
    arr.display();

    // 测试缩容
    while (arr.Size() > 2)
        arr.removeLast();
    arr.display();

    // 测试异常: get越界
    try {
        arr.get(100);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // 测试异常: remove越界
    try {
        arr.remove(-1);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // 测试异常: removeLast空
    MyArrayList<int> emptyArr;
    try {
        emptyArr.removeLast();
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // 测试自定义初始容量
    MyArrayList<int> arr2(5);
    arr2.addLast(1);
    arr2.addLast(2);
    arr2.display();

    return 0;
}
