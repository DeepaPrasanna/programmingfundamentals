#include<stdio.h>
#include<stdlib.h>

void InsertAtEnd(int data);
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
	
	printf("Enter the number to add at the end of the Linked List\n");
	scanf("%d", &data);
	InsertAtEnd(data);
	
	}
	
	PrintList();
}

void InsertAtEnd(int data){

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	
	if(head == NULL) {
		head = temp;
	} else {
		tail->next = temp;
	}
	
	tail = temp;
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
