#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */

char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *dayo_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);

	if (datash->args[1][0] == '-')
	{
		dayo_flag = malloc(3);
		dayo_flag[0] = '-';
		dayo_flag[1] = datash->args[1][1];
		dayo_flag[2] = '\0';
		_strcat(error, dayo_flag);
		free(dayo_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}


/**
 * error_get_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */

char *error_get_cd(data_shell *datash)
{
	int len, len_id;
	char *error, *var_str, *mesg;

	var_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		mesg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		mesg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len = len + _strlen(var_str) + _strlen(mesg) + len_id + 5;
	error = malloc(sizeof(char) * (len + 1));

	if (error == 0)
	{
		free(var_str);
		return (NULL);
	}

	error = strcat_cd(datash, mesg, error, var_str);
	free(var_str);
	return (error);
}


/**
 * error_not_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */

char *error_not_found(data_shell *datash)
{
	int len;
	char *err, *var;

	var = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(var);
	len = len + _strlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(err);
		free(var);
		return (NULL);
	}

	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, var);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(var);
	return (err);
}


/**
 * error_exit_shell - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */

char *error_exit_shell(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
