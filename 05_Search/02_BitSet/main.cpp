#include"bitset.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <assert.h>

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <ctime>

void validator() {
    const int TEST_TIMES = 20000; // 总测试组数
    const int OP_COUNTS = 300;   // 每组随机操作次数
    const int MAX_SIZE = 100;    // 位图最大长度

    srand(time(NULL));
    std::cout << "开始对数器测试 (直接使用 std::unordered_set 对比)..." << std::endl;

    for (int t = 0; t < TEST_TIMES; t++) {
        int n = rand() % MAX_SIZE + 1;

        // 实验组
        Bitset my(n);

        // 对照组：直接使用 STL 容器
        // ref_set 存储物理上为 1 的索引，ref_flipped 存储当前翻转状态
        std::unordered_set<int> ref_set;
        bool ref_flipped = false;

        // 记录操作历史，用于错误回溯
        std::vector<std::string> history;
        history.push_back("Initialize Bitset(size = " + std::to_string(n) + ")");

        try {
            for (int i = 0; i < OP_COUNTS; i++) {
                int op = rand() % 7;
                int idx = rand() % n;
                std::string current_op;

                if (op == 0) { // fix
                    current_op = "fix(" + std::to_string(idx) + ")";
                    my.fix(idx);
                    // 逻辑：fix(idx) 是要把逻辑值变 1。
                    // 如果没翻转，物理设为 1；如果翻转了，物理设为 0。
                    if (!ref_flipped) ref_set.insert(idx);
                    else ref_set.erase(idx);
                }
                else if (op == 1) { // unfix
                    current_op = "unfix(" + std::to_string(idx) + ")";
                    my.unfix(idx);
                    // 逻辑：unfix(idx) 是要把逻辑值变 0。
                    // 如果没翻转，物理设为 0；如果翻转了，物理设为 1。
                    if (!ref_flipped) ref_set.erase(idx);
                    else ref_set.insert(idx);
                }
                else if (op == 2) { // flip
                    current_op = "flip()";
                    my.flip();
                    ref_flipped = !ref_flipped;
                }
                else if (op == 3) { // all
                    current_op = "all()";
                    int logical_ones = ref_flipped ? (n - ref_set.size()) : ref_set.size();
                    if (my.all() != (logical_ones == n)) throw std::runtime_error("all() 结果不一致");
                }
                else if (op == 4) { // one
                    current_op = "one()";
                    int logical_ones = ref_flipped ? (n - ref_set.size()) : ref_set.size();
                    if (my.one() != (logical_ones > 0)) throw std::runtime_error("one() 结果不一致");
                }
                else if (op == 5) { // count
                    current_op = "count()";
                    int logical_ones = ref_flipped ? (n - ref_set.size()) : ref_set.size();
                    if (my.count() != logical_ones) throw std::runtime_error("count() 结果不一致");
                }
                else if (op == 6) { // toString
                    current_op = "toString()";
                    std::string my_str = my.toString();
                    std::string ref_str = "";
                    for (int k = 0; k < n; k++) {
                        bool physical = (ref_set.count(k));
                        ref_str += (ref_flipped ? !physical : physical) ? '1' : '0';
                    }
                    if (my_str != ref_str) throw std::runtime_error("toString() 结果不一致\nExpect: " + ref_str + "\nActual: " + my_str);
                }

                history.push_back(current_op);
            }
        }
        catch (const std::exception& e) {
            std::cout << "\n[测试失败] 第 " << t << " 组测试检测到异常！" << std::endl;
            std::cout << "错误信息: " << e.what() << std::endl;
            std::cout << "--- 错误现场还原 (操作历史) ---" << std::endl;
            for (const auto& log : history) {
                std::cout << " Step: " << log << std::endl;
            }
            return;
        }

        if (t % 500 == 0 && t > 0) std::cout << "已成功通过 " << t << " 轮随机测试..." << std::endl;
    }

    std::cout << "\n恭喜！通过了 2000 轮高强度随机对数测试，代码逻辑无误。" << std::endl;
}
int main() {
    validator();
    return 0;
}