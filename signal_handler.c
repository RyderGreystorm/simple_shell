#include "main.h"

/**
 * sig_handler - waits for signal
 * @sign: signal.
 */
void sig_handler(int sign)
{
	char *new_prompt = "\nFavShell$ ";

	(void)sign;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 6);
}
