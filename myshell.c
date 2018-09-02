#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#define clear() printf("\033[H\033[J");
void initshell(){
	clear();      
	printf(" _________\n");
	printf("|\n");
	printf("|\n");
	printf("|\n");
	printf("|________ \n");
	printf("         |\n");
	printf("         |\n");
	printf("         | \n");
	printf("_________| A S H \n");
	printf("\n\nWelcome %s\n\n",getenv("USER"));
	sleep(2);
}
void printcurr(){
	char a[1000];
	getcwd(a,sizeof(a));
	printf("%s\n",a);
}
int input(char* a){
	char *b;
	b=readline("$ ");
	add_history(b);
	if(strlen(b)!=0){
		strcpy(a,b);
		return 0;
	}
	free(b);
	return 1;
}
void run(char *a,char **b){
	if(strcmp(b[0],"cd")==0){
		if(b[1]==NULL)
			chdir("/home/sarthak");
		else
			chdir(b[1]);
	}
	else if(strcmp(b[0],"pwd")==0){
		printcurr();
	}
	else if(strcmp(b[0],"exit")==0)
		exit(0);
	else{
		pid_t pid=fork();
		if(pid<0)	printf("Forking failed\n");
		else if(pid==0){
			if(execvp(b[0],b)==-1)
				printf("Not a valid command\n");
			exit(0);		
		}
		else{
			wait(NULL);			
		}
	}
}


void parse(char *a,char **b){
	int i;
	for(i=0;i<100;i++){
		b[i]=strsep(&a," ");
		if(b[i]==NULL)	break;
	}
}
int main(){
	char inputs[100],*parsed[100];
	initshell();
	while(1){
		input(inputs);
		parse(inputs,parsed);
		run(inputs,parsed);
	}
    free(parsed);
	return 0;
}