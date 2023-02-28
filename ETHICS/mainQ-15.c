// C program to delete nth node from last
#include<stdio.h>
#include<stdlib.h>
// Structure of node
struct Node {
	int data;
	struct Node* next;
};

// Function to insert node in a linked list
struct Node* create(struct Node* start, int x)
{
	struct Node *temp, *ptr = start;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return start;
}

// Function to remove nth node from last
struct Node* removeNthFromEnd(struct Node* start, int B)
{
	// To store length of the linked list
	int len = 0;
	struct Node* tmp = start;
	while (tmp != NULL) {
		len++;
		tmp = tmp->next;
	}

	// B > length, then we can't remove node
	if (B > len)
	{
		printf( "Length of the linked list is %d",len );
		printf( " we can't remove %dth node from the",B);
		printf(" linked list\n");
		return start;
	}

	// We need to remove start node
	else if (B == len) {

		// Return start->next
		return start->next;

	}
	else
	{
		// Remove len - B th node from starting
		int diff = len - B;
		struct Node* prev= NULL;
		struct Node* curr = start;
		for(int i = 0;i < diff;i++){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		return start;
	}

}

// This function prints contents of linked
// list starting from the given node
void display(struct Node* start)
{

	struct Node* temp = start;
	while (temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Driver code
int main()
{
	struct Node* start = NULL;

    start = create(start, 1);
	start = create(start, 2);
	start = create(start, 3);
	start = create(start, 4);
	start = create(start, 5);

	int n=0;
	scanf("%d", &n);

	printf("Linked list Input \n");
	display(start);

	start = removeNthFromEnd(start, 2);
	printf("Linked list after modification: \n");
	display(start);

	return 0;
}
