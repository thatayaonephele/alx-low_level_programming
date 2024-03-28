#include "main.h"

int rand(void)
{
	static int x = -1;
	int result = 0;

	x++;
	if ((x == 0) || (x == 1))
		return (8);
	switch (x)
	{
	case 2:
		return (7);
	case 3:
		return (9);
	case 4:
		return (23);
	case 5:
		return (74);
	}
	result = x * x % 30000;
	return (result);
}
