/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 22:52:21
 * @LastEditors: LLynn
 * @LastEditTime: 2026/4/8 13:25:04
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 */
#ifndef CONVERTER_H
#define CONVERTER_H
#include "automata.h"
#include "dynamic_enum.h"
#include <queue>
StateID_sset get_epsilon_closure(const StateID_sset &StateIDes, const NFA &nfa);
DFA convert_NFA_to_DFA(NFA nfa);
#endif