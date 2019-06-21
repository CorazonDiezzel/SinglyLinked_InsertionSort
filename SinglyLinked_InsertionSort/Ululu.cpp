#include<iostream> 
#include<conio.h>
#include<stdlib.h> 

using namespace std;

struct Node {
	int data;
	struct Node* next; //pointer penunjuk alamat Node berikutnya;
};

//deklarasi prosedur
void sortedInsert(struct Node**, struct Node*);
void insertionSort(struct Node** head_ref) {
	struct Node* sorted = NULL;

	struct Node* current = *head_ref;
	while (current != NULL)
	{
		struct Node* next = current->next;

		sortedInsert(&sorted, current);

		current = next;
	}

	*head_ref = sorted;
}

//prosedur insertion sort.


void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current;

	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
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

void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		cout << " " << temp->data;
		temp = temp->next;
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}
/*
int main()
{
	int p;
	int nilai;
	struct Node* a = NULL;


	do {
		system("cls");
		cout << "Pilih Aksi" << endl;
		cout << "=============================" << endl;
		cout << "1. Masukan Data" << endl;
		cout << "2. Tampilkan Data Sebelum Sort" << endl;
		cout << "3. Tampilkan Data Setelah Sort" << endl;
		cout << "Pilihan anda : ";
		cin >> p;

		switch (p) {
		case 1:
			cout << "Data : ";
			cin >> nilai;
			push(&a, nilai);
			cout << endl;
			break;
		case 2:
			cout << "Linkedlist sebelum sort \n";
			printList(a);
			cout << endl;
			_getche();
			break;
		case 3:
			insertionSort(&a);

			cout << "Linkedlist setelah di sort \n";
			printList(a);
			cout << endl;
			_getche();
			break;
		}
	} while (p != 4);

	return 0;
}
*/