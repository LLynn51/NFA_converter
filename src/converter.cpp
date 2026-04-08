/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 22:52:29
 * @LastEditors: LLynn
 * @LastEditTime: 2026/3/25 17:28:40
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 * @Email: linyumian51@gmail.com
 */
#include "automata.h"
#include "dynamic_enum.h"
#include "interaction.h"
#include <queue>

// 计算一个状态集合的 epsilon-closure
StateID_sset get_epsilon_closure(const StateID_sset &StateIDs, const NFA &nfa)
{
    StateID_sset closure = StateIDs;
    std::queue<StateID> q;
    for (StateID s : StateIDs)
        q.push(s);

    while (!q.empty())
    {
        StateID curr = q.front();
        q.pop();

        // 使用 .count() 或 .find() 检查，防止 [] 产生多余的空 map 项
        if (nfa.R.count(curr) && nfa.R.at(curr).count(EPSILON))
        {
            for (StateID next_stat : nfa.R.at(curr).at(EPSILON))
            {
                if (closure.find(next_stat) == closure.end())
                {
                    closure.insert(next_stat);
                    q.push(next_stat);
                }
            }
        }
    }
    return closure;
}

DFA convert_NFA_to_DFA(NFA nfa)
{
    DFA dfa;
    dfa.Input_map = nfa.Input_map;
    dfa.T = nfa.T;

    // 映射：NFA状态集合 -> DFA状态ID
    std::map<StateID_sset, StateID> subset_to_id;
    // 待处理队列：存放NFA状态集合
    std::queue<StateID_sset> work_queue;

    // NFA起始状态的 epsilon-closure
    StateID_sset start_nfa_set = {nfa.q0};
    StateID_sset start_closure = get_epsilon_closure(start_nfa_set, nfa);

    // DFA起始状态
    std::string start_name = set_to_string(start_closure, nfa);
    StateID dfa_start_id = dfa.StateID_map.get_id(start_name);

    dfa.q0 = dfa_start_id;
    dfa.Q.insert(dfa_start_id);
    subset_to_id[start_closure] = dfa_start_id;
    work_queue.push(start_closure);

    // 检查起始状态闭包是否本身就是终止状态
    for (StateID s : start_closure)
    {
        if (nfa.F.count(s))
        {
            dfa.F.insert(dfa_start_id);
            break;
        }
    }

    // 子集构造迭代
    while (!work_queue.empty())
    {
        StateID_sset curr_nfa_set = work_queue.front();
        work_queue.pop();
        StateID curr_dfa_id = subset_to_id[curr_nfa_set];

        // 遍历所有可能的输入符号(不含epsilon)
        for (InputID c : dfa.T)
        {
            StateID_sset move_res;
            for (StateID s : curr_nfa_set)
            {
                if (nfa.R.count(s) && nfa.R.at(s).count(c))
                {
                    for (StateID next_s : nfa.R.at(s).at(c))
                    {
                        move_res.insert(next_s);
                    }
                }
            }

            if (move_res.empty())
                continue;
            StateID_sset next_closure = get_epsilon_closure(move_res, nfa);

            // 如果这个新集合没见过，则创建新DFA状态
            if (subset_to_id.find(next_closure) == subset_to_id.end())
            {
                std::string new_name = set_to_string(next_closure, nfa);
                StateID new_dfa_id = dfa.StateID_map.get_id(new_name);

                subset_to_id[next_closure] = new_dfa_id;
                dfa.Q.insert(new_dfa_id);
                work_queue.push(next_closure);

                // 检查新生成的集合是否包含终止状态
                for (StateID s : next_closure)
                {
                    if (nfa.F.count(s))
                    {
                        dfa.F.insert(new_dfa_id);
                        break;
                    }
                }
            }

            // 建立DFA转移规则
            dfa.R[curr_dfa_id][c] = subset_to_id[next_closure];
        }
    }

    return dfa;
}
