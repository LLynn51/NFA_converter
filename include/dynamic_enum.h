/**FileHeader
 * @Author: LLynn
 * @Date: 2026/3/24 18:03:39
 * @LastEditors: LLynn
 * @LastEditTime: 2026/4/8 13:25:09
 * @Description:
 * @Copyright: Copyright (©)}) 2026 LLynn. All rights reserved.
 */
#ifndef DYNAMIC_ENUM_H
#define DYNAMIC_ENUM_H
#include <map>
#include <vector>
#include <set>
#include <string>
class dy_enum
{
private:
    std::map<std::string, int> name2id; // 对应编号从0开始
    std::vector<std::string> id2name;

public:
    int get_id(const std::string &name)
    {
        if (name2id.find(name) == name2id.end())
        {
            int s = id2name.size();
            name2id[name] = s;
            id2name.push_back(name);
        }
        return name2id[name];
    }
    // 用于报错
    int find_id(const std::string &name) const
    {
        auto it = name2id.find(name);
        if (it != name2id.end())
            return it->second;
        return -1; // 返回 -1 表示没找到
    }
    std::string get_name(const int id) const
    {
        if (id < id2name.size())
        {
            return id2name[id];
        }
        else
            return "ERROR:no such name"; // 没有查找到
    }
    size_t size() const
    {
        return id2name.size();
    }
};
#endif