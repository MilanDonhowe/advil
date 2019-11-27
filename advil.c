/* Advil: A Simple brainfuck interpreter in C */
#include <stdio.h>
#include <stdlib.h>

// tape_ptr refers to the operating memory
int tape_ptr = 0;
int tape[30000];


void interpreter(int *code){
    int instruction_ptr = 0;
    while (code[instruction_ptr] != EOF){
        switch (code[instruction_ptr]){
            case '>':
                tape_ptr++;
                if (tape_ptr > 29999) tape_ptr = 0;
                break;
            case '<':
                tape_ptr--;
                if (tape_ptr < 0) tape_ptr = 29999;
                break;
            case '+':
                tape[tape_ptr]++;
                if (tape[tape_ptr] > 255) tape[tape_ptr] = 0;
                break;
            case '-':
                tape[tape_ptr]--;
                if (tape[tape_ptr] < 0) tape[tape_ptr] = 255;
                break;
            case '.':
                putchar(tape[tape_ptr]);
                break;
            case ',':
                tape[tape_ptr] = getchar();
                break;
            case '[':
                if (tape[tape_ptr] == 0){
                    int layer = 1;
                    while(layer != 0){
                        instruction_ptr++;
                        switch (code[instruction_ptr]){
                            case ']':
                                layer--;
                                break;
                            case '[':
                                layer++;
                                break;
                            default:
                                break;
                        }
                    }
                }
                break;
            case ']':
                if (tape[tape_ptr] != 0){
                    int layer = 1;
                    while (layer != 0){
                        instruction_ptr--;
                        switch(code[instruction_ptr]){
                            case '[':
                                layer--;
                                break;
                            case ']':
                                layer++;
                                break;
                            default:
                                break;
                        }
                        
                    }
                }
                break;
            // just ignore non-brainfuck commands
            default:
                break;
        }
        instruction_ptr++;
    }
}

int main(int argc, char *argv[]){
    // tape size set to 30,000 blocks
    if (argc == 2) {

        // move file text to a travesible dynamic array
        FILE *programFile = fopen(argv[1], "r");
        int charCount = 1;
        int *programText = malloc(sizeof(int) * charCount);
        int thisCharacter = fgetc(programFile);
        while (thisCharacter != EOF){
            programText[charCount-1] = thisCharacter;
            charCount++;
            programText = realloc(programText, sizeof(int)*charCount);
            thisCharacter = fgetc(programFile);
        }
        programText[charCount-1] = EOF;
        fclose(programFile);
        // pass code to interpreter
        interpreter(programText);
        // free memory
        free(programText);

    } else if (argc > 2) {
        printf("Error: Too many arguments\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Error: Too few arguments\n");
        exit(EXIT_FAILURE);
    }


    return 0;
}