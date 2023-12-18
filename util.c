#include <ctype.h>
#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
/**
 * isnumber - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(char *str)
{
	int e;

	if (!str)
		return (0);

	for (e = 0; str[e]; e++)
		if (e < '0' || e > '9')
			return (0);

	return (1);
}
