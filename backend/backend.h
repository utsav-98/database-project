
#ifndef BACKEND_H
#define BACKEND_H
#include "../common.h"
#include "../frontend/frontend.h"

#define true 1
#define false 0

inputBuffer *init_inputBuffer(); /* Function to initialize input Field */

int isMetaCommand(
    inputBuffer *new_input_field); /* Function to check if the command is meta
                                      command  or not */

int isExit(inputBuffer *new_input_field); /* Function to check if the entered
                                             command is exit or not*/

void RunStatement(Statement* statement);

#endif // !BACKEND_H
