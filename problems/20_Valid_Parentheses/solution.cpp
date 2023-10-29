/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <stack>
#include <string>

// @lc code=start
class Solution
{
public:
	bool isValid(std::string s)
	{
		std::stack<char> waits{};
		while (!s.empty())
		{
			char c = s.at(0);
			if (c == '(')
			{
				waits.push(')');
			}
			else if (c == '{')
			{
				waits.push('}');
			}
			else if (c == '[')
			{
				waits.push(']');
			}
			else if ((c == ')' ||
					  c == '}' ||
					  c == ']') &&
					 (!waits.empty() && c == waits.top()))
			{
				waits.pop();
			}
			else
			{
				return false;
			}

			s.erase(0, 1);
		}

		if (!waits.empty())
		{
			return false;
		}

		return true;
	}
};
// @lc code=end
