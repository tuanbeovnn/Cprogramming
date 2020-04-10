#include<stdio.h>
#define max 100


void caesar(char *s, int key){
	/*
		function to encrypt the given string and key

		Parameter: char *s - The given string needs to be encryted
					int key - The given key 
	*/

	//Initialize the counter variable
	int i;      // Initalize the temporary variable
	char ch;    // For loop encrypt single letter in string
	for(i=0; s[i] != '\0'; i++){
		ch=s[i];
		// If letter in English alphabet (either upper and lower )
		// replace by another letter that is key position down to it.
		if(ch >= 'a' && ch<='z'){
			ch=ch+key;
			if(ch > 'z'){
				ch= ch-'z'+'a'-1;
			}
			s[i]=ch;
		}
		else if (ch >= 'A' && ch <= 'Z'){
			ch= ch+key;
			if (ch > 'Z'){
				ch=ch-'Z'+'A'-1;
			}
			s[i]=ch;
		}
	}
}
int main(){
	char sentence[max];
	int key;
	printf("Enter a sentence to encrypt: ");
	gets(sentence);
	printf("Enter key: ");
	scanf("%d", &key);
	caesar(sentence, key);
	printf("Encryptted sentence: %s\n", sentence);
	return 0;
}
