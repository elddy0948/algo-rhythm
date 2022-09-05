# Union Find

## Union Find?

Union Find 알고리즘은 대표적으로 Disjoint Set(서로소 집합) 자료구조를 구현할 때 사용되는 알고리즘입니다.
주로 Disjoint Set과 Union Find 알고리즘은 세트로 다닙니다.

Union Find 알고리즘은 Disjoint Set과 같은 자료구조에서 사용되는 유용한 연산자 두가지를 지원하는데 이름에서도 알 수 있듯 Union과 Find라는 연산자 두가지를 지원합니다.

- Find : 원소(element)가 어떤 부분집합에 속해있는지 찾아내는 기능을 합니다. 이를 활용해서 두 원소가 같은 부분집합에 속해있는지를 판별합니다.

- Union : 두 개의 부분집합을 합치는 기능을 합니다. 우선 같은 집합인지 확인한 후, 아니라면 합치는 흐름으로 구현합니다.

## Implementaion Union and Find

### Find

Find는 어떤 node의 parent와 자기 자신이 같다면 그 node가 root가 됩니다. 만약 같지 않다면 재귀호출을 활용하여 root를 찾아가는 방식을 사용합니다.

```cpp
int Find(const std::vector<int> &parents, int nodeNumber)
{
  if (parents[nodeNumber] == nodeNumber)
  {
    return nodeNumber;
  }
  return parents[nodeNumber];
}
```

### Union

Union은 위에서 구현한 Find를 사용하여 구현합니다. 파라미터로 받아온 두 node의 root를 찾아 연결해주는 과정을 구현합니다.

```cpp
void Union(std::vector<int> &parents, int lhs, int rhs)
{
  auto lhsParent = Find(parents, lhs);
  auto rhsParent = Find(parents, rhs);

  parents[lhsParent] = rhsParent;
  return;
}
```

### Worst case

1 2 3 4 의 원소가 각각 존재한다고 하겠습니다.

```cpp
Union(1, 2);
Union(2, 3);
Union(3, 4);
```

이런식으로 Union을 진행하면 1 - 2 - 3 - 4 이런 그림이 최악의 케이스라고 할 수 있습니다.

## Improve Union Find

위에서 살펴보았던 Union Find 의 `O(logN)` 시간복잡도로 개선할 수 있습니다.

### Union by rank

Rank라는 단어는 Heigt, Size등 다양한 단어들과 바꿀 수 있습니다. 기준을 정하기 나름입니다. 트리의 높이를 rank로 표현할 수도 있고, 트리의 size를 rank로 표현할 수도 있습니다.

이 Rank가 작은 트리를 Rank가 높은 트리의 Root에 붙이는 방식이 Union by rank 방식입니다. 최악의 경우 시간 복잡도는 `O(logN)` 입니다.

```cpp
Union(1, 2);
Union(2, 3);
Union(3, 4);
```

이렇게 구성했을 때의 그림은

```markdown
   1
 / | \
2  3  4
```

### Path compression

트리가 만들어진 상태에서 Find() 함수를 호출할 때의 개선 사항으로 볼 수 있습니다. 어떤 node에 대해서 Find 함수를 호출하면 그 node로 부터 root까지 재귀호출을 통해 올라가면서 root를 찾는 방식이었는데, 이를 활용해서 root를 찾았으면, 지나왔던 경로에 있던 node들의 root는 결국 찾은 root와 동일합니다.

그럼 지나왔던 경로에 있는 node들의 root를 모두 찾은 root로 변경시켜주면, 다음에 해당 경로에 있던 node에 대한 Find 호출이 있을때, 다시 밑에서부터 찾지 않아도 됩니다.

### So

그래서 이 두 개선은 결국 Union과 Find에 대한 각각의 개선 사항이라고 볼 수 있습니다. 그래서 이 두가지 모두 활용하면 `O(LogN)` 보다 작게도 나올 수 있습니다.

## Implementation improved Union and Find

### Improved Find

```cpp
int Find(std::vector<int> &parents, int nodeNumber)
{
  if (parents[nodeNumber] != nodeNumber)
  {
    // Path Compression
    parents[nodeNumber] = Find(parents, parents[nodeNumber]);
  }

  return parents[nodeNumber];
}
```

### Improved Union

```cpp
void Union(
    std::vector<int> &parents,
    std::vector<int> &rank,
    int lhs, int rhs)
{
  auto lhsParent = Find(parents, lhs);
  auto rhsParent = Find(parents, rhs);

  if (lhsParent == rhsParent)
  {
    return;
  }

  // Union by rank
  if (rank[lhsParent] < rank[rhsParent])
  {
    parents[lhsParent] = rhsParent;
  }
  else if (rank[lhsParent] > rank[rhsParent])
  {
    parents[rhsParent] = lhsParent;
  }
  else
  {
    parents[lhsParent] = rhsParent;
    rank[rhsParent]++;
  }
  return;
}
```
