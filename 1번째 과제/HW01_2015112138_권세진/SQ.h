typedef struct stack{
        void* data;
        struct stack* next;
}Stack;


typedef struct stackHead{
        int dataNumber; // the number of data
        Stack* head; // always pointing a head of stack
}S_Head;

S_Head* MakeStack();

int PushStack(S_Head* stack,void* data);

void* PopStack(S_Head* stack);


typedef struct queue{
	void* data;
	struct queue* next;
}Queue;

typedef struct queueHead{
	int dataNumber;
	Queue* head;
	Queue* rear;
}Q_Head;

Q_Head* MakeQueue();

int Enqueue(Q_Head* head,void* data);

void* Dequeue(Q_Head* head);


