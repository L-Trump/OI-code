## 题目描述

从前有只舔狗，它很喜欢拉着它的伴侣讲故事。有一天它的伴侣突发奇想，让它不停地讲出n个故事，每个故事由一串长度不超过50的字符串组成（可重复，有空格，$1\le n \le 5*10^5$），然后它的伴侣随便说出m个故事，让这只舔狗报出这m个故事各讲了几次，因为这只舔狗经常口糊，所以仅空格和标点（除字母外都判定为标点）不同算作同一个故事，忽略字符串大小写问题，如果报不出来，那么舔狗之前的努力就白费了，请各位大佬帮帮它好吗？

## 输入

第一行两个正整数n,m
第2\~n+1行读入n个小故事（中间可能有空格，但仅空格数不同判作同一故事）
第n+2\~n+m+1行读入m个被询问的故事

## 输出

m行数据分别对应m个故事的出现次数，故事不存在输出0

## 样例输入

```
5 3
ILoveYou
Really?
Sure.
I Love you!
too!
I Love You
Sure
NoWay!
```

## 样例输出

```
2
1
0
```

## 样例说明

ILoveYou,I Love you!,ILove You这三句只有标点符号和空格不同，所以算同一句

## 数据范围
$1\le m \le n \le 5*10^5$
字符串长度$Length \le 50$
