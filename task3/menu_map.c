#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *map(char *array, int array_length, char (*f)(char))
{
    char *mapped_array = (char *)(malloc(array_length * sizeof(char))); // init an array
                                                                        /////////////////////////TODO: Complete during task 2.a ///////////////////////////
    if (mapped_array == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    for (int i = 0; i < array_length; i++) // loop the array and apply the function on each elemen
    {
        mapped_array[i] = f(array[i]);
    }
    return mapped_array;
}
char my_get(char c)
/* Ignores c, reads and returns a character from stdin using fgetc. */
{
    return fgetc(stdin);
}
char cxprt(char c)
/* If c is a number between 0x20 and 0x7E, cxprt prints the character of ASCII value c, otherwise, the dot ('.') character.
 This is followed by a space character, and then the value of c in a hexadecimal.
 Finally, a new line character is printed. After printing, cprt returns the value of c unchanged. */
{
    // printf("As Character: %c\n", my_char);     // char - a
    // printf("As Decimal:   %d\n", my_char);     // base 10 - 65
    // printf("As Hex:       %x\n", my_char);     //base 16 - 41
    if (c >= 0x20 && c <= 0x7E)
    {
        printf("%c ", c);
    }
    else
    {
        printf(". ");
    }
    printf("%02x\n", (unsigned char)c);
    return c;
}
char encrypt(char c)
/* Gets a char c and returns its encrypted form by adding 1 to its value.
 If c is 0x7F this wraps around and 0x20 is returned.
  If c is not between 0x20 and 0x7F it is returned unchanged */
{
    if (c == 0x7F) // wrap around
    {
        return 0x20;
    }
    if (c >= 0x20 && c <= 0x7E) // in range
    {
        return c + 1;
    }
    return c; // not in range
}
char decrypt(char c)
/* Gets a char c and returns its decrypted form by reducing 1 from its value.
 If c is 0x20 this wraps around and 0x7F is returned.
  If c is not between 0x20 and 0x7F it is returned unchanged */
{
    if (c == 0x20) // wrap around
    {
        return 0x7F;
    }
    if (c >= 0x21 && c <= 0x7F) // in range
    {
        return c - 1;
    }
    return c; // not in range
}
char dprt(char c)
/* dprt prints the value of c in a decimal representation followed by a new line, and returns c unchanged. */
{
    printf("%d\n", (unsigned char)c);
    return c;
}
int main(int argc, char **argv)
{
    /* TODO: Test your code */
    int base_len = 5;
    char arr1[base_len];
    char *arr2 = map(arr1, base_len, my_get);
    char *arr3 = map(arr2, base_len, dprt);
    char *arr4 = map(arr3, base_len, cxprt);
    free(arr2);
    free(arr3);
    free(arr4);
}
