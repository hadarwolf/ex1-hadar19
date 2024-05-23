#include "cipher.h"
#include "tests.h"
#include "tests.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARG_ERR "The program receives 1 or 4 arguments only.\n"
#define TEST_ERR "Usage: cipher test\n"
#define COM_ERR "The given command is invalid.\n"
#define K_ERR "The given shift value is invalid.\n"
#define FILE_ERR "The given file is invalid.\n"
#define FIVE 5
#define TWO 2
#define TEN 10
#define MAX_LINE 1024

// your code goes here
int valid_arg(int argc,char *argv[]){
    if ((argc != FIVE) && (argc != TWO))
    {fprintf(stderr, ARG_ERR);
        return EXIT_FAILURE;}

    if (argc == TWO && strcmp(argv[2],"test") != 0)
    {fprintf(stderr, TEST_ERR);
        return EXIT_FAILURE;}

    if (argc ==FIVE)
    {if (strcmp(argv[1],"cipher") != 0)
        { if(strcmp(argv[1],"decipher") != 0)
            {fprintf(stderr, COM_ERR);
            return EXIT_FAILURE ;}}


        for (int i = 0; argv[2][i] != '\0'; i++) {
        if (!isdigit(argv[2][i]))
        {if argv[2][0] =='-'{break}
            fprintf(stderr, K_ERR);
            return EXIT_FAILURE;
        }

    }}
    return EXIT_SUCCESS;}


int main (int argc, char *argv[]) {
    if (valid_arg(argc,argv) == 1){ return EXIT_FAILURE;}
    if (argc==FIVE) {
        char line[MAX_LINE] = {0};
        FILE *input_file = fopen(argv[3], "r");
        FILE *output_file = fopen(argv[4], "w");
        if (input_file == NULL)
        {fprintf(stderr, FILE_ERR);
            return EXIT_FAILURE;}
        if (output_file == NULL)
        {fclose(input_file);
            fprintf(stderr, FILE_ERR);
            return EXIT_FAILURE;}
        if (strcmp(argv[1], "cipher") == 0) {
            while (fgets(line, MAX_LINE, input_file))
            {cipher(line, strtol(argv[2],NULL,TEN ));
                fputs(line, output_file);}}
        else{
                while (fgets(line, MAX_LINE, input_file))
                {decipher(line, strtol(argv[2],NULL,TEN ));
                    fputs(line, output_file);}
            }fclose(input_file);
            fclose(output_file);
            return EXIT_SUCCESS;
        } else {
            if (test_cipher_non_cyclic_lower_case_positive_k()== 0)
                {return EXIT_FAILURE;}
            if (test_cipher_cyclic_lower_case_special_char_positive_k ()== 0)
                {return EXIT_FAILURE;}
            if (test_cipher_non_cyclic_lower_case_special_char_negative_k \
            ()== 0)
                {return EXIT_FAILURE;}
            if (test_cipher_cyclic_lower_case_negative_k ()== 0)
                {return EXIT_FAILURE;}
            if (test_cipher_cyclic_upper_case_positive_k ()== 0)
                {return EXIT_FAILURE;}
            if (test_decipher_non_cyclic_lower_case_positive_k ()== 0)
                {return EXIT_FAILURE;}
            if (test_decipher_cyclic_lower_case_special_char_positive_k ()== 0)
                {return EXIT_FAILURE;}
            if (test_decipher_non_cyclic_lower_case_special_char_negative_k ()\
                == 0)
                {return EXIT_FAILURE;}
            if (test_decipher_cyclic_lower_case_negative_k ()== 0)
                {return EXIT_FAILURE;}
            if (test_decipher_cyclic_upper_case_positive_k ()== 0)
                {return EXIT_FAILURE;}
        return EXIT_SUCCESS;}
}





