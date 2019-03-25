void DeletedNode(ListNode* ListHead,ListNode*toBeDelete){
 

		if(!ListHead||!toBeDelete)
			return;
		if(toBeDelete->m_pNext != nullptr){
		    ListNode* pNext=toBeDelete->next;
		    toBeDelete->value=pNext->value;
		    toBeDelete->next=pNext->next;

		    delete pNext;
		    pNext=nullptr;

		}

		else if(*ListNode==toBeDelete)
			delete toBeDelete;
			toBeDelete=nullptr;
		   *ListNode=nullptr;
		else
			ListNode* pNode=*ListNode;
			while(pNode->next!=toBeDelete)
				pNode=pNode->next;
			pNode->next=nullptr;
			delete toBeDelete;
			toBeDelete=nullptr;
	
}

void Test(ListNode* ListHead,ListNode* pNode){
	printf("The origial list is:");
	printList(pListHead);

	printf("The node to be deleted is:");
	printListNode(pNode);

	DeletedNode(&ListHead,pNode);

	printf("The result list is:");
	printList(ListHead);
}


void Test1(){
	ListNode * pNode1=CreateListNode(1);\
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode3);

	DestroyList(pNode1);
}

int main(int argc,char* argc[]){
   Test1();
   Test2();
   Test3();

   return 0;
}

struct ListNode
{ 
	int value;
	ListNode* next;
	
};

ListNode* CreateListNode(int value){
	ListNode* pNode=new ListNode();
	pNode->value=pHead->value;
	pNode->next=nullptr;

	return pNode;

}

void ConnectListNodes(ListNode* pHead,ListNode* pNode){
	if(pHead->next==nullptr)
		printf("error");
	else
		pHead->next=pNode;
}


int printList(ListNode* pHead){
	ListNode* pNode=pHead;
	while(pNode->next!=nullptr){
		printf("%d\n",pNode->value);
		pNode=pNode-next;
	}

}


void DestroyList(ListNode* pHead){
       ListNode* pNode=pHead;
       while(pNode!=nullptr){
       		pHead=pHead->next;
       		delete pNode;
       		pNode=pHead;
       }   
}