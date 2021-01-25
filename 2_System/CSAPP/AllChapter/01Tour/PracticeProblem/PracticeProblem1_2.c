#include <stdio.h>

int main()
{
	double ratio = 4;
	double valid_part = 0.9;

	double old_perfor = 1;
	double new_perfor = 1 / ratio;

	double ratio_valid_part = valid_part / (new_perfor - 0.1);
	printf("we need to improve ratio about %f for the part we can improve\n", ratio_valid_part);

	return 0;
}
