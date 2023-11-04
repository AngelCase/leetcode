## 問題
文字列の配列`strs`が与えられたとき、
アナグラムであるものをまとめよ。
ただし、順序は問わない。

ただし、アナグラムは元の文字を1回だけ使用して
別の単語の文字を再配置して形成された単語である。

## 解法
```cpp
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
	unordered_map<string, vector<string>> map{};
	vector<vector<string>> ans{};
	for (auto &str : strs)
	{
		string sorted = str;
		sort(sorted.begin(), sorted.end());

		map[sorted].push_back(str);
	}

	for (auto &val : map)
	{
		ans.push_back(val.second);
	}
	return ans;
}
```
unordered_mapを使う。
文字列を辞書順にソートしたものをキーとし、
そのアナグラムである文字列の配列をバリューとする。
