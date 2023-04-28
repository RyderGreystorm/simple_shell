#include "main.h"

/**
 * sig_handler - waits for signal
 * @sign: signal.
 */

	char *err_name;
	int hist;
	aliases_t *aliases;

void sig_handler(int sign)
{
	char *err_name __attribute__((unused));
	int hist __attribute__((unused));
	aliases_t *aliases __attribute__((unused));
	char *new_prompt = "\nFavShell$ ";

	(void)sign;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 6);
}
