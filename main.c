#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Deklarace funkce 
char* encrypt(char plaintext[], int key);

int main(void)
{
    // Init
    char plaintext[1000];
    int key;

    // Plaintext
    printf("Plaintext: (Max. 999) ");
    fgets(plaintext, 1000, stdin); // fgets pro moznost limitovat pocet charakteru pri inputu 

    // Klic pro posun
    printf("Key: ");
    scanf("%d", &key);

    // Sifrace
    printf("Ciphertext: ");
    printf("%s", encrypt(plaintext, key));

    return 0;
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