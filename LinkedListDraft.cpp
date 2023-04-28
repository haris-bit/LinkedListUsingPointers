#include <iostream>
using namespace std;

class LinkedList {
	private:
		
		class ListNode {
			public:
				int data;
				ListNode* next;
				
				ListNode(int d)    
				{
					data = d;
					next = NULL;
				}
		};
		
		ListNode* head;
		
	public:
		
		LinkedList()
		{
			head = NULL;
		}
		
		~LinkedList()
		{
			std::cout<<"Linked List Destroyed!"<<std::endl;
		}
		
		void append(int d)
		{
			if(head==NULL)
			{
				head = new ListNode(d);
				return; 
			}
			
			ListNode* tmp = head;
			while(tmp->next!=NULL)
			{
				tmp = tmp->next;
			}
			
			tmp->next = new ListNode(d);
			
		}
		
		void display()
		{
			ListNode* tmp = head;
			while(tmp!=NULL)
			{
				cout<<tmp->data<<endl;
				tmp = tmp->next;
			}
		}
		
		
		void erase(int d)
		{
			ListNode* tmp = head;
			while(tmp!=NULL && tmp->next!=NULL && tmp->next->data!=d)
			{
				tmp = tmp->next;
			}
			
			if(tmp!=NULL)
			{
				ListNode* junk = tmp->next;
				tmp->next = tmp->next->next;
				delete junk;
			}
		}
		

		
		void insertBefore(int d, int e)      
		{
			if(head==NULL)
			{
				return;
			}
			
			if(head->data==e)
			{
				ListNode* tmp = new ListNode(d);
				tmp->next = head;
				head = tmp;
				return;
			}
		
			ListNode* tmp = head;
			while(tmp!=NULL && tmp->next->data != e)
			{
				tmp = tmp->next;	
			}
			
			if(tmp!=NULL)
			{
				ListNode* nn = new ListNode(d);
				nn->next = tmp->next;
				tmp->next = nn;	
			}
				
		}
		
		
		int count()
		{
			ListNode* tmp = head;
			int count = 0;
			while(tmp!=NULL)
			{
				count += 1;
				tmp = tmp->next;	
			}
			return count;
		}
		
		
		void addHead(int value)
		{
			if(head==NULL)
			{
				return;
			}
				
			ListNode* tmp = new ListNode(value);
			tmp->next = head;
			head = tmp;
			return;
		}
		
		
		//still contains a small bug for the removal of the beginning nodes 
		void removeBefore(int value)
		{
		
			if(head==NULL)
			{
				return;
			}
			
			if(head->next->data==value)
			{
				return;
			}
			
			ListNode* tmp = head;
			while(tmp->next->next->data!=value)
			{
				tmp = tmp->next;
			}
			
			if(tmp!=NULL)
			{
				ListNode* junk = tmp->next;
				tmp->next = tmp->next->next;
				delete junk;
			}
			
		}
		
		
		
		
		void insertNth(int value, int N)
		{
			if(head==NULL)
			{
				return;
			}
			
			ListNode* tmp = head;
			int count = 0;
			while(tmp!=NULL)
			{
				count += 1;
				tmp = tmp->next;
				if(count==N-1)
				{
					break;
				}
			}
			if(tmp!=NULL)
			{
//				ListNode* nn = new ListNode(value);
//				nn->next = tmp->next;
//				tmp->next = nn;
//				return;	
				ListNode* nn = new ListNode(value);
				tmp->next = nn;
				nn->next = tmp->next->next;
				return;
			}
			
		}
		
		
		
		
//		void reverse()
//		{
//			if(head==NULL)
//			{
//				return;
//			}
//			
//			ListNode* prev = NULL;
//			ListNode* next = NULL;
//			while(head!=NULL)
//			{
//				next = head->next;
//				head->next = prev;
//				prev = head;
//				head = next;
//			}
//			head = prev;
//			//return head;
//		}
		
		
		
		void reverse()
		{
			ListNode* prev = NULL;
			ListNode* next = NULL;
			while(head!=NULL)
			{
				next = head->next;
				head->next = prev;
				prev = head;
				head = next;
			}
			head = prev;
		}
		
		
		
		
//		void sort()
//		{
//			if(head==NULL)
//			{
//				return;
//			}
//			
//			ListNode* tmp = head;
//			while(tmp!=NULL)
//			{
//				while(tmp!=NULL)
//				{
//					while(tmp->next!=NULL)
//					{
//						if(tmp->next->data < tmp->data)
//			            {
//			                int temp = tmp->data;
//			                tmp->data = tmp->next->data;
//			                tmp->next->data = temp;
//			            }
//					}
//				}
//				tmp = tmp->next;
//			}
//			
//		}
		
		
//		void reverse()
//		{
//			ListNode* tmp = head;
//			while(tmp!=NULL)
//			{
//				tmp = tmp->next
//			}
//			while(tmp!=head)
//			{
//			
//			}
//		}
		
};



int main()
{
	LinkedList c;
	c.append(10);
	c.append(20);
	c.append(30);
	c.append(40);
	
	c.erase(40);
	c.insertBefore(333, 10);

	c.addHead(2222);

	//c.removeBefore(20);
	
	//c.insertNth(1111, 3);
	
	c.display();
	
	cout<<"Count: "<<c.count()<<endl;
	
	//	c.sort();	
	//	c.display();
		
		
	//reversing the linked list
	//	c.reverse();
	//	c.display();	
	return 0;
}
