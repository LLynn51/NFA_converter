#ifdef
#include <map>
#include <vector>
#include <set>
using namespace std; // 但是我真的不想写std::
class identifier_map
{
private:
    // 空串不在字符集里处理，用另外的方法单独处理
    map<string, int> name2id; // 对应编号从0开始
    map<int, string> id2name;

public:
    int get_id(const string &name)
    {
        if (name2id.find(name) == name2id.end())
        {
            name2id[name] = id2name.size();
            id2name.push_back(name);
        }
        return name2id[name];
    }
    string get_name(int id) const
    {
        return id2name[id];
    }
    size_t size() const
    {
        return id2name.size();
    }
};
#endif