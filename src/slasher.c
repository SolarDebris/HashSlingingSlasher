#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#define MAX_LEN 5  // Max length of string to brute-force

void print_hash(unsigned char *hash, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to increment the string (for brute-forcing)
int increment_string(char *str, int max_length) {
    int i = 0;
    while (i < max_length) {
        if (str[i] == 126) { // '~' (last printable ASCII character)
            str[i] = 32;     // Reset to ' ' (first printable ASCII character)
            i++;
        } else {
            str[i]++;
            return 1; // Successful increment
        }
    }
    return 0; // Overflow, no more combinations
}

int main(int argc, char *argv[]) {

    unsigned char hash_output[SHA512_DIGEST_LENGTH];  // Max size for SHA-512
    char candidate[MAX_LEN + 1];  // Brute-force candidate string
    memset(candidate, 32, MAX_LEN);  // Start with all spaces (' ')
    candidate[MAX_LEN] = '\0';  // Null-terminate the string
                                //
    if (argc != 2){
        puts("<usage> ./slasher (hashing algoirthm)");
        exit(-1);
    }

    do {
        
        if (strcmp(argv[1], "md5") == 0){
            MD5((unsigned char*)candidate, strlen(candidate), hash_output);
        }
        else if (strcmp(argv[1], "sha1") == 0){
            SHA1((unsigned char*)candidate, strlen(candidate), hash_output);
        }
        else if (strcmp(argv[1], "sha256") == 0){

            SHA256((unsigned char*)candidate, strlen(candidate), hash_output);
        }
        else if (strcmp(argv[1], "sha512") == 0){
            SHA512((unsigned char*)candidate, strlen(candidate), hash_output);
        }
        else {
            puts("Invalid hashing algorithm choose: md5, sha1, sha256");
        }


        if (hash_output[0] == '\0') {
            printf("String \"%s\" produces hash starting with null byte\n", candidate);
            printf("Result: %s\n", candidate);
            print_hash(hash_output, MD5_DIGEST_LENGTH);
            return 0;
        }

    } while (increment_string(candidate, MAX_LEN));

    printf("No matching string found up to length %d.\n", MAX_LEN);
    return 1;
}

