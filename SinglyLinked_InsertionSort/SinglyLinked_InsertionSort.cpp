/*Berhasil dicompile dengan Compiler bawaan Visual Studio 2019*/
#include <iostream>
#include <conio.h>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;

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


//prosedur untuk menyisipkan Node baru kedalam list.
void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current;
	/*
	Jika pointer awal (head_ref) NULL atau datanya lebih besar atau sama dengan data Node baru, maka
	Pointer Node baru selanjutnya akan diset ke head_ref, dan Node baru akan masuk ke depan (head_ref).
	*/
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		//Mengarahkan pointer current ke posisi yangakan diselipkan.
		current = *head_ref;
		/*
		Melakukan perulangan selama alamat LinkedList berikutnya bukan NULL, dan
		data LinkedList berikutnya lebih kecil dari node baru;
		*/
		while (current->next != NULL &&
			current->next->data < new_node->data)
		{
			current = current->next; //menujukan current ke alamat berikutnya.
		}
		new_node->next = current->next; 
		current->next = new_node; //menyelipkan Node baru ke Pointer current->next.
	}
}


//Fungsi untuk menampilkan LinkedList.
void printList(struct Node* head)
{
	struct Node* temp = head;
	/*
	Melakukan perulangan sampai mencapai ujung LinkedList;
	*/
	while (temp != NULL)
	{
		printf("%d ", temp->data); //menampilkan data;
		temp = temp->next; //temp ditujukan ke alamat berikutnya.
	}
}

//Fungsi untuk menambah Node LinkedList.
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

int main()
{
	int p;	//variable untuk menampung pilihan;
	int nilai; //variable untuk menampung nilai baru;
	struct Node* a = NULL; //Pointer Node a;


	do {
		system("cls"); //membersihkan layar.
		cout << "Pilih Aksi" << endl;
		cout << "=============================" << endl;
		cout << "1. Masukan Data" << endl;
		cout << "2. Tampilkan Data Sebelum Sort" << endl;
		cout << "3. Tampilkan Data Setelah Sort" << endl;
		cout << "Pilihan anda : ";
		cin >> p; //membaca input.

		switch (p) { //menjalankan instruksi berdasarkan nilai p
		case 1: //memasukan data baru
			cout << "Data : ";
			cin >> nilai;
			push(&a, nilai);
			cout << endl;
			break;
		case 2: //menampilkan Linkedlist sebelum diurut;
			cout << "Linkedlist sebelum sort \n";
			printList(a);
			cout << endl;
			_getche();
			break;
		case 3: //menampilkan Linkedlist setelah diurut;
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
