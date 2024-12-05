#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace myQueue {
	template <typename T>
	class Node {
	public:
		T info;
		Node* next;
		Node* prev;

		Node(T value) {
			info = value;
			next = prev = nullptr;
		}
	};

	//Queueue - FIFO = first in, first out
	template <typename U>
	class Queue {
	protected:
		Node<U>* head;
		Node<U>* current;
	public:
		Queue() {
			head = current = nullptr;
		}
		~Queue() { while (!isEmpty())pop_front(); }//נואכ³חאצ³ÿ

		bool isEmpty()const { return head == nullptr; }//נואכ³חאצ³ÿ

		U first()const {
			if (isEmpty())throw "MyQueue is empty!\n";
			return head->info;
		}//נואכ³חאצ³ÿ

		void push_back(U value) { 
			Node<U>* el = new Node<U>(value);
			if (isEmpty())
			{
				head = current = el;
			}
			else 
			{
				current->next = el;
				el->prev = current;
				current = current->next;
			}
		}//נואכ³חאצ³ÿ
		void pop_front() { 
			if (!isEmpty())
			{
				if (head!=current)
				{
					head = head->next;
					delete head->prev;
					head->prev = nullptr;
				}
				else
				{
					delete current;
					head = current = nullptr;
				}
			}
		}//נואכ³חאצ³ÿ

		void show()const { 
			if (isEmpty()) {
				cout << "MyQueue is empty!";
				return;
			}
			Node<U>* p = head;
			while (p != nullptr) {
				cout << p->info << " ";
				p = p->next;
			}
			cout << endl;
		}//נואכ³חאצ³ÿ
	};
}
