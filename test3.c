#include <stdio.h>
#include <stdlib.h>
 
/* counts words in the file */
int main(void) /* C89 ANSI */
{
    FILE *fp;
    int r,n,i; /* a variable for result of a function, returning int */
     /* the words counter */
    const char *filename = "test2.txt"; /* a file name opening for read */
    char word[10]; /* an array for the check if a non-empty word was read */
     
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "error: file" "\n");
        return 1;
    }  
    /* if can't open the file for read
       then print an error message and return false to the environment */
     
    n = 0; /* turn the counter of words to zero */
    word[0] = '\0'; /* turn the word array to an empty state */
    while ((r = fscanf(fp, "\n%9[^ 0-9\n\t.,!-]%*c", word)) == 1) {

        int arraylen = sizeof(word)/sizeof(word[0]);
        if((r = fscanf(fp, "%[0-9]]%*c", word)) == 0) {
            for(i=0;i<arraylen;i++)
                printf("%c\n",word[i]);
        }

        if (word[0] != '\0')
            n++;
        /* if the word array got something,
           then it was a word, count it */ 
         
        word[0] = '\0'; /* turn the word back into an empty state */

    }  
    /* skipping words delimeted by ' ' or '\n' or ','
       while file fp can be read, continue skipping
       and count every skip */
     
     
    if (ferror(fp) != 0) { /* check the file for read error if EOF occured */
        fprintf(stderr, "error: read file" "\n");
        fclose(fp);
        return 1;
    }
    /* if there was an error while reading the file
       then print error, close the file (because it was opened though)
       and return false to the environment */
     
    if (n == 1) /* control "to be" and endings for word or words */
        printf("there is %d word" "\n", n);
    else
        printf("there are %d words" "\n", n);
     
    fclose(fp); /* close the file */
     
    return 0; /* return success to the environment */
}