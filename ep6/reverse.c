#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isAccentedLetter(unsigned char letter) {    
    return letter > 0x7f;
}

unsigned char *reverse(unsigned char *text) {
    unsigned char *reversedText;

    int size= strlen(text);

    reversedText = malloc(size + 1);
    
    for(int i = 0; i < (int)(size); i++) {
        if(isAccentedLetter(text[i])) {            
            reversedText[size-i-2] = text[i];
            reversedText[size-i-1] = text[i + 1];
            i++;
        } else {
            reversedText[size-i-1] = text[i];
        }
    }

    reversedText[size] = '\0';

    return reversedText;
}
