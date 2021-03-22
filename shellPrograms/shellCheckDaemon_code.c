#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   size_t buffer_size = SHELL_BUFFERSIZE;
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v pts > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   int status = system(command);
   if (status == -1)
   {
      return 0;
   }

   free(command);

   int live_daemons = 0;

   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   char *buffer = malloc(sizeof(char) * 256); //allocate a memory space for the buffer
   if (buffer == NULL)
   { //check if there is space for buffer
      perror("Boooo memory no space");
      exit(1);
   }
   /** TASK 6  **/
   // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
   // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
   FILE *outputFp = fopen("/home/folkloreee/Documents/50005/ProgrammingAssignment1/PA1/output.txt", "r");
   // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
   if (outputFp != NULL)
   {
      while (getline(&buffer, &buffer_size, outputFp) != -1)
      {
         live_daemons++;
      }
      fclose(outputFp);
   }
   else
   {
      perror("FILE NOT FOUND");
      return 0;
   }

   // 3. Increase the daemon count whenever we encounter a line
   // 4. Close the file
   // 5. print your result

   if (live_daemons == 0)
      printf("No daemon is alive right now\n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }

   // TODO: close any file pointers and free any statically allocated memory

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}