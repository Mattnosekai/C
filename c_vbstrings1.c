// By Matt B.
// Emulate Functionality of some VB string commands in C
// Compiled with Dev-C++ 4.9.9.2

#include <stdio.h>
#include <string.h>

int LEN(char* sdata)
{
   //LEN function reurnts length of string
   int len1;
   len1 = strlen(sdata);                 
   return len1; 
} 

char * MID(char* sdata, int start, int ends)
{
 //MID$ funtion returns a string from int start to int ends
 start--;
 int len1;
 len1=LEN(sdata);
 int len2;
 len2=start+ends;
 if (len2>len1){
 return (0);
 }        
char *sdata2=malloc(ends);
memcpy(sdata2,sdata+start,ends);
sdata2[ends]='\0'; // Terminate the string with '\0' or 1 byte of RAM/garbage will show
return sdata2;           
}    

int DELIM(char* ostring,char* strings[],char* delims)
{
     //This is not a VB/BASIC command but a personal routine originally coded by me in BASIC
     //DELIM tokenize the string and split/break it on delimter(s)
     // more than one delimiter can be passed to delims
     // an Array of strings is returned via ostring
     char * pch;
     int i=1;
     pch = strtok(ostring, delims);
    strings[1]=pch;
    while (pch != NULL)
     {
     pch = strtok (NULL, delims);
     i++;
     strings[i]=pch;
     }
return 0;
}      



int main()
{
   // demo showing z being split at comma with 2 strings being returned to array strings2[1] and strings2[2]
   char z[120];
   char z2[120];
   strcpy(z, "12345,6789");
  
   int len2;
   len2=LEN(z);
   char* strings2[100]; 
   DELIM(z,strings2,",");
   printf("%s\n",strings2[1]);
   printf("%s\n",strings2[2]);
       
   getchar();
   return 0;
}

             

 
            
