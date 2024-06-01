## 問題リスト
|#|Name|Intuition|
|-|-|-|
|1|Two Sum|ハッシュマップに記録して高速化|
|9|Palindrome Number|回文判定はひっくり返したものとの比較でも行える|
|82|Remove Duplicates from Sorted List II|連結リストの先頭にダミーノードを追加する|

## k番目に大きい要素
- 703 Kth Largest Element in a Stream
優先度付きキューを使う。

## 連結リストのサイクル検知
- 141 Linked List Cycle
連結リストのサイクル判定はslowとfastの2つのポインタで行える。

- 142 Linked List Cycle II
サイクルの始点は「slowとfastがぶつかったところ」と「リストの先頭」それぞれからslowを走らせ、ぶつかったところ。

## 行きがけ、通りがけ、帰りがけを反復で解く
- 94 Binary Tree Inorder Traversal
- 145 Binary Tree Postorder Traversal
通りがけと帰りがけは
ノードに戻ってくるので巡回済みかのメモを取っておくこと。

- 589 N-ary Tree Preorder Traversal
行きがけは同じノードを二回通ることはないので
ただ巡回するだけ。

