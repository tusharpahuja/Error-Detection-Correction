#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//str1 is the transferred data
//str2 is the received data

char str1[33],str2[33];
char carry[9],checksum1[9],checksum2[9],checksum[9];
int i,val=0;

//Function for computing the checksum
void compute_checksum(char str[33]){
    for(i=7;i>=0;i--){
        val = 0;
        val = (str[i] - '0') + (str[i + 8] - '0') + (str[i + 16] - '0') + (str[i + 24] - '0') + (carry[i] - '0');
        if(val==1){
            checksum[i] = '1';
            carry[i-1] = '0';
        }
        else if(val==2){
            checksum[i] = '0';
            carry[i-1] = '1';
        }
        else if(val==3){
            checksum[i] = '1';
            carry[i-1] = '1';
        }
        else if(val==4){
            checksum[i] = '1';
            carry[i-1] = '0';
        }
        else if(val==5){
            checksum[i] = '0';
            carry[i-1] = '1';
        }
    }

}


int main(){

carry[7] = '0';

//File pointers
FILE *file_ptr1;
FILE *file_ptr2;

//Opening the first file
file_ptr1 = fopen("file1.txt","r");
//Reading the first file
fgets(str1,33,file_ptr1);

//Opening the second file
file_ptr2 = fopen("file2.txt","r");
//Reading the second file
fgets(str2,33,file_ptr2);

//Computing the checksum for the first file
compute_checksum(str1);
for(i=0;i<8;i++){
    checksum1[i] = checksum[i];
}

//Computing the checksum for the second file
compute_checksum(str2);
for(i=0;i<8;i++){
    checksum2[i] = checksum[i];
}

printf("Transferred Data: %s\n",str1);
printf("Received Data: %s\n",str2);

printf("Checksum for the transferred data: %s\n",checksum1);
printf("Checksum for the received data: %s\n",checksum2);

printf("\n");

//Comparing the checksums
if(strcmp(checksum1,checksum2)==0){
    printf("No error detected ! The Data received is correct !");
}
else{
    printf("Error detected in the received data!");
}

return 0;
}



//01011011001010100001000011110110


//10010101111001101010101010010101
