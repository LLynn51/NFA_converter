/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 22:52:13
 * @LastEditors: LLynn
 * @LastEditTime: 2026/4/8 13:25:07
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
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