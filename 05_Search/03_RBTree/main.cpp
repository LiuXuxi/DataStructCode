#include "RBTree.h"
#include <vector>
#include <iostream>

int main() {
    // 使用 C++ 的 vector 来存储数据
    std::vector<int> data = { 55, 40, 65, 60, 75, 57, 63, 56 };

    // 创建 RBTree 对象，构造函数会自动调用
    RBTree<int> rbTree;

    // 使用范围 for 循环插入数据
    for (int value : data) {
        rbTree.insert(value);
    }

    // 打印树的内容
    rbTree.travel();

    std::cout << "=======================" << std::endl;

    // 调用删除方法
    rbTree.deleteValue(60);

    // 再次打印树
    rbTree.travel();

    return 0;
} // rbTree 对象在此处离开作用域，其析构函数 ~RBTree() 会被自动调用，释放所有内存