## 問題
連結リストのheadが与えられるので、
その連結リストのサイクルがどこから始まっているか返せ。

また、連結リストへの変更を加えることは禁止。

## 解法
```cpp
ListNode *detectCycle(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}

	ListNode *fast = head;
	ListNode *slow = head;

	ListNode *fastOld = head;
	ListNode *slowOld = head;

	// サイクルの有無を判定
	while (fast != NULL)
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			return NULL;
		}

		fastOld = fast;
		slowOld = slow;

		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			break;
		}
	}

	if (fast == NULL)
	{
		return NULL;
	}

	// slowを初期地点に戻し、fastは1つずつ移動させる
	// 重なった位置がサイクルの開始点
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
```
サイクルの有無を見つけるまではフロイドの循環検出法でよい。
サイクルがあった場合、ポインタを以下の2点から1つずつ移動させる。
- 連結リストのhead
- slowとfastがぶつかった位置
これでぶつかった位置がサイクルの始点。

なぜこうなるのかは計算によって導かれる。
headからサイクル始点までの距離をA、
サイクル始点からぶつかった位置までの距離をB、
ぶつかった位置からサイクル始点に戻るまでの距離をC、
fastがサイクルを回った回数をnとする。

この時、slowの移動距離はA+B、fastの移動距離はA+(B+C)n + Bと表せる。
このことから以下の等式が成り立つ。
2(A+B) = A + (B+C)n + B
今回、Aが分かればサイクルの始点も分かるので、Aについて解く。
2A + 2B = A + Bn + Cn + B
A = (B+C)n - B

つまり、以下の2つのポインタを移動させてぶつかった点がサイクルの始点だと分かる。
- 連結リストのheadから1つずつ移動（=A）
- slowとfastがぶつかった位置から1つずつ移動（=(B+C)n - B）
