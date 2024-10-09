# HashSlingingSlasher
A simple C program that gives an ascii string in which the hash that starts with a null byte.

```
./slasher (md5, sha1, sha256)
```

In C, if you are using strcmp to compare hashes in order to verify users.

Example:

```C
#include <stdio.h>
#include <string.h>

int main() {
    // Example password hashes (in reality, these would be actual cryptographic hashes)
    char stored_hash[] = "5f4dcc3b5aa765d61d8327deb882cf99";  // Hash of "password"
    char input_hash[33];  // Input buffer for user-provided hash

    printf("Enter your password hash: ");
    scanf("%32s", input_hash);  // Read up to 32 characters to avoid overflow

    // Vulnerable comparison using strcmp
    if (strcmp(stored_hash, input_hash) == 0) {
        printf("Access granted!\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
```
