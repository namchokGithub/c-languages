#include<stdio.h>
#include<string.h>
void clear_data(char *name,char *pass);
int main()
{
	char *name,*admin = "pech",*pass,*pass_admin = "4751";
	clear_data(name, pass);

	printf("Good luck\n");
return 0;
}
void clear_data(char *name,char *pass)
{
	char *ans = "no";
	printf("Please enter name: ");
	scanf("%s",name);
	printf("Please enter password: ");
	scanf("%s",pass);
	printf("Do you want to clear data ? (yes/no):");
	scanf("%s",*ans);
	if (strcmp(ans,"yes") == 0){
		printf("Clear data complet\n");
	}
}
