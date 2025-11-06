#include "LinkList.cpp"
#include <iostream>
#include <string>

void testIntList() {
    std::cout << "===== 测试整型双向链表 =====" << std::endl;
    MyLinkList<int> list;
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
}

void testStringList() {
    std::cout << "\n===== 测试字符串双向链表 =====" << std::endl;
    MyLinkList<std::string> list;
    list.addLast("A");
    list.addLast("B");
    list.addFirst("Start");
    list.add(2, "Middle");
    list.display();
    std::cout << "第一个元素: " << list.getFirst() << std::endl;
    std::cout << "最后一个元素: " << list.getLast() << std::endl;
    std::cout << "移除索引1的元素: " << list.remove(1) << std::endl;
    list.display();
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // 设置Windows控制台为UTF-8编码
#endif
    // 尝试设置为C.UTF-8，若报错可注释掉下一行
    try {
        std::locale::global(
            std::locale("C.UTF-8")); // 或 "en_US.UTF-8" 或 "zh_CN.UTF-8"
    } catch (const std::runtime_error &) {
        // 设置失败则忽略
    }
    testIntList();
    testStringList();
    return 0;
}
