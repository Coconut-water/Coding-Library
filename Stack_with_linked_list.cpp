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
#define ll long long
#define debug(x) cerr << (#x) << "'s value is " << (x) << newl
// Main code starts here
class Ele_of_stack{
	public:
		int value;
		Ele_of_stack* next;
};
Ele_of_stack* push(Ele_of_stack* head, int data){
	Ele_of_stack* new_node = new Ele_of_stack();
	new_node->value = data;
	new_node->next = head;
	return new_node;
}
int top(Ele_of_stack* head){
	return head->value;
}
Ele_of_stack* pop(Ele_of_stack*head){
	if(head==NULL){
		cout<<"Stack Underflow"<<newl;
	}
	head = head->next;
	return head;
}
void answer(int test){
	// initializing a new stack;
	Ele_of_stack* head;
	// using push to push a new value in stack
	head = push(head,1);
	head = push(head,2);
	// Top returns the topmost value of stack
	cout<<top(head);
	head = push(head,3);
	cout<<top(head)<<newl;
	// pop removes the topmost element
	head = pop(head);
	cout<<top(head)<<newl;

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

