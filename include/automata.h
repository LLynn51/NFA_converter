/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 22:51:56
 * @LastEditors: LLynn
 * @LastEditTime: 2026/3/25 16:52:23
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 * @Email: linyumian51@gmail.com
 */

#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
#include <vector>
#include <map>
#include <set>
#include "dynamic_enum.h"
const int EPSILON = -2;
const int INVALID_INPUT = -1;

typedef int StateID;                                                   // 状态
typedef int InputID;                                                   // 输入
typedef std::set<StateID> StateID_sset;                                // NFA的状态子集
typedef std::map<std::set<StateID>, StateID> Nss2D;                    // 记录NFA集合对应哪个DFA整数ID的映射
typedef std::map<StateID, std::map<InputID, std::vector<StateID>>> Ns; // s指sigma
typedef std::map<StateID, std::map<InputID, StateID>> Ds;
typedef struct
{
    dy_enum StateID_map; // 状态名映射器（string->StateID），同时可以携带上下文
    dy_enum Input_map;   // 输入映射器（string->input）
    std::set<StateID> Q; // 状态集
    std::set<InputID> T; // 字符集
    Ns R;                // 规则集，R取rules首字母
    StateID q0;          // 起始状态
    std::set<StateID> F; // 终止状态集
} NFA;
typedef struct
{
    dy_enum StateID_map; // 状态名映射器（string->StateID）
    dy_enum Input_map;   // 输入映射器（string->input）
    std::set<StateID> Q; // 状态集
    std::set<InputID> T; // 字符集
    Ds R;                // 规则集，R取rules首字母
    StateID q0;          // 起始状态
    std::set<StateID> F; // 终止状态集
} DFA;
#endif