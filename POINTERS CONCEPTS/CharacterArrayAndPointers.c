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


void print(char *c){
   /* while(*c!='\0'){
        printf("%c",*c);
        *c++;
    }*/
   int i;
   while(c[i]!='\0'){
    printf("%c",c[i]);
    i++;
   }
}

int main(){
    char c[]="HELLO";
    print(c);
}

