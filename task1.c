
#include <stdio.h>
#define max 100 // define the maximum string user input

int main() {
	int count = 0; // count's variable to count the vowel sounds. 
	char str[max], c;// To declare the array str[] with max define above.
	printf("Enter a string: ");
	fgets(str,max,stdin); // fgets() reads input from user
	printf("String is: %s\n", str); // To show the string the user input
   	while(str[count] != '\0') { // Function to check the vowel sounds in string
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