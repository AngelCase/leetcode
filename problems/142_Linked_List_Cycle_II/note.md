## 問題
連結リストのheadが与えられるので、
その連結リストのサイクルがどこから始まっているか返せ。

また、連結リストへの変更を加えることは禁止。

## 閃き
数式で考えればなんとなくイメージはできるが、
答えを覚えたほうが早い。

以下の2つのポインタを移動させてぶつかる所を探す。
- 連結リストのheadから1つずつ移動
- slowとfastがぶつかった位置から1つずつ移動

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

まず以下のように変数をおく：
- A：headからサイクル始点までの距離
- B：サイクル始点からぶつかった位置までの距離
- C：ぶつかった位置からサイクル始点に戻るまでの距離
- n：fastがサイクルを回った回数（必ず0より大きい）

この時、slowの移動距離はA+B、fastの移動距離はA + (B+C)n + Bと表せる。
このことから以下の等式が成り立つ。
2(A+B) = A + (B+C)n + B
Aについて解く。
2A + 2B = A + Bn + Cn + B
A = (B+C)n - B

nに具体的な値を入れるとイメージがつきやすい。

n=1のときA = Cなので
head、ぶつかった位置それぞれから1つずつ進めば
サイクルの始点でぶつかる。

n=2のときA = (B+C) + Cなので
これも同様に1つずつ進めば
一周してCだけ進んだ後
サイクルの始点でぶつかる。

この時、一周もせずにぶつかることはありえない。
なぜなら、一周しないということはA=Cとなり(B+C)=0となってしまうため。

n=3、n=4と続けても同様の結果になり、

つまり、以下の2つのポインタを移動させてぶつかった点がサイクルの始点だと分かる。
- 連結リストのheadから1つずつ移動
- slowとfastがぶつかった位置から1つずつ移動
