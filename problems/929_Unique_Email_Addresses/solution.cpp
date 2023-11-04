/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    string procLocal(const string &local)
    {
        string beforePlus = local.substr(0, local.find('+'));

        string ret = beforePlus;
        while (ret.find('.') != string::npos)
        {
            ret.erase(ret.find('.'), 1);
        }

        return ret;
    }

    string makeActual(const string &email)
    {
        string local = email.substr(0, email.find('@'));
        string domain = email.substr(local.length());

        local = procLocal(local);

        return local + "@" + domain;
    }

    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> us{};
        for (auto &email : emails)
        {
            string actual = makeActual(email);
            us.emplace(actual);
        }

        return us.size();
    }
};
// @lc code=end
