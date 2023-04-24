char *variables_replacement(char *getline)
{
    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    char *retBuffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    int i = 0, j = 0;
    pid_t pid = getpid();
    int exit_status = 0;
    char *path = getenv("PATH");

    while (getline[i] != '\0')
	{
        if (getline[i] == '$' && getline[i+1] == '?')
		{
            snprintf(buffer, BUFFER_SIZE, "%d", exit_status);
            _strcat(retBuffer, buffer);
            j += _strlen(buffer);
            i += 2;
        }
		else if (getline[i] == '$' && getline[i+1] == '$')
		{
            snprintf(buffer, BUFFER_SIZE, "%d", pid);
            _strcat(retBuffer, buffer);
            j += _strlen(buffer);
            i += 2;
        }
		else if (getline[i] == '$' && getline[i+1] == 'P' && getline[i+2] == 'A' && getline[i+3] == 'T' && getline[i+4] == 'H')
		{
            _strcat(retBuffer, path);
            j += _strlen(path);
            i += 5;
        }
		else {
            retBuffer[j++] = getline[i++];
        }
    }

    retBuffer[j] = '\0';

    free(buffer);

    return retBuffer;
}
