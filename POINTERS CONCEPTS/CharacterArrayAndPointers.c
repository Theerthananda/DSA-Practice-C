#include<stdio.h>
#include<string.h>
/*int main(){
    char c[]="JHON";
   c[0]='j';
    c[1]='h';
    c[2]='o';
    c[3]='n';
    c[4]='\0';
    int len=strlen(c);
    

    printf("The string is %s\n",c);
    printf("Length of string is %d\n",len);
    printf("Size = %d\n",sizeof(c));
}*/


void print(const char *c){
    // c[0]='a';  not modifyable
    /*while(*c!='\0'){
        printf("%c",*c);
        *c++;
    }*/
  
   int i=0;
   while(c[i]!='\0'){
    printf("%c",c[i]);
    i++;
   }
}

int main(){
   // char *c="HELLO"; not modifyable
   char c[30]="hello";
    print(c);
}

