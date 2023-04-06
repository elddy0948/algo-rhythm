#include <iostream>
#include <unordered_map>

using namespace std;

int windowSize;
int dnaLength;
char dna[1000001];
int minimumCounts[4]; // A C G T
int currentCounts[4]; // A C G T
int check = 0;
int answer = 0;

void Input()
{
  cin >> dnaLength >> windowSize;

  for (int i = 0; i < dnaLength; i++)
  {
    cin >> dna[i];
  }

  for (int i = 0; i < 4; i++)
  {
    cin >> minimumCounts[i];
    if (minimumCounts[i] == 0)
    {
      check++;
    }
  }
  return;
}

void add(char c)
{
  switch (c)
  {
  case 'A':
    currentCounts[0]++;
    if (currentCounts[0] == minimumCounts[0])
      check++;
    break;

  case 'C':
    currentCounts[1]++;
    if (currentCounts[1] == minimumCounts[1])
      check++;
    break;

  case 'G':
    currentCounts[2]++;
    if (currentCounts[2] == minimumCounts[2])
      check++;
    break;

  case 'T':
    currentCounts[3]++;
    if (currentCounts[3] == minimumCounts[3])
      check++;
    break;
  }
}

void remove(char c)
{
  switch (c)
  {
  case 'A':
    if (currentCounts[0] == minimumCounts[0])
      check--;
    currentCounts[0]--;
    break;

  case 'C':
    if (currentCounts[1] == minimumCounts[1])
      check--;
    currentCounts[1]--;
    break;

  case 'G':
    if (currentCounts[2] == minimumCounts[2])
      check--;
    currentCounts[2]--;
    break;

  case 'T':
    if (currentCounts[3] == minimumCounts[3])
      check--;
    currentCounts[3]--;
    break;
  }
}

void CheckDNA()
{
  for (int i = 0; i < windowSize; i++)
  {
    add(dna[i]);
  }

  if (check == 4)
  {
    answer++;
  }

  for (int i = windowSize; i < dnaLength; i++)
  {
    int j = i - windowSize;
    add(dna[i]);
    remove(dna[j]);

    if (check == 4)
    {
      answer++;
    }
  }
  return;
}

int main()
{
  Input();
  CheckDNA();

  cout << answer;
  return 0;
}