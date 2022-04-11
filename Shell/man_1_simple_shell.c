NAME
	sh - shell, he standard command language interpreter.
DESCRIPTION
	The sh utility is a command language interpreter that shall execute commands read form a command line string, the standard input, or a specified file.

Pathname expansion shall not fail due to the size of a file.

Shell input and output redirections have an implementation defined offset maximun that is established in the open file description.

OPERANDS

		-		A single <hypen-minus> shall be treated as the first operand and then ignored. If both '-' are given as arguments, or it other operands pecede the single <hypen-minus>, the results are undefined.

		argument
			The positional parameters ($1, $2, and so on) shall be set to arguments, if any.
		
		command_file

STDIN
	The standar input shall be used only if the following is true:

