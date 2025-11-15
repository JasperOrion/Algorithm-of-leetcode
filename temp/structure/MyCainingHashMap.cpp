#include <algorithm> // 添加此头文件
#include <iostream>
#include <list>
#include <optional>
#include <vector>

// 修正类名拼写错误
template <typename K, typename V> class MyChainingHashMap {
    // 使用单链表结点存储key - value
    struct KVNode {
        K key;
        V value;
        KVNode(K key, V value) : key(key), value(std::move(value)) {}
    };

private:
    // 哈希表中每个元素是一个链表，链表中的每个节点是一个KVNode 的键值对
    std::vector<std::list<KVNode>> table;
    int size;
    // 底层数组初始容量
    static constexpr int INIT_CAP = 4;
    // 哈希函数，将键映射到 table 的索引
    int hash(const K &key) const {
        if (table.size() == 0)
            return 0;
        // 下面取哈希值的低31位然后对表长取模映射
        return (std::hash<K>{}(key) & 0x7fffffff) % table.size();
    }
    void resize(int newCap) {
        newCap = std::max(newCap, 1);
        MyChainingHashMap<K, V> newMap(newCap);
        for (auto &list : table) {
            for (auto &node : list) {
                newMap.put(node.key, node.value);
            }
        }
        this->table = newMap.table; // 修正成员访问
    }

public:
    MyChainingHashMap() : MyChainingHashMap(INIT_CAP) {}
    explicit MyChainingHashMap(int initCapacity) {
        size = 0;
        initCapacity = std::max(initCapacity, 1);
        table.resize(initCapacity);
    }
    /*---------增加/修改------------*/
    void put(K key, V value) {
        auto &list = table[hash(key)];
        for (auto &node : list) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        // 尾插
        list.emplace_back(key, value);
        size++;
        // 元素超过负载因子，进行扩容
        if (size > table.size() * 0.75)
            resize(table.size() * 2);
    }
    /*--------删除--------------*/
    void remove(K key) {
        auto &list = table[hash(key)];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->key == key) {
                list.erase(it);
                size--;

                if (size <= table.size() / 8 && table.size() > 1)
                    resize(std::max(static_cast<int>(table.size() / 4), 1));
                return;
            }
        }
    }
    /*---------查找--------------*/
    std::optional<V> get(K key) const {
        const auto &list = table[hash(key)];
        for (const auto &node : list) {
            if (node.key == key)
                return node.value;
        }
        return std::nullopt;
    }
    /*-------返回所有键值对------*/
    std::list<K> keys() const {
        std::list<K> keys;
        for (const auto &list : table) {
            for (const auto &node : list) {
                keys.push_back(node.key);
            }
        }
        return keys;
    }
    /*-----工具函数----------*/
    int hashSize() const { return size; }
};

int main() {
    // 修正类名拼写错误
    MyChainingHashMap<std::string, int> map;

    // 测试 put 和 get
    map.put("apple", 10);
    map.put("banana", 20);
    map.put("orange", 30);

    std::cout << "apple: "
              << (map.get("apple").has_value()
                      ? std::to_string(map.get("apple").value())
                      : "not found")
              << std::endl;
    std::cout << "banana: "
              << (map.get("banana").has_value()
                      ? std::to_string(map.get("banana").value())
                      : "not found")
              << std::endl;
    std::cout << "orange: "
              << (map.get("orange").has_value()
                      ? std::to_string(map.get("orange").value())
                      : "not found")
              << std::endl;
    std::cout << "pear: "
              << (map.get("pear").has_value()
                      ? std::to_string(map.get("pear").value())
                      : "not found")
              << std::endl;

    // 测试覆盖
    map.put("apple", 100);
    std::cout << "apple after update: "
              << (map.get("apple").has_value()
                      ? std::to_string(map.get("apple").value())
                      : "not found")
              << std::endl;

    // 测试 remove
    map.remove("banana");
    std::cout << "banana after remove: "
              << (map.get("banana").has_value()
                      ? std::to_string(map.get("banana").value())
                      : "not found")
              << std::endl;

    // 测试 keys
    std::cout << "All keys: ";
    for (const auto &key : map.keys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    // 测试 size
    std::cout << "Current size: " << map.hashSize() << std::endl;

    return 0;
}
