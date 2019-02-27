#include <iostream>
#include <stdexcept>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


void printTreeNode(BinaryTreeNode* pNode){

	if(pNode!=nullptr){
		printf("value of this node is:%d\n",pNode->m_nValue);
		if(pNode->m_pLeft!=nullptr)
			printf("value of its lift child is :%d\n",pNode->m_pLeft->m_nValue);
		else
			printf("value of its lift child is null");
		if(pNode->m_pRight!=nullptr){
			printf("value of its right child is:%d",pNode->m_pRight->m_nValue);
		}
		else{
			printf("value of its right child is null");
		}		
	}
	else{
		printf("this node is null");
	}
	printf("\n");
}

void printTree(BinaryTreeNode* pRoot){
	printTreeNode(pRoot);//采用递归打印树
	if(pRoot!=nullptr){
		if(pRoot->m_pLeft!=nullptr)
			printTree(pRoot->m_pLeft);
		if(pRoot->m_pRight!=nullptr)
			printTree(pRoot->m_pRight);
	}
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder);

BinaryTreeNode* Construct(int* preorder,int* inorder,int length){
	if (preorder == NULL || inorder == NULL || length <= 0)
		 return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder){
	int rootValue=startPreorder[0];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=rootValue;
	root->m_pLeft=root->m_pRight=nullptr;

	if(startPreorder==endPreorder){
		if(startInorder==endInorder&&startPreorder==startInorder)
			return root;
		else
			
			throw std::logic_error("Invalid input");
	}
	int *rootInorder=startInorder;
	while(rootInorder<=endInorder && *rootInorder!=rootValue )
		rootInorder++;
	if(rootInorder==endInorder && *rootInorder!=rootValue)
		throw std::logic_error("Invalid input");
	int leftLength=rootInorder-startInorder;
	int *leftPreorderEnd=startPreorder+leftLength;
	if(leftLength>0)
	{
		root->m_pLeft=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
	}
	if(leftLength<endPreorder-startPreorder){
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

void Test(const char* testname,int *preorder,int *inorder,int length)
{
	if(testname!=nullptr)
		printf("Begins:%s\n",testname);
	printf("The preorder sequence is:");
	for(int i=0;i<length;++i){
		printf("%d",preorder[i]);
	}
	printf("\n");

	printf("The inorder sequence is:");
	for(int i=0;i<length;++i){
		printf("%d",inorder[i]);
	printf("\n");
	}

	try{
		BinaryTreeNode *root=Construct(preorder,inorder,length);
		printTree(root);
	}
	catch(std::exception &expection){
q	printf("Invalid Input.\n");
	}
}

void Test1(){
	const int length=8;
	int preorder[length]={1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[length]={4, 7, 2, 1, 5, 3, 8, 6};
	Test("Tset1",preorder,inorder,length);
}

int main(int argc,char* argv[])       
{
	Test1();
	return 0;
}