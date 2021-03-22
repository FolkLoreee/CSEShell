#include "shell.h"
#include "syslog.h"

/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args)
{

  printf("shellFind is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call
  int returnValue = execvp("./shellPrograms/find", args);
  printf("RETURN VALUE IS: %d", returnValue);
  if (returnValue == -1)
  {
    printf("[shellFind] Failed to find %s", args[1]);
    return 1;
  }
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue

  return 0;
}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args)
{
  printf("shellDisplayFile is called!\n");
  if (execvp("./shellPrograms/display", args) == -1)
  {
    perror("Execvp fails");
    return 0;
  }
  /** TASK 4 **/
  // 1. Execute the binary program 'display' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue

  return 1;
}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args)
{

  printf("shellListDirAll is called!\n");
  if (execvp("./shellPrograms/listdirall", args) == -1)
  {
    perror("Execvp fails");
    exit(1);
  }
  /** TASK 4 **/
  // 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue

  return 1;
}

/*
	List the items in the directory
*/
int shellListDir(char **args)
{
  printf("shellListDir is called!\n");
  if (execvp("./shellPrograms/listdir", args) == -1)
  {
    perror("Execvp fails");
    exit(1);
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDir

  return 1;
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args)
{
  printf("shellCountLine is called!\n");
  if (execvp("./shellPrograms/countline", args) == -1)
  {
    perror("Execvp fails");
    return 0;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'countline' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue

  return 1;
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args)
{
  printf("shellDaemonize is called!\n");
  if (execvp("./shellPrograms/summond", args) == -1)
  {
    perror("Execvp fails");
    return 0;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'summond' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue

  return 1;
}

/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args)
{
  printf("shellCheckDaemon is called!\n");
  if (execvp("./shellPrograms/checkdaemon", args) == -1)
  {
    perror("Execvp fails");
    return 0;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue

  return 1;
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
  printf("shellCD is called! \n");
  if (args[1] == NULL)
  {
    fprintf(stderr, "CSEShell: expected argument to \"cd\"\n");
  }
  else
  {
    // chdir() changes the current working directory of the calling process
    // to the directory specified in path.
    if (chdir(args[1]) != 0)
    { //use chdir
      perror("CSEShell:");
    }
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
  printf("shellHelp is called! \n");
  int i;
  printf("CSE Shell Interface\n");
  printf("Usage: command arguments\n");
  printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++)
  {
    printf("  %s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args)
{
  return 0;
}

/*
  Builtin function implementations.
*/
int shellUsage(char **args)
{
  int functionIndex = -1;
  if (args[1] == NULL)
  {
    printf("Argument required for usage\n");
    return 1;
  }
  // Check if the commands exist in the command list
  for (int i = 0; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(args[1], builtin_commands[i]) == 0)
    {
      //pass it to the functions
      functionIndex = i;
    }
  }

  switch (functionIndex)
  {
  case 0:
    printf("Type: cd directory_name\n");
    break;
  case 1:
    printf("Type: help\n");
    break;
  case 2:
    printf("Type: exit\n");
    break;
  case 3:
    printf("Type: usage command\n");
    break;
  case 4:
    printf("Type: display filename\n");
    break;
  case 5:
    printf("Type: countline filename\n");
    break;
  case 6:
    printf("Type: listdir\n");
    printf("Type: listdir -a to list all contents in the current dir and its subdirs\n");
    break;
  case 7:
    printf("Type: listdirall\n");
    break;
  case 8:
    printf("Type: find filename_keyword\n");
    break;
  case 9:
    printf("Type: summond \n");
    break;
  case 10:
    printf("Type: checkdaemon \n");
    break;
  default:
    printf("Command %s not found\n", args[0]);
    break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int commandIsInBuiltin(char *command)
{
  for (int i = 0; i < 4; i++)
  {
    if (strcmp(command, builtin_commands[i]) == 0)
    {
      return 0;
    }
  }
  for (int i = 4; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(command, builtin_commands[i]) == 0)

    {
      return 1;
    }
  }
  return -1;
}

int shellExecuteInput(char **args)
{
  /** TASK 3 **/
  pid_t pid;
  pid_t childReturn;

  char filePath[128];

  // 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
  if (args[0] == NULL)
  {
    return 1;
  }

  int check = commandIsInBuiltin(args[0]);

  //check that its an invalid command
  if (check == -1)
  {
    fprintf(stderr, "Invalid command received. Type help to see what commands are implemented\n");
  }
  //check if command is in built_in_commands and is one of the first 4
  if (check == 0)
  {
    // printf("Function called: %s\n", args[0]);
    if (strcmp(args[0], "cd") == 0)
      return shellCD(args);
    if (strcmp(args[0], "help") == 0)
      return shellHelp(args);
    if (strcmp(args[0], "exit") == 0)
      return shellExit(args);
    if (strcmp(args[0], "usage") == 0)
      return shellUsage(args);
  }
  //check if command args[0] is in built_in_commands but is not one of the first 4
  if (check == 1)
  {
    strcat(filePath, realpath("./shellPrograms", NULL));
    strcat(filePath, "/");
    strcat(filePath, args[0]);

    pid = fork();
    // printf("pid is equal to: %d\n", pid);
    // printf("%s", filePath);

    //forking error
    if (pid < 0)
    {
      fprintf(stderr, "Fork has failed. Exiting now");
      return 1;
    }

    //child process
    else if (pid == 0)
    {
      if (strcmp(args[0], "display") == 0)
        return shellDisplayFile(args);
      else if (strcmp(args[0], "countline") == 0)
        return shellCountLine(args);
      else if (strcmp(args[0], "listdir") == 0)
        return shellListDir(args);
      else if (strcmp(args[0], "listdirall") == 0)
        return shellListDirAll(args);
      else if (strcmp(args[0], "find") == 0)
        return shellFind(args);
      else if (strcmp(args[0], "summond") == 0)
        return shellSummond(args);
      else if (strcmp(args[0], "checkdaemon") == 0)
        return shellCheckDaemon(args);
    }
    //parent process
    else
    {
      //wait for child process to terminate
      // printf("Fork works, waiting for child\n");
      wait(NULL);
    }
  }
  // 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
  // 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful.
  // 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
  // 5. For the parent process, wait for the child process to complete and fetch the child's return value.
  // 6. Return the child's return value to the caller of shellExecuteInput
  // 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1
  return 1;
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char *shellReadLine(void)
{
  size_t buffer_size = SHELL_BUFFERSIZE;
  /** TASK 1 **/
  // read one line from stdin using getline()

  // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
  char *buffer = malloc(sizeof(char) * 256); //allocate a memory space for the buffer

  // 2. Check that the char* returned by malloc is not NULL
  if (buffer == NULL)
  { //check if there is space for buffer
    perror("Boooo memory no space");
    exit(1);
  }

  // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
  //basically fetches the input from stdin and put it into the address of the buffer of size fetched from &size
  getline(&buffer, &buffer_size, stdin);
  // 4. Return the char*
  return buffer;
}

/**
 Receives the *line, and return char** that tokenize the line
**/

char **shellTokenizeInput(char *line)
{

  /** TASK 2 **/
  // 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
  char **token_pos = malloc(sizeof(char *) * 8);
  // 2. Check that char ** that is returend by malloc is not NULL
  if (token_pos == NULL)
  {
    perror("Memory space for line_ptr is null");
    exit(1);
  }
  // 3. Tokenize the *line using strtok() function
  char *token = strtok(line, SHELL_INPUT_DELIM); //we use line instead of *line because we need to parse the entire string, not the pointer to the string
  int index = 0;
  token_pos[index] = token;
  index++;

  while (token != NULL)
  {
    token = strtok(NULL, SHELL_INPUT_DELIM); //continuously tokenize from the last string passed to strtok()
    token_pos[index] = token;
    index++;
  }
  //NULL Termination
  token_pos[index] = NULL;
  // 4. Return the char **
  return token_pos;
}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void)
{
  //instantiate local variables
  char *line;  // to accept the line of string from user
  char **args; // to tokenize them as arguments separated by spaces
  int status;  // to tell the shell program whether to terminate shell or not

  /** TASK 5 **/
  //write a loop where you do the following:
  printf("Welcome to 50.005 Customshell!\n");
  while (1)
  {
    // 1. print the message prompt
    printf("CSEShell>");
    // 2. clear the buffer and move the output to the console using fflush
    fflush(stdout);
    // 3. invoke shellReadLine() and store the output at line
    line = shellReadLine();
    // 4. invoke shellTokenizeInput(line) and store the output at args**
    args = shellTokenizeInput(line);
    // 5. execute the tokens using shellExecuteInput(args)
    status = shellExecuteInput(args);
    // 6. free memory location containing the strings of characters
    free(line);
    // 7. free memory location containing char* to the first letter of each word in the input string
    free(args);
    // 8. check if shellExecuteInput returns 1. If yes, loop back to Step 1 and prompt user with new input. Otherwise, exit the shell.
    if (status == 1)
    {
      continue;
    }
    else
    {
      exit(1);
    }
  }
}

int main(int argc, char **args)
{
  shellLoop();
}
