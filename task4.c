#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define n 8

/*
	In this task, we decoded the encrypted message (message.bin). In this message.bin file, 
	each byte was XORed by a key.To be able to decrypted this file, we used the property of XOR
	operation:
				original message XOR key XOR key = original message
	We generated all possible value of key (256 values becasue key has length of 8 bit), then for each
	possible key, we did the XOR operation between encryted message and this ky, we got the possible 
	original message. The possible original message was stored in folder name (output)
*/

char *file_in="message.bin";  // Initialize the name of message file (input file)
char *folder_out="output";    // Initialize the name of folder that contains the output files.

void xor(char *file_in, char *file_out ,unsigned int key){
	/*
		xor function does the XOR operation between the message(file_in) and the given key (key)
		After that, the result is written to the file named file_out.

		Parameter:   char *file_in: the path of encrypted message
					 char *file_out the path of the  result
					 unsigned int key:  the key
	*/
	FILE *fp1=fopen(file_in, "rb");   // Open and read the encrypted file 
	FILE *fp2=fopen(file_out, "wb");  // Created and open the file that stored the result of XOR operation
	int ch;							  // Temporary  variable to store each byte in file_in
	while((ch=fgetc(fp1))!= EOF){     // Read the message
		putc(ch^ key, fp2);			  //  Do a XOR operation and store to file_out
	}
	fclose(fp1);					  // Close the file_in
	fclose(fp2);					  // Close the file_out
}

unsigned int arrToInteger(int *arr){
	/*
		arrTOInterger function converts the array (contains 8 elements 0 and 1) to the corresponding integer

		Parameter: int *arr: Array contains 8 element of 0 and 1
		Return: Integer value corresponding to array
	*/
	unsigned int converted=0;
	for(int i=0; i< 8; i++) converted |= (unsigned) arr[i] << i;
	return converted;
}

void decrypt(char *file_in){
	/*
		decrypt function does 2 jobs: generate all the possible value of key (256 possibilities) and call function xor to 
		perform XOR operation between the file input and key.

		Parameter: char *file_in: path of the encrypted message
	*/
	int k= n-1;  //Initialize the temporary variable to generate key
	int arr[n]={0, 0, 0, 0, 0, 0, 0, 0};  //Initialize the first key (00000000)
	char s[100]; //Initial the tempory variable to set up the name of file output
	while(k >= 0){ // While loop generates the ly
		unsigned int key= arrToInteger(arr);  // At this step, one key is generated successfully, but in a array form, therefore call arrToInteger function to convert to integer value
		snprintf(s,100,"%s/output%d.bin",folder_out, key); // Set the path of the file output (as the form <folder contains it> + "/output" + key + ".bin")
														   // For example, with the key=10, the path of file output would be : "output/output10.bin"
		xor(file_in,s,key);  //Call the xor function to perform XOR operation and store result file
		// The following code below to generate the key
		k=n-1;
		while(k >= 0 && arr[k]==1) k--;
		if(k >= 0){
			arr[k]=1;
			for (int i=k+1; i<n;i++) arr[i]=0;
		}

    }
}


int main()
{
	mkdir(folder_out, 0777); // Create the folder in the current directory to store output
	decrypt(file_in);        // Perform the decrytion
	printf("Decrypted successfully, all the results are store at folder %s\n", folder_out);
	return 0;
}
