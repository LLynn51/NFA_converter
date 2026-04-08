/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 13:53:40
 * @LastEditors: LLynn
 * @LastEditTime: 2026/4/8 13:25:13
 * @Description: 入口函数
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 */
#include <iostream>
#include "automata.h"
#include "interaction.h"
#include "converter.h"
int main()
{
    // std::ios::sync_with_stdio(0);
    //  欢迎语
    std::cout << "欢迎使用本程序进行NFA到DFA的转换！";
    std::cout << "请按照系统提示依次输入NFA的状态集、字符集、转移规则、初始状态和接受状态集。";
    std::cout << "系统将自动为您输出与之等价的DFA描述。" << std::endl;
    std::cout << "按[s]开始，按[q]退出程序…………" << std::endl;
    char command;
    int cnt = 0;
    while (std::cin >> command)
    {
        std::cin.ignore(1024, '\n');
        if (command == 's')
        {
            while (true)
            {
                cnt++;
                std::cout << "==========================第" << cnt << "次转换==========================" << std::endl;
                NFA nfa; // 定义一个空的NFA对象
                if (read_NFA_from_terminal(nfa))
                {
                    DFA dfa = convert_NFA_to_DFA(nfa); // 算法输入NFA，返回DFA
                    write_DFA_to_terminal(dfa);        // 输出结果
                    std::cout << "=======第" << cnt << "次转换结束，按[s]开始下一次转换，按[q]退出程序=======" << std::endl;
                    break;
                }
            }
        }
        else if (command == 'q')
        {
            break;
        }
        else
        {
            std::cout << "按[s]开始，按[q]退出程序…………" << std::endl;
        }
    }
    return 0;
}
