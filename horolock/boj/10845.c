#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QNode {
  int key;
  struct QNode *next;
};

struct Queue {
  struct QNode *front;
  struct QNode *rear;
};

struct QNode *new_node(int k) {
  struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
  temp->key = k;
  temp->next = NULL;
  return temp;
}

struct Queue *create_queue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

int is_empty(struct Queue *queue) {
  return (queue->front == NULL && queue->rear == NULL);
}

void enqueue(struct Queue *queue, int item) {
  struct QNode *temp = new_node(item);
  if (queue->rear == NULL) {
    queue->front = queue->rear = temp;
    return;
  }
  queue->rear->next = temp;
  queue->rear = temp;
}

int dequeue(struct Queue *queue) {
  if (queue->front == NULL) {
    return -1;
  }

  struct QNode *temp = queue->front;
  int key = temp->key;

  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(temp);

  return key;
}

int main(void) {
  unsigned int command_count = 0;
  char command[6];
  unsigned int length = 0;
  unsigned int i = 0;
  unsigned int value = 0;
  int size = 0;
  struct Queue* q = create_queue();

  scanf("%d\n", &command_count);

  for (i = 0; i < command_count; ++i) {
    length = 0;
    memset(command, 0, sizeof(command));

    while (1) {
      char ch = getc(stdin);
      if (ch == '\n') {
        break;
      }
      if (ch == ' ') {
        scanf("%d\n", &value);
        break;
      }

      command[length] = ch;
      length++;
    }

    if(strcmp(command, "push") == 0)
    {
      size++;
      enqueue(q, value);
    }
    else if(strcmp(command, "pop") == 0)
    {
      int res = dequeue(q);
      if (res != -1) { size--; }
      printf("%d\n", res);
    }
    else if(strcmp(command, "size") == 0)
    {
      printf("%d\n", size);
    }
    else if(strcmp(command, "empty") == 0)
    {
      printf("%d\n", is_empty(q));
    }
    else if(strcmp(command, "front") == 0)
    {
      q->front == NULL ? printf("-1\n") : printf("%d\n", q->front->key);
    }
    else if(strcmp(command, "back") == 0)
    {
      q->rear == NULL ? printf("-1\n") : printf("%d\n", q->rear->key);
    }
  }

  return 0;
}
