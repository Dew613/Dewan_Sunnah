#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[13]= "TEST";
char str2[13]="";


int slen(char *a){
  int i=0;
  while(*(a++)!=0){
    i++;
  }
  return i;
}

char* sncpy(char *s1,char *s2, int n){
  int i=0;
  for (i=0; i<n && *(s2)!=0; i++)
    *(s1++)=*(s2++);
  for(i; i<n; i++)
    *(s1++)=0;
  return s1;
}

char* scat(char *s1, char *s2){
  int l=slen(s1);
  int i=0;
  for (i; i<l;i++)
    s1++;
  for (i=0;*(s2)!= 0; i++){
    if (i==0)
      *(s1)=*(s2);
    else
      *(s1++)=*(s2++);
  }
  *(s1++)=0;
  return s1;
}

int scmp(char *s1, char *s2){
  if (*s1==0 &&*s2==0)
    return 0;
  if(*s1==0 && *s2!=0)
    return -1;
  if (*s1!=0 && *s2==0)
    return 1;
  while(*s1!=0){
    if (*s2==0)
      return 1;
    if(*s1>*s2)
      return 1;
    if(*s1<*s2)
      return -1;
    s1++;
    s2++;
  }
  return 0;
}

char* schr(char *s1, char key){
  while (*s1!=key && *s1!=0)
    s1++;
  return *s1;
}
  

int main(){
  printf("             Test for slen \n");
  printf("str1=Test\t len=4\n");
  printf("str2=,\t len=0\n");
  printf("str1=Test\t len=%d\n", slen(str1));
  printf("str2=,\t len=%d\n", slen(str2));
  printf("\n");
  printf("\n");


  printf("             Test for sncpy \n");
  char str3[]="To be or not to be";
  char str4[40];
  char str5[40];
  sncpy(str4, str3, sizeof(str4));
  sncpy(str5, str4, 5);
  str5[5]= 0;
  printf("copying s1 to s2: s1= To be or not to be, s2=, \n");
  printf("s2 is now: ");
  printf(str4);
  printf("\n");
  printf("copying first five of s2 to s3: s2= To be or not to be, s=, \n");
  printf("s3 is now: ");
  printf(str5);
  printf("\n");
  printf("\n");


  printf("              Test for scat \n"); 
  char str[80];
  printf("starting string: These; strings to be concatenated: strings, are, concatnated \n");
  sncpy(str, "These ", sizeof(str));
  scat(str, "strings ");
  scat(str, "are ");
  scat(str, "concatenated. \n");
  printf(str);
  printf("\n");
  printf("\n");


  printf("              Test for scmp \n");
  char dog[]="zygarde";
  char cat[]="abra";
  char tiger[]="abra";
  char test[13];
  printf("compare zygarde to abra: ");
  printf("%d \n", scmp(dog,cat));
  printf("compare abra to zygarde: ");
  printf("%d \n", scmp(cat,dog));
  printf("compare zygarde to ,: ");
  printf("%d \n", scmp(dog,test));
  printf("compare abra to abra: ");
  printf("%d \n", scmp(cat,tiger));
  printf("\n");
  printf("\n");


  printf("              Test for schr \n");
  char search[64]="Looking for a L";
  char find='L';
  printf("Looking for L in Looking for a L: ");
  printf("[%c] \n",schr(search, find));
  printf("Looking for k in Looking for a L: ");
  printf("[%c] \n",schr(search, 'k'));
  printf("Looking for z in Looking for a L: ");
  printf("[%c] \n",schr(search, 'z'));

  printf("\n");

  return 0;
}
