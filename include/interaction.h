/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 22:52:13
 * @LastEditors: LLynn
 * @LastEditTime: 2026/3/25 17:04:48
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 * @Email: linyumian51@gmail.com
 */
#ifndef INTERACTION_H
#define INTERACTION_H
#include "automata.h"
#include "dynamic_enum.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
typedef bool StateIDUS;
StateIDUS read_NFA_from_terminal(NFA &nfa);
std::string set_to_string(const StateID_sset &s, const NFA &nfa);
void write_DFA_to_terminal(const DFA &dfa);
#endif