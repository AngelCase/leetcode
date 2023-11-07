## 問題
空でない、要素が自然数の2つの連結リストが与えられる。
桁は逆順で、各ノードに単一の桁が入っている。
数値がゼロで無ければ、先頭ノードにゼロはない。

２つの数を連結リストとして返せ。

## 解法
```cpp
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *ans = nullptr;
	ListNode *ansPtr = nullptr;

	ListNode *ptr1 = l1;
	ListNode *ptr2 = l2;

	bool kuriage = false;
	while (ptr1 != nullptr || ptr2 != nullptr || kuriage)
	{
		int digit1 = ptr1 != nullptr ? ptr1->val : 0;
		int digit2 = ptr2 != nullptr ? ptr2->val : 0;

		// この桁の合計を出す
		int sum = digit1 + digit2;
		if (kuriage)
		{
			sum += 1;
		}

		// 繰り上げの有無
		kuriage = 10 <= sum;

		// リスト末尾への追加
		int newVal = sum % 10;
		if (ans == nullptr)
		{
			ans = new ListNode{newVal};
			ansPtr = ans;
		}
		else
		{
			ansPtr->next = new ListNode{newVal};
			ansPtr = ansPtr->next;
		}

		// ポインタの移動
		if (ptr1 != nullptr)
		{
			ptr1 = ptr1->next;
		}
		if (ptr2 != nullptr)
		{
			ptr2 = ptr2->next;
		}
	}

	return ans;
}
```

## 学び
この問題とは直接関係ないが、
他の人の回答を見ていて、以下の三項演算子の書き方をいいと思った。
```cpp
int digit1 = (l1 != nullptr) ? l1->val : 0;
```
条件文をカッコで囲うことで見やすくなっている。
