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
class Stack{
	public:
		node<E>* head;
		int size;
	Stack(){
		head=NULL;
		size=0;
	}
	~Stack(){
		clear();
	}
	void push(E);
	void pop();
	int get_size();
	E get_top();
	bool is_empty();
	void reverse();
	void clear();
};

template<class E>
void Stack<E> :: push(E var){
	node<E>* tmp=new node<E>(var);
	size++;
	if(head==NULL){
		head=tmp;
		return;
	}
	tmp->link=head;
	head=tmp;
}

void empty(){
	cout << "Stack is Empty!!!\n";
}

void line(){
	cout << "\n-----------------------------------------\n";
}

template<class E>
void Stack<E> :: pop(){
	if(size==0){
		empty();
		return;
	}
	cout << head->value << " is poped\n";
	node<E>* tmp=head;
	head=head->link;
	delete (tmp);
	size--;
}


template<class E>
int Stack<E> :: get_size(){
	return size;
}

template<class E>
bool Stack<E> :: is_empty(){
	if(size==0){
		return true;
	}
	return false;
}

template<class E>
E Stack<E> :: get_top(){
	if(is_empty()==true){
		empty();
		return -1;
	}
 	return head->value;	
}

template<class E>
void Stack<E> :: reverse(){
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
void Stack<E> :: clear(){
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
	cout << "Note:\t1.Push\n"
		 << "\t2.Pop\n"
		 << "\t3.Size\n"
		 << "\t4.Top Element\n"
		 << "\t5.Reverse the Stack\n"
		 << "\t6.Clear Stack\n"
		 << "\t7.Exit\n";
		 line();
}

int main(){
	int counter=0;
	int choice,element;
	Stack<int> tmp;
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
				tmp.push(element);
				cout << "Pushed successfullly!!!\n";
				line();
				break;
			case 2:
				tmp.pop();
				line();
				break;
			case 3:
				cout << "Size is " << tmp.get_size();
				line();
				break;
			case 4:
				if(tmp.is_empty()==false)
				cout << "Top is " << tmp.get_top();
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
					cout << "Stack is cleared successfullly!!!\n";
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
