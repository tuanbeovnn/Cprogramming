#include <stdio.h>
#include <string.h>
#define max 100


/*The function to calculate the length of string*/
int string_length(char s[]) {
   int i=0;

   while(s[i]!='\0')
      i++;

   return i;	
}

/*The function to reverse of the string*/
void string_reverse(char st[]) {
   int i,j,len;
   char ch;
   len = string_length(st) - 1;
   j = len;
   i = 0;

   while(i < j) {// this is while loop to change the position.
      ch = st[j];
      st[j] = st[i];
      st[i] = ch;
      i++;
      j--;
   }
}

int main (void) {
    
    char line[max]; // define a array line with max =100
    printf("Enter the sentence...\n");
    gets(line);// reads input from user.
    char reverse[max] = "", temp[max]; // Initalize the temporary variable
    int i, j, n; 


   n = string_length(line); 

   for(i = n-1; i >= 0; --i) {

      for(j = 0; i >= 0 && line[i] != ' '; --i,++j)
         temp[j] = line[i];

      temp[j] = '\0';

      string_reverse(temp);
      
      strcat(reverse,temp);// Used to concatenate 2 strings
      strcat(reverse," ");
   }

   printf("String is :\n %s", line);
   printf("\nNow reversing the sentence...:\n %s",reverse);

   return 0;
}