#include <stdio.h>
#include <stdlib.h>

int SIZE = 100;

struct Bucket* hash_table = NULL;

struct Node
{
  int key;
  char* value;
  struct Node* next;
  struct Node* previous;
};

struct Bucket
{
  int count;
  struct Node* head;
};

struct Node* create_node(int key, char* value)
{
  struct Node* new_node;
  new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->key = key;
  new_node->value = value;
  new_node->next = NULL;
  new_node->previous = NULL;
  return new_node;
}

int make_key(char* key)
{
  int hash = 143;
  for(;*key;key++)
  {
    hash = hash * 3 + (*key);
  }
  return hash % 2000000000;
}

int hash_function(int key) { return key % SIZE; }

void insert(char* value)
{
  int key = make_key(value);
  int hash_index = hash_function(key);
  struct Node* new_node = create_node(key, value);
  if(hash_table[hash_index].count == 0)
  {
    hash_table[hash_index].count = 1;
    hash_table[hash_index].head = new_node;
  }
  else
  {
    hash_table[hash_index].count++;
    hash_table[hash_index].head->previous = new_node;
    new_node->next = hash_table[hash_index].head;
    hash_table[hash_index].head = new_node;
  }
  return;
}

int search(char* value)
{
  int key = make_key(value);
  int hash_index = hash_function(key);
  struct Node* node = hash_table[hash_index].head;
  int flag = 0;

  while(node != NULL)
  {
    if(node->key == key)
    {
      flag = 1;
      break;
    }
    node = node->next;
  }

  return flag;
}

int main(void)
{
  int n, m = 0;
  char str[501];
  unsigned int i, ans = 0;

  hash_table = (struct Bucket*)malloc(sizeof(struct Bucket) * SIZE);

  scanf("%d %d", &n, &m);

  for(i = 0; i < SIZE; ++i)
  {
    hash_table[i].count = 0;
    hash_table[i].head = NULL;
  }

  for(i = 0; i < n; ++i)
  {
    scanf("%s", str);
    insert(str);
  }

  for(i = 0; i < m; ++i)
  {
    scanf("%s", str);
    ans += search(str);
  }
  printf("%d", ans);
  free(hash_table);

  return 0;
}
