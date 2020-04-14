#include<bits/stdc++.h>
using namespace std;

template<class E>
class node{
	public:
		E value;
		node<E>* link;
		node(){
			link=NULL;
			value=-1;
		}
		node(E n){
			value=n;
			link=NULL;
		}
};

template<class E>
class Queue{
	public:
		node<E>* head;
		int size;
	Queue(){
		head=NULL;
		size=0;
	}
	~Queue(){
		clear();
	}
	void insert(E);
	void dequeue();
	int get_size();
	E front();
	bool is_empty();
	void reverse();
	void clear();
	node<E>* add(E,node<E>*);
};

template<class E>
node<E>* Queue<E> :: add(E value,node<E>* tmp){
	if(tmp==NULL){
		return new node<E>(value);
	}
	tmp->link=add(value,tmp->link);
}

template<class E>
void Queue<E> :: insert(E var){
	node<E>* tmp=new node<E>(var);
	size++;
	head=add(var,head);
}

void empty(){
	cout << "Queue is Empty!!!\n";
}

void line(){
	cout << "\n-----------------------------------------\n";
}

template<class E>
void Queue<E> :: dequeue(){
	if(size==0){
		empty();
		return;
	}
	cout << head->value << " is dequeued\n";
	node<E>* tmp=head;
	head=head->link;
	delete (tmp);
	size--;
}


template<class E>
int Queue<E> :: get_size(){
	return size;
}

template<class E>
bool Queue<E> :: is_empty(){
	if(size==0){
		return true;
	}
	return false;
}

template<class E>
E Queue<E> :: front(){
	if(is_empty()==true){
		empty();
		return -1;
	}
 	return head->value;	
}

template<class E>
void Queue<E> :: reverse(){
	node<E>* pre,*curr,*next,*tmp;
	pre=next=NULL;
	curr=head;
	while(curr!=NULL){
		next=curr->link;
		curr->link=pre;
		pre=curr;
		curr=next;
	}
	head=pre;
}

template<class E>
void Queue<E> :: clear(){
	if(size==0) return ;
	node<E>* tmp;
	while(head){
		tmp=head;
		head=head->link;
		delete(tmp);
		size--;
	}
}


void instruction(){
	cout << "Note:\t1.Insert\n"
		 << "\t2.Dequeue\n"
		 << "\t3.Size\n"
		 << "\t4.Front Element\n"
		 << "\t5.Reverse the Queue\n"
		 << "\t6.Clear Queue\n"
		 << "\t7.Exit\n";
		 line();
}

int main(){
	int counter=0;
	int choice,element;
	Queue<int> tmp;
	while(1){
		if(counter%7==0){
			instruction();
		}
		cout << "Enter your choice : ";
		cin >> choice;
		counter++;
		switch(choice){
			case 1:
				cout << "Enter the elemenet : " ;
				cin >> element;
				tmp.insert(element);
				cout << "Pushed successfullly!!!\n";
				line();
				break;
			case 2:
				tmp.dequeue();
				line();
				break;
			case 3:
				cout << "Size is " << tmp.get_size();
				line();
				break;
			case 4:
				if(tmp.is_empty()==false)
				cout << "Top is " << tmp.front();
				else empty();
				line();
				break;
			case 5:
				tmp.reverse();
				if(tmp.is_empty()==false)
				cout << "Reversed successfullly!!!\n";
				else empty();
				line();
				break;
			case 6:
				if(tmp.is_empty()) empty();
				else{
					tmp.clear();
					cout << "Queue is cleared successfullly!!!\n";
				}
				line();
				break;
			case 7:
				return 0;
			default:
				line();
		}
	}
}
