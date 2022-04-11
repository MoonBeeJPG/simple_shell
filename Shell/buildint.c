#include "main.h"

/**
* builtin_str - o
*/
char *builtin_str[] = {
  "exit"
};
/**
* builtin_func - a
*/
int (*builtin_func[]) (char **) = {
  &lsh_exit
};
/**
* lsh_num_builtins - a
*/
int lsh_num_builtins(void) 
{
  return (sizeof(builtin_str) / sizeof(char *));
}
/**
   @brief Builtin command: exit.
   @param args List of args.  Not examined.
   @return Always returns 0, to terminate execution.
 */
int lsh_exit(char **args)
{
  return (0);
}


/**
* execute - function that matches the tokenized line input with the
* corresponding program or buildint
*
* @args: previous tokenized line
*
* Return: If the tokenized input are not any of the buildint the
* shell go to the system programs and work with pid and ppid
*/
int lsh_execute(char **args)
{
    int i;

    if (args[0] == NULL)
    {
        return (1);
    }

    for (i = 0; i < lsh_num_builtins(); i++)
    {
        if (compare(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }

    return lsh_launch(args);
}
