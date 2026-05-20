#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

// Her bir veriyi ve bir sonraki düðümün adresini tutar
template <typename Object>
class Node{
	public:
		Object item;         // Saklanan veri 
		Node<Object> *next;  // Bir alttaki düðüme iþaretçi
		
		Node(const Object& item,Node<Object> *next=NULL){
			this->item = item;
			this->next = next;
		}
};


template <typename Object>
class Stack{
	private:
		Node<Object> *topOfStack; // Yýðýtýn en üstündeki düðüm
		
	public:
		Stack(){
			topOfStack=NULL; // Baþlangýçta yýðýt boþ
		}
		bool isEmpty()const{
			return topOfStack == NULL; // Yýðýt boþ mu kontrolü
		}
		void push(const Object& item){
            // Yeni veriyi en üste ekler
		    topOfStack	= new Node<Object>(item,topOfStack);
		}
		void pop(){
			if(isEmpty()) throw "Stack is Empty";
			Node<Object> *tmp = topOfStack;
			topOfStack = topOfStack->next; // En üstteki düðümü kaldýrýr
			delete tmp; // Belleði temizler
		}
		const Object& top()const{
			if(isEmpty()) throw "Stack is Empty";
			return topOfStack->item; // En üstteki veriyi döndürür
		}
		void makeEmpty(){
			while(!isEmpty()) pop(); // Tüm yýðýtý temizler
		}
		~Stack(){
			makeEmpty(); // Bellek sýzýntýsýný önlemek için yýðýtý boþaltýr
		}
};

#endif
