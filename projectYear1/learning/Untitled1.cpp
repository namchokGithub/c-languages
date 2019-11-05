#include<stdio.h>
#include<string.h>
int main()
{
	char* str;
	char ch;
	printf("Please enter char: ");
	ch = getch();
	gets(str);
	printf("%c | %s\n",ch,str);
}
