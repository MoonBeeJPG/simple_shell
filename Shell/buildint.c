#include "main.h"

/**
* builtin_str - o
*/
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};
/**
* builtin_func - a
*/
int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
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
