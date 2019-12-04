#include <stdio.h> 
#include <sys/time.h> 
#include <time.h> 
#include <unistd.h> 
  
// A sample function whose time taken to 
// be measured 

void fun() 
{ 
    for (int i=0; i<1e7; i++) 
    { 
    };
    //printf("fun() called\n");
    //sleep(1);
}
/*
void fun() {
    printf("fun() starts\n");
    printf("Press enter to stop fun()\n");
    while(1) {
        if (getchar())
            break;
    }
    printf("fun() stopped\n");
}
*/

/*
void fun()
{
    struct timespec time;
    time.tv_sec = 1;
    time.tv_nsec = 400000000;
    nanosleep(&time, NULL);
}
*/
  
int main() 
{ 
    /* Time function returns the time since the  
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start_t, end_t; 
  
    /* You can call it like this : start = time(NULL); 
     in both the way start contain total time in seconds  
     since the Epoch. */
    time(&start_t); 
  
    // unsync the I/O of C and C++. 
    //ios_base::sync_with_stdio(false); 
  
    fun();

    // Recording end time.
    time(&end_t);

    // Calculating total time taken by the program.
    double time_taken_t = (end_t - start_t);
    printf("Time taken using time() is : %f\n", time_taken_t);

/* clock_t clock(void) returns the number of clock ticks 
       elapsed since the program was launched.To get the number  
       of seconds used by the CPU, you will need to divide by  
       CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical 
       32 bit system.  */
    clock_t start_c, end_c;

    /* Recording the starting clock tick.*/
    start_c = clock();
    printf("start_c = %ld\n", start_c);

    fun();

    // Recording the end clock tick.
    end_c = clock();
    printf("end_c = %ld\n", end_c);
    double time_taken_c = (end_c - start_c) / CLOCKS_PER_SEC; 
    //double time_taken_c = (end_c - start_c); 
    printf("Time taken using clock() is : %f\n", time_taken_c);


    /* The function gettimeofday() can get the time as
       well as timezone.
       int gettimeofday(struct timeval *tv, struct timezone *tz);
      The tv argument is a struct timeval and gives the
      number of seconds and micro seconds since the Epoch.
      struct timeval {
               time_t      tv_sec;     // seconds
               suseconds_t tv_usec;    // microseconds
           };    */
    struct timeval start_tv, end_tv;

    // start timer.
    gettimeofday(&start_tv, NULL);
    //printf("start_tv = %ld\n", (start_tv.tv_sec + start_tv.tv_usec));
    //printf("start_tv = %ld\n", start_tv.tv_sec);

    // unsync the I/O of C and C++.
    //ios_base::sync_with_stdio(false);

    fun();

    // stop timer.
    gettimeofday(&end_tv, NULL);
    //printf("end_tv = %ld\n", (end_tv.tv_sec + end_tv.tv_usec));
    //printf("end_tv = %ld\n", end_tv.tv_sec);

    // Calculating total time taken by the program. 
    double time_taken_tv; 
  
    time_taken_tv = (end_tv.tv_sec - start_tv.tv_sec) * 1e6; 
    time_taken_tv = (time_taken_tv + (end_tv.tv_usec -  
                              start_tv.tv_usec)) * 1e-6; 
  
    printf("Time taken using struct timeval and gettimeofday(): %f\n", time_taken_tv);

    /* int clock_gettime( clockid_t clock_id, struct
     timespec *tp ); The clock_gettime() function gets
     the current time of the clock specified by clock_id,
     and puts it into the buffer  pointed to by tp.tp
     parameter points to a structure containing
     atleast the following members:
     struct timespec {
               time_t   tv_sec;        // seconds
               long     tv_nsec;       // nanoseconds
           };
    clock id = CLOCK_REALTIME, CLOCK_PROCESS_CPUTIME_ID,
               CLOCK_MONOTONIC ...etc
    CLOCK_REALTIME : clock  that  measures real (i.e., wall-clock) time.
    CLOCK_PROCESS_CPUTIME_ID : High-resolution per-process timer
                               from the CPU.
    CLOCK_MONOTONIC : High resolution timer that is unaffected
                      by system date changes (e.g. NTP daemons).  */
    struct timespec start_spec, end_spec;

    // start timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_spec);
    // clock_gettime(CLOCK_REALTIME, &start_spec);
    clock_gettime(CLOCK_MONOTONIC, &start_spec);

    // unsync the I/O of C and C++.
    //ios_base::sync_with_stdio(false);

    fun(); 
  
    // stop timer. 
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_spec); 
    // clock_gettime(CLOCK_REALTIME, &end_spec); 
    clock_gettime(CLOCK_MONOTONIC, &end_spec); 
  
    // Calculating total time taken by the program. 
    double time_taken_spec; 
    time_taken_spec = (end_spec.tv_sec - start_spec.tv_sec) * 1e9; 
    time_taken_spec = (time_taken_spec + (end_spec.tv_nsec - start_spec.tv_nsec)) * 1e-9; 

    printf("Time taken using struct timespec and clock_gettime(): %f\n", time_taken_spec);

    return 0;
}
