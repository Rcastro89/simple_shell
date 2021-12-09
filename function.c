#include "main.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: char input
 * Return: length of the input string
 */
int _strlen(char *s)
{
	int i = 1, sum = 0;
	char pl;

	pl = s[0];
	while (pl != '\0')
	{
		sum++;
		pl = s[i++];
	}
	return (sum);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: input one
 * @s2: input two
 * Return: Always 0 (Success)
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != 0 && s2[i] != 0)/* B */
	{
		if (s1[i] != s2[i])/* C */
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: copy to
 * @src: copy from
 * Return: two concat strings
 */
char *_strcat(char *dest, char *src)
{
	int i, n;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (n = 0; (dest[i + n] = *src++) != '\0'; n++)
	{
	}

	return (dest);
}

/**
 * _strdup - duplicate string whit reserve malloc
 * @str: string to duplicate
 * Return: () pointer created
*/
char *_strdup(char *str)
{
	char *ma;
	int i = 0, j;

	if (str == NULL)
	return (NULL);
	while (str[i] != '\0')
	i++;
	ma = malloc(sizeof(char) * i + 1);
	if (ma == 0)
	return (NULL);
	for (j = 0; j < i; j++)
	ma[j] = str[j];
	return (ma);
}
