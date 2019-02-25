#include <stack>
using namespace std;
#include <iostream>
struct ListNode{
	int m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value){
	ListNode* pNode=new ListNode();
	pNode->m_nValue=value;
	pNode->m_pNext=nullptr;

	return pNode;
}

void connectListNodes(ListNode* pCurrent,ListNode* pNext){
	if(pCurrent==nullptr){
         printf("Error to connect two nodes");
         exit(1);
	}
	pCurrent->m_pNext=pNext;
}

void printList(ListNode* pHead){
	printf("print List start:\n");
	ListNode* pNode=pHead;
	while(pNode!=nullptr){
		printf("%d\n",pNode->m_nValue);
		pNode=pNode->m_pNext;
		
	}
	printf("end\n");
}

void DestoryList(ListNode* pHead){
	ListNode* pNode=pHead;
	while(pNode!=nullptr){
		pHead=pHead->m_pNext;
		delete pNode;
		pNode=pHead;
	}

}

void printListReversingly_Iteratively(ListNode* pHead){
	std::stack<ListNode*>nodes;

	ListNode* pNode=pHead;
	while(pNode!=nullptr){
         nodes.push(pNode);
         pNode=pNode->m_pNext;
	}
	while(!nodes.empty()){
		pNode=nodes.top();
		printf("%d\t",pNode->m_nValue);
		nodes.pop();
	}
}

void printListReversingly_Recursively(ListNode* pHead){
	if(pHead!=nullptr){
		if(pHead->m_pNext!=nullptr){
			printListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t",pHead->m_nValue);
	}
}

void Test(ListNode* pHead){
	printList(pHead);
	printListReversingly_Iteratively(pHead);
	printf("\n");
	printListReversingly_Recursively(pHead);
	printf("\n");
}

void Test1(){
	printf("Test1:\n");

	ListNode* pNode1=CreateListNode(1);
	ListNode* pNode2=CreateListNode(2);
	ListNode* pNode3=CreateListNode(3);
	ListNode* pNode4=CreateListNode(4);
	ListNode* pNode5=CreateListNode(5);

	connectListNodes(pNode1,pNode2);
	connectListNodes(pNode2,pNode3);
	connectListNodes(pNode3,pNode4);
	connectListNodes(pNode4,pNode5);

	Test(pNode1);

	DestoryList(pNode1);
}

void Test2(){
	printf("Test2:\n");
	ListNode* pNode1=CreateListNode(1);

	Test(pNode1);

	DestoryList(pNode1);
}

void Test3(){
	printf("Test3:\n");
	Test(nullptr);
}

int main(int argc,char* argv[]){
	Test1();
	Test2();
	Test3();
}