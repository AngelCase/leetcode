## 問題
有効なemailは`@`で区切られたlocal nameとdomain nameから構成される。
小文字に加えて、1つ以上の`.`か`+`を持つ場合がある。
（例）`alice@leetcode.com`の場合：
- local name: `alice`
- domain name: `leetcode.com`

`.`をlocal nameの文字の間に加えると、
メールはドットのないlocal nameのアドレスに転送される。
このルールはdomain nameには適用されない。
（例）`alice.z@leetcode.com`と`alicez@leetcode.com`は
同じメールアドレスに転送される。

local nameに`+`を追加すると、最初のプラス以降は無視される。
これによって特定のメールアドレスはフィルタされる。
このルールはdomain nameには適用されない。
（例）`m.y+name@email.com`は`my@email.com`に転送される。

これらのルールは同時に使える。

`emails[i]`にemailを送るような文字列配列`emails`が与えられたとき、
メールを実際に受け取る異なるアドレスの数を返せ。

## 解法
```cpp
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
```
