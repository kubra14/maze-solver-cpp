#include <iostream>
#include<stack>
#define SIZE 5

using namespace std;

  class Queue{
  	private:
  		int items[SIZE],front,rear;
  		
  	public:
  		Queue(){
  			front=-1;
  			rear=-1;
		  }
	bool isFull(){
		if(front==0 && rear==SIZE - 1){
			return true;
		}
		return false;
	}
	bool isEmpty(){
		if(front==-1)
			return true;
		else 
		    return false;
    }
	void enQueue(int element){
		if(isFull()){
			cout<<"queue dolu";
		}
		else{
			if(front=-1){
				front=0;
				rear++;
				items[rear]=element;
				cout<<endl;
			}
		}
	}
	void deQueue(){
		int element;
		if(isEmpty()){
			cout<<"queue boþ";
			return(-1);
		}
		else{
			element=items[front];
			if(front>=rear){
				front=-1;
				rear=-1;
			}
			else{
				front++;
			}
			cout<<endl;
		}
	}
	void display(){
		if(isEmpty()){
			cout<<"queue bos";
		}
		else{
			for(int i=front;i<=rear;i++){
				cout<<items[i];
			}
		}
	}
  };
int main(){
  	Queue q;
  	q.enQueue(1);
  	q.enQueue(2);
  	q.enQueue(3);
  	q.enQueue(4);
  	q.enQueue(5);
  	
  	q.display();
  	
  	q.deQueue();
  	
  	q.display();
  	
  	return 0;
}

