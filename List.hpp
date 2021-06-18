#ifndef ECE275LIB_CONTAINERS_LIST_H
#define ECE275LIB_CONTAINERS_LIST_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

namespace ECE275Lib::containers {

	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* next;
	};

	template <typename T>
	class List {

	public:
		List(); //unparameterized constructor
		List(unsigned int); //parameterized constructor

		Node<T>* front() { // Access to the memory location of the head
			return head;
		}

		Node<T>* back() { // Access to the memory location of the tail
			return tail;
		}

		T at(unsigned int i) { // Access to the ith element
			Node<T>* temp = head;
			temp = son(i);
			return temp->data;
		}

		void assign(unsigned int i, T d) { // Assign the data stored in the ith element of the list to be the value d
			Node<T>* temp = son(i);
			temp->data = d;
		}

		unsigned int size() { // Return the length of the list
			return list_size;
		}

		void remove(unsigned int i) { // Remove the ith element
			if (list_size == 0) { //If there is no element in the list
				return;
			}
			if (i == 0) { // Delete the first node
				Node<T>* temp = head;
				head = head->next;
				delete temp;
			}
			else if (i == list_size - 1) { //Delete the last node
				Node<T>* temp = tail;
				delete temp;
				tail = son(list_size - 2);
				tail->next = nullptr;
			}
			else { //Delete a node in the middle
				Node<T>* temp1 = head;
				Node<T>* temp2 = head;
				for (unsigned int s = 0; s < i - 1; s++) {
					temp1 = temp1->next;
				}
				temp2 = temp1->next;
				temp1->next = temp2->next;
				delete temp2;
			}
			list_size = list_size - 1; // List's size decreases
		}

		void remove(unsigned int s, unsigned int e) {
			if (s == e) { // If s and e are the same
				remove(s);
			}
			else {
				if (s == 0 && e!= list_size -1) { // If the sth node is the first node and eth node is not the last node
					Node<T>* temp = head;
					head = son(e + 1);
					Freeall(temp, e - s + 1);
				}
				else if (e == list_size - 1 && s != 0) { // If the eth node is the last node and sth node is not the first node
					Node<T>* temp = son(s);
					tail = son(s - 1);
					Freeall(temp, e - s + 1);
					tail->next = nullptr;

				}
				else if (s == 0 && e == list_size - 1) { // If sth node is the first node and eth node is the last node
					Node <T>* temp = head;
					tail = nullptr;
					head = nullptr;
					Freeall(temp, list_size);
				}
				else {
					Node<T>* temp = son(s - 1);
					Node<T>* temp2 = son(s);
					temp->next = son(e + 1);
					Freeall(temp2, e - s + 1);
				}
				list_size = list_size - (e - s + 1); // List's size decreases
			}
		}

		void insert(unsigned int i, T d) {
			Node<T>* temp;
			temp = new Node<T>();
			temp->data = d;
			if (i == 0) { // Insert at the first node
				Node<T>* temp1;
				temp1 = head;
				head = temp;
				temp->next = temp1;
			}
			else if (i == list_size - 1) { // Insert at the last node
				tail->next = temp;
				tail = temp;
				temp->next = nullptr;
			}
			else {
				Node<T>* prev, * next;
				prev = son(i - 1);
				next = son(i);
				prev->next = temp;
				temp->next = next;
			}
			list_size++; // List's size increases by 1
		}

		void insert(unsigned int i, List<T>& other) {
			if (i == 0) { // Insert at the first node
				Node<T>* temp;
				temp = head;
				head = other.head;
				other.tail->next = temp;
			}
			else if (i == list_size - 1) { // Insert at the last node
				Node<T>* temp, * temp1;
				temp = son(list_size - 2);
				temp1 = tail;
				temp->next = other.head;
				other.tail->next = temp1;
				tail = other.tail;
			}
			else {
				Node<T>* prev, * next;
				prev = son(i - 1);
				next = son(i);
				prev->next = other.head;
				other.tail->next = next;
				other.head = head;
				other.tail = tail;
			}
			list_size = list_size + other.list_size; // List's size increases 
		}

		void push_back(T in) { // Add one node to the end
			Node<T>* temp;
			temp = new Node<T>();
			temp->data = in;
			if (list_size == 0) {
				head = temp;
			}
			else {
				Node<T>* prev = son(list_size - 1);
				prev->next = temp;
			}

			tail = temp;
			temp->next = nullptr;
			list_size++;
		}

		void Freeall(Node<T>* temp, unsigned int i) { // Helper function that delete i nodes from the node temp
			Node<T>* next = temp;
			for (unsigned int q = 0; q < i; q++) {
				next = temp->next;
				delete temp;
				temp = next;
			}
		}

		Node<T>* son(unsigned int i) { // Helper function that returns the pointer to the ith node
			Node<T>* temp = head;
			if (i > 0) {
				for (unsigned int s = 0; s < i; s++) {
					temp = temp->next;
				}
			}
			return temp;
		}

	private:
		Node<T>* head;
		Node<T>* tail;
		unsigned int list_size;
	};

	template <typename T>
	List<T>::List() {
		head = nullptr;
		tail = nullptr;
		list_size = 0;
	}

	template <typename T>
	List<T>::List(unsigned int N) {
		head = nullptr;
		tail = nullptr;
		list_size = N;
		Node<T>* temp;
		for (unsigned int i = 0; i < N; i++) {
			temp = new Node<T>();
			temp->data = NULL;
			if (head == nullptr) {
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				tail = tail->next;
			}
			tail->next = nullptr;
		}
	}
}


#endif
