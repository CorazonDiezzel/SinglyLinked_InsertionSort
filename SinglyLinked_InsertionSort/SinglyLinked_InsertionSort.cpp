/* Source Code: 
	https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/
*/

#include<stdio.h> 
#include<stdlib.h> 

/*Link list Node */
struct Node
{
	int data;
	struct Node* next;
};
 
void sortedInsert(struct Node**, struct Node*); // Fungsi untuk memasukan node baru kedalam LinkedList.
void insertionSort(struct Node** head_ref) // Fungsi untuk mengurutkan LinkedList menggunakan Insertion Sort. 
{
	// Inisialisasi linked list untuk node yang akan diurut.
	struct Node* sorted = NULL;

	//Deklarasi node sementara dan menunjukannya ke head_ref.
	struct Node* current = *head_ref;
	//Menyalurkan setiap node sementara untuk diurut, dan menampungnya kedalam node sorted. 
	
	while (current != NULL){ //perulangan sampai current->next NULL (ujung Linked List)
		// Menampung alamat node next.
		struct Node* next = current->next;

		// Pemanggilan fungsi sortedInsert, dimana current akan diuji, lalu dimasukan ke Node sorted.
		sortedInsert(&sorted, current);

		// menunjukan current ke next (node berikutnya) untuk iterasi berikutnya.
		current = next;
	}

	// Merubah head_ref ke node sorted yang sudah diurut. 
	*head_ref = sorted;
}

/* function to insert a new_node in a list. Note that this
function expects a pointer to head_ref as this can modify the
head of the input linked list (similar to push())*/
void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL &&
			current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


// Main function
int main()
{
	struct Node* a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	printf("Linked List before sorting \n");
	printList(a);

	insertionSort(&a);

	printf("\nLinked List after sorting \n");
	printList(a);

	return 0;
}
