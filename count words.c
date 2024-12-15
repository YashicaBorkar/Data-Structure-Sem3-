#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Increased size for better input handling

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) { // Check for stack overflow
        top++;
        stack[top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (top >= 0) { // Check for stack underflow
        char x = stack[top];
        top--;
        return x;
    }
    return '\0'; // Return null character if stack is empty
}

int isEmpty() {
    return top == -1; // Check if stack is empty
}

void count() {
    int word = 0;
    char y;
    int inWord = 0; // Flag to indicate if we are in a word

    // Pop all characters from the stack and count words
    while (!isEmpty()) {
        y = pop();
        if (y == ' ') {
            if (inWord) {
                word++; // Increment word count if a space is found and we were in a word
                inWord = 0; // Reset flag
            }
        } else {
            inWord = 1; // We are in a word
        }
    }
    
    // If the last character was not a space, count the last word
    if (inWord) {
        word++;
    }

    printf("\nNumber of words are %d\n", word);
}

int main() {
    char str[MAX]; // Array to store the input string
    int i = 0;

    printf("\nEnter a sentence: ");
    // Read input character by character until a newline is encountered
    char ch;
    while (1) {
        scanf("%c", &ch); // Read one character
        if (ch == '\n') { // Stop if newline is encountered
            break;
        }
        str[i] = ch; // Store the character in the str array
        push(ch); // Push the character onto the stack
        i++; // Increment the index for the str array
    }
    
    str[i] = '\0'; // Null-terminate the string

    count(); // Call the function to count words
    return 0;
}
