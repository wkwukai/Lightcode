#include<cstdio>
#include<cstring>

void ReplaceBlanks(char str[],int length)
{
	if(str==nullptr && length<=0){
		return;
	}
    int originallength=0;
	int numberofblanks=0;
	int i=0;
	while(str[i]!='\0'){
		originallength++;
	    if(str[i]=' '){
			numberofblanks++;
         }
         i++;
	}
    int newlength=originallength+numberofblanks*2;
    if(newlength>length){
    	return;
    }
   // int indexoforiginal=originallength;
   // int indexofnew=newlength;
    while(originallength>0 && newlength>originallength){
         if(str[originallength]=' '){
                str[newlength--] ='0';
                str[newlength--]='2';
                str[newlength--]='%';
         }
         else
         	str[newlength--]=str[originallength];
         originallength--;
    }
}



void Test(const char* testName,char str[],int length,char expected[]){
	if(testName!=nullptr)
		 printf("%s begins",testName);
	ReplaceBlanks(str,length);

	if(expected==nullptr && str == nullptr)
		printf("passed.\n");
	else if(expected==nullptr && str!=nullptr)
		printf("failed.\n");
	else if(strcmp(str,expected)==0)
		printf("passed\n");
	else
		printf("failed\n");	
}

void Test1(){
     
	const int length=100;

	char str[length]="hello world";
	Test("Test1", str, length, "hello%20world");
}