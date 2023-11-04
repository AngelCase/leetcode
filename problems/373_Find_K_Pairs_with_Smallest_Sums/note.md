## 問題
2つの非降順でソートされた整数配列`nums1`と`nums2`、
そして整数`k`が与えられる。
それぞれの配列の要素から構成されるペア`(u,v)`を定義する。
和が最小となる`k`個のペア`(u1,v1), (u2,v2), ..., (uk, vk)`を返せ。

## 解法
```cpp
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    auto comp = [](auto &a, auto &b)
    {
        return a.first + a.second < b.first + b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq{comp};

    for (int i = 0; i < nums1.size(); ++i)
    {
        for (int j = 0; j < nums2.size(); ++j)
        {
            if (pq.size() < k)
            {
                pq.push({nums1.at(i), nums2.at(j)});
            }
            else if (pq.size() == k && nums1.at(i) + nums2.at(j) < pq.top().first + pq.top().second)
            {
                pq.pop();
                pq.push({nums1.at(i), nums2.at(j)});
            }
            else if (pq.size() == k && pq.top().first + pq.top().second < nums1.at(i) + nums2.at(j))
            {
                break;
            }
        }
    }

    vector<vector<int>> ans{};
    while (0 < pq.size())
    {
        ans.push_back({pq.top().first, pq.top().second});
        pq.pop();
    }
    return ans;
}
```
