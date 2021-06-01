#include <stdio.h>
#include <string.h>

// Deklarace funkce 
char* encrypt(char plaintext[], int key);
char* decrypt(char ciphertext[], int key);

int main(void)
{
    // Init
    char plaintext[1000], ciphertext[1000];
    int key, choice;

    // Volba pouziti
    printf("Sifrace | Desifrace (0 | 1): ");
    scanf("%d", &choice);

    // Klíč
    printf("Key: ");
    scanf("%d", &key);

    if (choice == 0) {
        // Plaintext
        printf("Plaintext: (Max. 999) ");
        scanf(" %999[^\n]", plaintext);

        // Šifrace
        printf("Ciphertext: ");
        printf("%s", encrypt(plaintext, key)); 
    } 
    
    else if (choice == 1) {
        // Ciphertext
        printf("Ciphertext: (Max. 999) ");
        scanf(" %999[^\n]", ciphertext);

        // Dešifrace
        printf("Plaintext: ");
        printf("%s", decrypt(ciphertext, key)); 
    } 
    
    else {
        printf("Je nutno zadat pro volbu 0 | 1");
        return 1;
    }
}

char* encrypt(char plaintext[], int key) {
    for (int i = 0; i < strlen(plaintext); i++) // Iteruje skrze plaintext
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26; 
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
    }

    return plaintext;
}

char* decrypt(char ciphertext[], int key) {
     for (int i = 0; i < strlen(ciphertext); i++) // Iteruje skrze plaintext
    {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
        {
            ciphertext[i] = 'z' - ('z' - ciphertext[i] + key) % 26;
        }
        else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
        {
            ciphertext[i] = 'Z' - ('Z' - ciphertext[i] + key) % 26;
        }
    }

    return ciphertext;
}