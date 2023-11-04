## 問題
整数配列`nums`が与えられたとき、
次の種類のクエリを処理せよ。

`left <= right`の場合、
インデックスの`left`と`right`の間の`nums`の要素の合計を計算する

`NumArray`クラスを実装せよ：
- `NumArray(int[] nums)`
  - 整数配列`nums`でオブジェクトを初期化する
- `int sumRange(int left, int right)`
  - `left <= right`の場合、インデックスの`left`と`right`の間の`nums`の要素の合計を返す
    - 例：`nums[left] + nums[left + 1] + ... + nums[right]`

## 解法
```cpp
class NumArray
{
public:
    vector<int> accum;

    NumArray(vector<int> &nums)
    {
        accum.push_back(0);
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            accum.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return accum[right + 1] - accum[left];
    }
};
```
累積和を用いた解法。
差が区間の総和になることを利用している。
