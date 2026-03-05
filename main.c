#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// input Field Struct
typedef struct {
  char *input_text;
  int input_length;
} input_field;

// Input Field initialization
input_field *init_input_field() {
  input_field *inputField = malloc(sizeof(input_field));
  inputField->input_text = NULL;
  inputField->input_length = 0;

  return inputField;
}

// Function to read Input from User
void read_input(input_field *new_input_field) {
  if (new_input_field->input_text == NULL) { // if the input text is empty
    new_input_field->input_length = 200;     // then length be 200
    new_input_field->input_text = malloc(
        sizeof(new_input_field->input_length)); // allocate memory size in ram
  }

  // store exactly 200 char
  scanf("%200[^\n]", new_input_field->input_text);
  // removing the \n from the scanf
  getchar();
}
// Function to check if the Command is Exit command or not
int isExit(input_field *new_input_field) {
  if (strcmp(".exit", new_input_field->input_text) == 0) {
    free(new_input_field->input_text); // freeing the make input_text
    free(new_input_field);             // freeing the input field
    return 1;
  } else {
    return 0;
  }
}

int main() {
  input_field *new_input_field = init_input_field();
  while (true) {
    printf("db> ");
    read_input(new_input_field);
    if (isExit(new_input_field)) {
      exit(EXIT_SUCCESS);
    } else {
      printf("unrecognized command '%s'.\n", new_input_field->input_text);
    }
  }

  return 0;
}
