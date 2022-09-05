#include <vector>
#include <iostream>

int Find(std::vector<int> &parents, int nodeNumber)
{
  if (parents[nodeNumber] != nodeNumber)
  {
    // Path Compression
    parents[nodeNumber] = Find(parents, parents[nodeNumber]);
  }

  return parents[nodeNumber];
}

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

int main(void)
{
  std::vector<int> parents(6, 0);
  std::vector<int> rank(6, 0);

  for (int i = 1; i <= 5; i++)
  {
    parents[i] = i;
  }

  Union(parents, rank, 1, 2);
  Union(parents, rank, 2, 3);
  Union(parents, rank, 4, 5);

  for (int i = 1; i <= 5; i++)
  {
    std::cout << parents[i] << ' ';
  }

  if (Find(parents, 3) == Find(parents, 5))
  {
    std::cout << "Same Parent!";
  }
  else
  {
    std::cout << "Different Parent!";
  }
}