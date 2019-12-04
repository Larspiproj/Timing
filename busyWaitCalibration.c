#include <stdio.h>
#include <stdlib.h>
//#include <bcm2835.h>
#include <time.h>
#include <unistd.h>

#define BILLION 1e9L

//function declaration
//function prototype
int fun(int sec, int nsec);

//function definition
int fun(int sec, int nsec) {
    int result = 0;
    struct timespec time;
    //time.tv_sec = 1;
    time.tv_sec = sec;
    //time.tv_nsec = 4e7;
    time.tv_nsec = nsec;
    //nanosleep(&time, NULL);
    if(result = nanosleep(&time , NULL) == -1)
   {
      //printf("Nanosleep system call failed \n");
      perror("Nanosleep");
      exit(EXIT_FAILURE);
      //return -1;
   }

   return result;

	//for (i = 0; i < 1e7; i++) {
	//};
	//sleep(1);
}

int main(int argc, char** argv) {
	struct timespec btime, etime;
	volatile int i;
    int sec;
    int nsec;
    printf("Enter seconds: ");
    scanf("%d", &sec);
    printf("Enter nanoseconds: ");
    scanf("%d", &nsec);
    //printf("Arg1 = %s Arg2 = %s\n", argv[1], argv[2]);
    //int result = fun(1, 4e7);
    //sec = atol(argv[1]);
    //nsec = atol(argv[2]);
	clock_gettime(CLOCK_REALTIME, &btime);
    int result = fun(sec, nsec);
    //fun();
	clock_gettime(CLOCK_REALTIME, &etime);
	double nseconds =
			(double) ((etime.tv_sec - btime.tv_sec) * BILLION) +
			(double) (etime.tv_nsec - btime.tv_nsec);
	int n = (int) 10 / nseconds * BILLION + 0.5;
	int n2 = (int) 10 / nseconds * BILLION;
	printf("nseconds: %f\n", nseconds);
	printf("etime.tv_sec: %f s btime.tv_sec: %f s\n", (double)etime.tv_sec, (double)btime.tv_sec);
	printf("etime.tv_nsec: %f ns btime.tv_nsec: %f ns\n", (double)etime.tv_nsec, (double)btime.tv_nsec);
	printf("time = %Lf (s) \n \r", nseconds / BILLION);
	printf("n = %d \n \r", n);
	printf("n2 = %d \n \r", n2);
	return (EXIT_SUCCESS);
}
