#include <vector>

class UnionFind
{
private:
  std::vector<int> parents;
  std::vector<int> rank;

public:
  UnionFind(int n)
  {
    rank.assign(n, 0);
    parents.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
      parents[i] = i;
    }
  }

  int Find(int i)
  {
    return (parents[i] == i) ? i : (parents[i] = Find(parents[i]));
  }

  bool IsSameSet(int lhs, int rhs)
  {
    return (Find(lhs) == Find(rhs));
  }

  void Union(int lhs, int rhs)
  {
    if (!IsSameSet(lhs, rhs))
    {
      int lhsParent = Find(lhs);
      int rhsParent = Find(rhs);

      if (rank[lhsParent] > rank[rhsParent])
      {
        parents[rhsParent] = lhsParent;
      }
      else
      {
        parents[lhsParent] = rhsParent;
        if (rank[lhsParent] == rank[rhsParent])
          rank[rhsParent]++;
      }
    }
  }
};