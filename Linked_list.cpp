#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
const char newl='\n';
// Main code starts here
class Node{
	public:
		int value;
		Node* next;
};
Node* insert_at_tail(Node* head, int data){
	Node* new_node;
	new_node = new Node();
	new_node->value = data;
	new_node->next = NULL;
	if(head==NULL){
		head = new_node;
		return head;
	}
	Node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = new_node;
	return head;
}
Node* insert_at_head(Node* head, int data){
	Node* new_node = new Node();
	new_node->value = data;
	new_node->next = head;
	return new_node;
}
void printlinked_list(Node* head){
	while(head){
		cout<<head->value<<" ";
		head = head->next;
	}
	cout<<newl;
}
bool detectLoop(Node* head){
    Node *slow_p = head, *fast_p = head;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}
Node* delete_first_node_by_value(Node* head , int data){
	Node* prev = NULL;
	Node* temp = head;
	if(head->value==data){
		return head->next;
	}
	while(head!=NULL){
		if(head->value==data){
			prev->next = head->next;
			return temp;
		}
		prev = head;
		head = head->next;
	}
	return temp;
}
Node * delete_value_by_position(Node* head, int position){
	if(position==0){
		return head->next;
	}
	int count = 0;
	Node* prev = NULL;
	while(head){
		if(count==position){
			break;
		}
		prev = head;
		head = head->next;
		count++;
	}
	prev->next = head->next;
	return head;
}
void answer(int test){
	Node* head = NULL;
	// checking insert at tail function
	// Complexity = O(v) where v is the number of nodes in the linked_list
	// except when the head is empty
	head = insert_at_tail(head,2);
	head = insert_at_tail(head,3);
	printlinked_list(head);
	// checking insert at head function
	// Complexity = O(1)
	head = insert_at_head(head,1);
	printlinked_list(head);
	//checking loop
	//Checking all by value
	//Adding anathor 3 so that all instances can be removed
	head = insert_at_tail(head, 3);
	printlinked_list(head);
	//now removing all 3
	head = delete_first_node_by_value(head,3);
	printlinked_list(head);
	// adding 3 so that linked list is same as before
	head = insert_at_tail(head,3);
	// Checking delete by position
	//First there is no loop
	if(detectLoop(head)){
		cout<<"There is a loop"<<newl;
	}
	else{
		cout<<"There is no loop found"<<newl;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
   	//cin>>test;
    int curr = 1;
    while(test--){
        answer(curr);
        curr++;
    }
}

