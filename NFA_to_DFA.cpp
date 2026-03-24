#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
using namespace std;
// 为代码可读性，设置别名
typedef int curr_stat; // 现态 Q
typedef int input;     // 输入 （字符集中任意字符）
typedef int next_stat; // 次态
// NFA的转移规则，一个<现态,输入>的组合可能对应多个次态
typedef map<curr_stat, map<input, vector<next_stat>>> NFA_delta;
// DFA的转移规则，一个<现态,输入>的组合对应唯一次态
typedef map<curr_stat, map<input, next_stat>> DFA_delta;
int main()
{
    ios::sync_with_stdio(0);
    // 欢迎语
    cout << "欢迎使用本程序进行NFA到DFA的转换！";
    cout << "请按照系统提示依次输入NFA的状态集、字符集、转移规则、初始状态和接受状态集。";
    cout << "系统将自动为您输出与之等价的DFA描述。" << endl;
    cout << "按[h]查看帮助。按[q]结束程序。按[c]清除所有历史内容，从头开始。" << endl;
    cout << "按任意键开始……" << endl;
    getchar();   // 接收换行符
    int cnt = 0; // 记录执行任务的次数
    while (1)
    {
        cout << "==================我是分割线===================" << endl;
        cnt++;
        cout << "第" << cnt << "次转换：" << endl;
        // 初始化接受输入的变量
        set<string> NFA_Q;
        set<string> NFA_T;
        string q_0;
        set<string> NFA_F;
        set<NFA_delta> NFA_D;
        string tmp, tmp2, tmp3; // 接收输入的临时变量
        // 接受输入
        // 输入NFA状态集
        cout << "请输入NFA的状态集（用字符串表示，用空格或换行符分隔）。按esc结束输入。" << endl;
        while ()
        {
            scanf("%s", &tmp);
            NFA_Q.insert(tmp);
        }
        // 输入DFA字符集
        cout << "请输入NFA的字符集（除转义符号外的字符）。用字符串epsilon表示空串。按esc结束输入。" << endl;
        while ()
        {
            scanf("%c", &tmp);
            NFA_T.insert(tmp);
        }

        // 输入初始状态
        cout << "请输入NFA的初始状态（用字符串表示）。按enter表示输入完成。";
        cout << "本程序只接受一个输入状态，如果输入多个将丢弃剩余、只取第一个。" << endl;
        cin >> q_0;
        // 输入转换规则
        cout << "请输入NFA的转换规则。";
        cout << "要求格式：delta(现态,字符)=次态，按enter输入下一条规则。用字符串epsilon表示空串。";
        cout << "如果格式不合法，程序将拒绝接收该规则。";
        cout << "按ctrl+C结束输入。";
        while ()
        {
            scanf("delta(%s,%s)=%s", &tmp, &tmp2, &tmp3);
            NFA_delta dealtmp;
            dealtmp.
        }

        // 输入NFA结束状态集
        cout << "请输入NFA的状态集（用字符串表示，用空格或换行符分隔）。按esc结束输入。" << endl;
        while (scanf("%c", &tmp) && tmp != "\n")
            NFA_F.insert(tmp);
    }
    return 0;
}
