#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <openssl/sha.h>


void print_hash(unsigned char *hash, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}


int main() {
    // Example password hashes (in reality, these would be actual cryptographic hashes)
    unsigned char stored_hash[33];
    unsigned char input_hash[33];  // Input buffer for user-provided hash   
    char user_password[10];
    char *actual_password = "password";

    printf("Enter your password: ");
    fgets(user_password, 10, stdin);

    char *newline = strstr(user_password, "\n");

    *newline = '\0';


    MD5((unsigned char*)actual_password, strlen(actual_password), stored_hash); 
    MD5((unsigned char*)user_password, strlen(user_password), input_hash);    

    printf("Stored hash: ");
    print_hash(stored_hash, strlen(stored_hash));
    
    printf("Actual hash: ");
    print_hash(input_hash, 16);
    print_hash(user_password, strlen(user_password));

    //int result = strcmp(input_hash, stored_hash);
    int result = strcmp(stored_hash, input_hash);

    printf("strcmp result %d\n", result);

    // Vulnerable comparison using strcmp
    if (result == 0) {
        printf("Access granted!\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
