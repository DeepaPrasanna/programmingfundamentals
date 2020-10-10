#include<stdio.h>
#include<stdlib.h>

void InsertAtBegin(int data);
void PrintList();

struct Node {

	int data;
	struct Node* next;
};


struct Node* head;
struct Node* tail;
int length;

int main() {

	int	num, i, data;
	head = NULL;
	tail = NULL;
	length = 0;
	printf("How many numbers of nodes?\n");
	scanf("%d", &num);
	
	for(i=0;i<num;i++){
	
	printf("Enter the number to add at the beginning of the Linked List\n");
	scanf("%d", &data);
	InsertAtBegin(data);
	
	}
	
	PrintList();
}

void InsertAtBegin(int data){

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	
	if(head == NULL) {
		tail = temp;
	}
	
	head = temp;
	length++;
	
}

void PrintList(){

	struct Node* temp = head;
	
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	
	printf("\n");
}
