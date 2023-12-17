
/**
 * opcode - this is a function responsible for running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @number: number of lines
 *
 * Return: nothing
 */

void opcode(stack_t **stack_p, char *str, unsigned int number)
{
        int i = 0;

        instruction_t op[] = INSTRUCTIONS;

        if (!strcmp(str, "stack"))
        {
                global.data_struct = 1;
                return;
        }
        if (!strcmp(str, "queue"))
        {
                global.data_struct = 0;
                return;
        }

        while (op[i].opcode)
        {
                if (strcmp(op[i].opcode, str) == 0)
                {
                        op[i].f(stack_p, number);
                        return; /* if we found a match, run the function */
                }
                i++;
        }
        fprintf(stderr, "L%d: unknown instruction %s\n", number, str);
        exit(EXIT_FAILURE);
}
