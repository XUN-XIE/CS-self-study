#include <stdio.h>

int main()
{
	double total_distance = 2500;
	double old_velocity = 100;
	double old_time = 25;

	// Problem A
	double A_velocity = 150;
	double A_time = (total_distance - 1500) / old_velocity + 1500 / A_velocity;
	double A_ratio = old_time / A_time;
	printf("For problem A, the efficiency improved are %.3f\nAnd the time consume now are %.3f\n", A_ratio, A_time);

	// Problem B
	double B_ratio = 1.67;
	double B_time = old_time / B_ratio;
	double B_velocity = (total_distance - 1000) / (B_time - 1000 / old_velocity);
	printf("For problem B, the velocity need to be %.3f\n", B_velocity);

	return 0;
}
