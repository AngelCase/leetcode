## 問題
`x`の`n`乗（つまり$x^n$）を計算する`pow(x,n)`を実装せよ。

## 解法
### 1. 
```cpp
double helper(double x, long long n)
{
	if (n == 0)
	{
		return 1;
	}

	double res = helper(x * x, n / 2);

	return (n % 2) ? x * res : res;
}

double myPow(double x, int n)
{
	long long absN = abs(static_cast<long long>(n));

	double ans = helper(x, absN);

	return (0 <= n) ? ans : 1.0 / ans;
}
```
$x^4 = (x^2)^2$であることを利用して計算回数を減らしている。
単に計算すると`O(n)`だが、`O(log n)`まで減る。

## 学び
### abs(-2147483648)
intの範囲は$-2^{31}$から$2^{31}-1$。
つまり-2147483648から2147483647。

注目すべきは、下限の方が絶対値が1大きい点。
これに対して`std::abs`を使うと2147483648がとりえない値のため、
未定義動作となる。

#### 参考
[std::abs, std::labs, std::llabs, std::imaxabs - cppreference.com](https://en.cppreference.com/w/cpp/numeric/math/abs)
