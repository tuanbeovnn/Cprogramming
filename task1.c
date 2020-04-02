
#include <stdio.h>
#define max 100

int main() {
	int count = 0;
	char str[max], c;
	printf("Enter a string: ");
	fgets(str,max,stdin);
	printf("String is: %s\n", str); 
   	while(str[count] != '\0') {
   	  c = str[count];
   	  if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'
   	  	|| c == 'o' || c == 'O' || c == 'u' || c == 'U') {

   	  	printf("%c", c);
   	  }

   	  count++;
   	}

   	printf("\n");

	return 0;
}