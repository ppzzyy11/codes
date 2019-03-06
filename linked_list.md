#Linked list
##2.Add Tow Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
	
	
	class Solution {
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        if(l1==NULL) return l2;
	        if(l2==NULL) return l1;
	
	        ListNode* head=new ListNode(0);
	        ListNode* pre=head;
	        int add=0;
	        while(l1||l2||add)
	        {
	            ListNode* node=new ListNode(0);
	            pre->next=node;
	            pre=node;
	
	            if(l1){node->val+=l1->val;l1=l1->next;}
	            if(l2){node->val+=l2->val;l2=l2->next;}
	            node->val+=add;
	            add=node->val/10;
	            node->val=node->val%10;
	        }
	        return head->next;
	    }
	};
	

##19.Remove Nth Node from End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

	Given linked list: 1->2->3->4->5, and n = 2.
	After removing the second node from the end, the linked list be
	
Note:
Given n will always be valid.
Try to do this in one pass.

###19.1,fast&slow pointer的方法
一个快指针比slow指针快N步,当fast抵达尾部的时候,删除slow的node

	class Solution
	{
	public:
	    ListNode* removeNthFromEnd(ListNode* head, int n)
	    {
	        ListNode** t1 = &head, *t2 = head;
	        for(int i = 1; i < n; ++i)
	        {
	            t2 = t2->next;
	        }
	        while(t2->next != NULL)
	        {
	            t1 = &((*t1)->next);
	            t2 = t2->next;
	        }
	        *t1 = (*t1)->next;
	        return head;
	    }
	};
	
###19.2.通过Reucr的方法来确定倒数的位置

	ListNode*  Recur(ListNode* head,int n,int &i)
	{
		if(head==NULL) {i=0;return NULL;}
		Recur(head->next,n,i));
		i=i+1;
		操作
	}
		
##21.Merge Two Sorted List

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


###21.1Recur

	class Solution {
	public:
	    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	        if(l1 == NULL) return l2;
	        if(l2 == NULL) return l1;
	        
	        if(l1->val < l2->val) {
	            l1->next = mergeTwoLists(l1->next, l2);
	            return l1;
	        } else {
	            l2->next = mergeTwoLists(l2->next, l1);
	            return l2;
	        }
	    }
	};

###21.2 Iterate

	class Solution {
	public:
	    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	        if(l1==NULL) return l2;
	        if(l2==NULL) return l1;
	
	        ListNode* head=new ListNode(0);
	        ListNode* cur=head;
	
	        while(l1&&l2)
	        {
	            if(l1->val<l2->val)
	            {
	                cur->next=l1;
	                l1=l1->next;
	            }else
	            {
	                cur->next=l2;
	                l2=l2->next;
	            }
	            cur=cur->next;
	        }
	        if(l1) cur->next=l1;
	        else cur->next=l2;
	
	        return head->next;
	    }
	};
	
	
##23.Merge K Sorted List
###23.1 

总结起来有点繁琐,不总结了
是太繁琐了,总共8页,这都142行了,才总结了半页,我yue,gg
以后都不总结了,慢慢学习吧,总结的纸质版可以买个文件夹保存起来(用处也没有想象中的那么大,但会看的时候会很有用,节省时间吧)

