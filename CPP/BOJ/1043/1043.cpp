#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> rank(51, 0);
std::vector<int> parents(51, 0);
std::vector<int> parties(51, 0);

int numberOfPeople;
int numberOfParties;

void Input()
{
  std::cin >> numberOfPeople >> numberOfParties;

  int numberOfKnowTruePeople;
  std::cin >> numberOfKnowTruePeople;

  for (int i = 1; i <= numberOfKnowTruePeople; i++)
  {
    int personNumber;
    std::cin >> personNumber;

    rank[personNumber] = 1;
  }

  for (int i = 1; i <= numberOfPeople; i++)
  {
    parents[i] = i;
  }

  return;
}

int Find(int nodeNumber)
{
  if (parents[nodeNumber] != nodeNumber)
  {
    parents[nodeNumber] = Find(parents[nodeNumber]);
  }
  return parents[nodeNumber];
}

void Union(int lhs, int rhs)
{
  auto lhsParent = Find(lhs);
  auto rhsParent = Find(rhs);

  if (lhsParent == rhsParent)
    return;

  if (rank[lhsParent] < rank[rhsParent])
  {
    parents[lhsParent] = rhsParent;
    rank[lhsParent] = 1;
  }
  else if (rank[lhsParent] > rank[rhsParent])
  {
    parents[rhsParent] = lhsParent;
    rank[rhsParent] = 1;
  }
  else
  {
    parents[lhsParent] = rhsParent;
  }

  return;
}

void InputPartyInfo()
{
  for (int i = 1; i <= numberOfParties; i++)
  {
    int numberOfPartyMemebers;
    std::cin >> numberOfPartyMemebers;

    int rootMember;
    std::cin >> rootMember;

    for (int j = 0; j < numberOfPartyMemebers - 1; j++)
    {
      int member;
      std::cin >> member;
      Union(rootMember, member);
    }

    parties[i] = Find(rootMember);
  }
}

int main(void)
{
  int answer = 0;

  Input();
  InputPartyInfo();

  for (int i = 1; i <= numberOfParties; i++)
  {
    int partyMaster = parties[i];
    int parent = Find(partyMaster);

    if (!rank[parent])
    {
      answer++;
    }
  }

  std::cout << answer;

  return 0;
}