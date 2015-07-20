#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int data;
	struct node* next;
}Node;
Node* insert(Node* head_ref,int data)
{
	Node* dummy=head_ref;
	Node* prev=NULL;
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	if(head_ref==NULL)
	return temp;
	else
	{
		while(dummy->data< data)
		{
			prev=dummy;
			dummy=dummy->next;
			if(dummy==NULL)
			{
				prev->next=temp;
				return head_ref;
			}
		}
			if(dummy==head_ref)
			{
				temp->next=head_ref;
				return temp;
			}
			prev->next=temp;
			temp->next=dummy;
			return head_ref;
	}
	
}
void display(Node* head_ref)
{
	while(head_ref!=NULL)
	{
		cout<<head_ref->data<<"->";
		head_ref=head_ref->next;
	}
	cout<<"NULL"<<endl;
	
	
}
Node* del(Node*head_ref,int data)
{
	Node* dummy=head_ref;
	Node* prev=NULL;
	while(dummy->data!=data)
	{
		prev=dummy;
		dummy=dummy->next;
		if(dummy==NULL)
		{
			cout<<"No such element :("<<endl;
			return head_ref;
		}
	}
	if(dummy==head_ref)
	{
		head_ref=head_ref->next;
		free(dummy);
		return head_ref;
	}
	else if(dummy->next==NULL)
	{
		free(dummy);
		prev->next=NULL;
		return head_ref;
	}
	else
	{
		prev->next=dummy->next;
		free(dummy);
		return head_ref;
	}
	
}
int main()
{
	Node* head=NULL;
	head=insert(head,10);
	head=insert(head,8);
	head=insert(head,9);
	head=insert(head,11);
	display(head);
	head=del(head,9);
	display(head);
	return 0;
}
