/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 22:52:36
 * @LastEditors: LLynn
 * @LastEditTime: 2026/3/25 17:04:40
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 * @Email: linyumian51@gmail.com
 */

#include "automata.h"
#include "dynamic_enum.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

typedef bool STATUS;

STATUS read_NFA_from_terminal(NFA &nfa)
{
    std::string line, tmp;

    std::cout << "请输入NFA状态集 (用空格分隔，回车确认): " << std::endl;
    if (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        while (ss >> tmp)
        {
            nfa.Q.insert(nfa.StateID_map.get_id(tmp));
        }
    }

    std::cout << "请输入NFA字符集 (空格分隔，不含epsilon，回车确认): " << std::endl;
    if (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        while (ss >> tmp)
        {
            nfa.T.insert(nfa.Input_map.get_id(tmp));
        }
    }

    std::cout << "请输入NFA规则集 (格式: 初态 字符 次态，每行一组，输入空行结束): " << std::endl;
    while (std::getline(std::cin, line) && !line.empty())
    {
        std::stringstream ss(line);
        std::string s, c, n;
        // 支持一行内写多组，或者每行一组
        while (ss >> s >> c >> n)
        {
            StateID ids = nfa.StateID_map.find_id(s);
            StateID idc = (c == "epsilon") ? EPSILON : nfa.Input_map.find_id(c);
            StateID idn = nfa.StateID_map.find_id(n);

            if (ids != INVALID_INPUT && idn != INVALID_INPUT)
            {
                // 特殊处理 epsilon 或者在字母表里的字符
                if (idc != INVALID_INPUT || c == "epsilon")
                {
                    nfa.R[ids][idc].push_back(idn);
                }
                else
                {
                    std::cout << ">> 警告: 字符 '" << c << "' 不在字母表中，该规则已忽略。" << std::endl;
                }
            }
            else
            {
                std::cout << ">> 警告: 状态 '" << s << "' 或 '" << n << "' 未定义，该规则已忽略。" << std::endl;
            }
        }
    }

    std::cout << "请输入NFA起始状态 (单个状态名，回车确认): " << std::endl;
    if (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if (ss >> tmp)
        {
            StateID id = nfa.StateID_map.find_id(tmp);
            if (id != INVALID_INPUT)
            {
                nfa.q0 = id;
            }
            else
            {
                std::cout << ">> 错误: 起始状态不在状态集中！" << std::endl;
            }
        }
    }

    std::cout << "请输入NFA终止状态集 (空格分隔，回车确认): " << std::endl;
    if (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        while (ss >> tmp)
        {
            StateID id = nfa.StateID_map.find_id(tmp);
            if (id != INVALID_INPUT)
            {
                nfa.F.insert(id);
            }
            else
            {
                std::cout << ">> 警告: 状态 '" << tmp << "' 不在状态集中，已忽略。" << std::endl;
            }
        }
    }

    return true;
}

// 将状态集转化为字符串，用于显示转换过程
std::string set_to_string(const std::set<StateID> &s, const NFA &nfa)
{
    if (s.empty())
        return "{}";

    std::vector<std::string> names;
    for (StateID id : s)
    {
        names.push_back(nfa.StateID_map.get_name(id));
    }
    std::sort(names.begin(), names.end());

    std::stringstream ss;
    ss << "{";
    for (size_t i = 0; i < names.size(); ++i)
    {
        ss << names[i] << (i == names.size() - 1 ? "" : ",");
    }
    ss << "}";
    return ss.str();
}

void write_DFA_to_terminal(const DFA &dfa)
{
    std::cout << "================ 转换结果 (DFA) ================" << std::endl;

    std::cout << "状态集 Q: { ";
    for (StateID s : dfa.Q)
        std::cout << dfa.StateID_map.get_name(s) << " ";
    std::cout << "}" << std::endl;

    std::cout << "字母表 T: { ";
    for (StateID i : dfa.T)
        std::cout << dfa.Input_map.get_name(i) << " ";
    std::cout << "}" << std::endl;

    std::cout << "起始状态 q0: " << dfa.StateID_map.get_name(dfa.q0) << std::endl;

    std::cout << "终止状态集 F: { ";
    for (StateID s : dfa.F)
        std::cout << dfa.StateID_map.get_name(s) << " ";
    std::cout << "}" << std::endl;

    std::cout << "转移规则 R:" << std::endl;
    for (auto const &[src, targets] : dfa.R)
    {
        for (auto const &[in, dest] : targets)
        {
            std::cout << "   " << dfa.StateID_map.get_name(src)
                      << " --(" << dfa.Input_map.get_name(in) << ")--> "
                      << dfa.StateID_map.get_name(dest) << std::endl;
        }
    }
    std::cout << "================================================" << std::endl;
}
