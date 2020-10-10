#include<stdio.h>
#include<stdlib.h>

void InsertAtBegin(int data);
void InsertAtEnd(int data);
void PrintList();
void InsertAtMiddle(int val, int index);

struct Node {

	int data;
	struct Node* next;
};


struct Node* head;
struct Node* tail;
int length;

int main() {

	int	num, i, data, val, index;
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
	
	printf("Enter the value and index position to insert a new Node\n");
	scanf("%d %d", &val, &index);
	
	InsertAtMiddle(val, index);
	
	PrintList();
	
}


void InsertAtMiddle(int val, int index){
	int i;
	if (index < 0 || index > length) {
		printf("Error!\n");
	} 
	else if(index == length){
    	InsertAtEnd(val);
    } 
    else if(index == 0){
    	InsertAtBegin(val);
    }
    else {
    	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    	newNode->data = val;
    	newNode->next = NULL;
    	
    	struct Node* previousNode = head;
    	
    	for(i = 0; i < index - 1; i++){
    		previousNode = previousNode->next;
    	}
    	
    	newNode->next = previousNode->next;
    	previousNode->next = newNode;
    	length++;
    }
    
    
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
