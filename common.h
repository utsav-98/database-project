#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define true 1
#define false 0

// input Field Struct
typedef struct {
  char *input;
  size_t buffer_length;
  ssize_t input_length;
} inputBuffer;

inputBuffer *init_inputBuffer(); /* Function to initialize input Field */
void read_input(inputBuffer *new_input_field); /* Function to Read Input*/
int isMetaCommand(
    inputBuffer *new_input_field); /* Function to check if the command is meta
                                      command  or not */
int isExit(inputBuffer *new_input_field); /* Function to check if the entered
                                             command is exit or not*/

void setError(char *errorText);
void AllocateInputBuffer(inputBuffer *new_input_field, size_t n);

#endif // !COMMON_H
