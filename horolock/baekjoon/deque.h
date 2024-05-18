typedef struct Deque
{
    int* arr;
    int front;
    int rear;
    int size;
} Deque;

void Deque_Init(Deque* dq, int size)
{
    dq->front = -1;
    dq->rear = 0;
    dq->size = size;
}

int Deque_Is_full(Deque* dq)
{
    return ((dq->front == 0 && dq->rear == dq->size - 1) || (dq->front == dq->rear + 1));
}

int Deque_Is_empty(Deque* dq)
{
    return (dq->front == -1);
}

void Deque_Insert_rear(Deque* dq, int key)
{
    if(Deque_Is_full(dq)) { return; }

    if (dq->front == -1)
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if (dq->rear == dq->size - 1)
        dq->rear = 0;
    else
        dq->rear = dq->rear + 1;

    dq->arr[dq->rear] = key;
}

void Deque_Delete_rear(Deque* dq)
{
    if (Deque_Is_empty(dq)) { return; }

    if (dq->front == dq->rear) { dq->front = -1; dq->rear = -1; }
    else if (dq->rear == 0) { dq->rear = dq->size - 1; }
    else { dq->rear = dq->rear - 1; }
}

int Deque_Get_rear(Deque* dq)
{
    if (Deque_Is_empty(dq) || dq->rear < 0) { return -1; }
    return dq->arr[dq->rear];
}

int Deque_Get_front(Deque* dq)
{
    if (Deque_Is_empty(dq)) { return -1; }
    return dq->arr[dq->front];
}