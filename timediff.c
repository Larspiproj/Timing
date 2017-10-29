/* struct timeval {
*	time_t		tv_sec;		 seconds
*	suseconds_t	tv_usec;	 microseconds
* };
*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

double time_diff(struct timeval x, struct timeval y);

//void timersub(struct timeval *start, struct timeval *stop, struct timeval *res);

void fun() {
	printf("fun() starts\n");
	printf("Press enter to stop fun()\n");
	while(1) {
		if (getchar())
			break;
	}
	printf("fun() stopped\n");
}
int main() {
	struct timeval start, stop, res;
	double elapsedTime;
	int time;
	double result;

	gettimeofday(&start, NULL);
	//fun();
	sleep(3);
	gettimeofday(&stop, NULL);

	timersub(&stop, &start, &res);
	result = (res.tv_sec + res.tv_usec/1000000.0);
	printf("Timersub: %f\n", result);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0; // sec to ms
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0; // us to ms
	//printf("%f\n", stop.tv_sec);
	printf("elapsedTime: %f ms\n", elapsedTime);
	printf("Time elapsed: %.0f us\n", time_diff(start, stop));
	
	return 0;
}

double time_diff(struct timeval x, struct timeval y) {
	double x_ms, y_ms, diff;

	x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
	y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;

	diff = (double)y_ms - (double)x_ms;

	return diff;
}
