#include "ft_printf.h"

int main (void)
{
	int i = 123445;
	int byte;

	byte = ft_printf("-d", i);
	return (byte);
}
