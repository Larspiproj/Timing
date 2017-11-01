#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <time.h>

#define BILLION 1e9L

int main(int argc, char** argv) {
	struct timespec btime, etime;

	volatile int i;
	clock_gettime(CLOCK_REALTIME, &btime);
	//for (i = 0; i < 1e7; i++) {
	//};
	usleep(1000000);
	clock_gettime(CLOCK_REALTIME, &etime);
	double nseconds =
			(double) ((etime.tv_sec - btime.tv_sec) * BILLION) +
			(double) (etime.tv_nsec - btime.tv_nsec);
	int n = (int) 10 / nseconds * BILLION + 0.5;
	printf("nseconds: %f\n", nseconds);
	printf("etime.tv_sec: %f s btime.tv_sec: %f s\n", (double)etime.tv_sec, (double)btime.tv_sec);
	printf("etime.tv_nsec: %f ns btime.tv_nsec: %f ns\n", (double)etime.tv_nsec, (double)btime.tv_nsec);
	printf("time = %f (s) \n \r", nseconds / BILLION);
	printf("n = %d \n \r", n);
	return (EXIT_SUCCESS);
}
