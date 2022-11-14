#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Utility functions to access the database

// Function to read the database from the file
char **read_line_by_line(char *filename)
{
    FILE *fp;
    char **lines = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        lines = realloc(lines, sizeof(char *) * (i + 1));
        lines[i] = malloc(len);
        strcpy(lines[i], line);
        i++;
    }

    fclose(fp);
    if (line)
        free(line);
    return lines;
}

// Function to split a string into tokens
char **split_string(char *line)
{
    char **tokens = NULL;
    char *token = NULL;
    int i = 0;

    token = strtok(line, " ");
    while (token != NULL)
    {
        tokens = realloc(tokens, sizeof(char *) * ++i);
        tokens[i - 1] = token;
        token = strtok(NULL, " ");
    }
    tokens = realloc(tokens, sizeof(char *) * (i + 1));
    tokens[i] = 0;
    return tokens;
}

// Function to convert integer string to integer
int convert_string_to_int(char *string)
{
    int i = 0;
    int number = 0;
    while (string[i] != '\0')
    {
        number = number * 10 + (string[i] - '0');
        i++;
    }
    return number;
}

// Function to convert integer to string
char *convert_int_to_string(int number)
{
    char *string = malloc(10);
    sprintf(string, "%d", number);
    return string;
}

// Function to concatenate two strings with a space in between
char *concatenate_strings(char *string1, char *string2)
{
    char *string = malloc(strlen(string1) + strlen(string2) + 2);
    strcpy(string, string1);
    strcat(string, " ");
    strcat(string, string2);
    return string;
}

// Function to write the database to the file
void write_single_line(char *filename, char *line)
{
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    fprintf(fp, "%s \n", line);
    fclose(fp);
}

// Delete all file content
void delete_file_content(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    fclose(fp);
}