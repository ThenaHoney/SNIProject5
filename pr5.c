/*
 * pr5.c
 *
 *  Created on: Nov 4, 2013
 *      Author: Admin
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

char array[4096][20480];

void readRows();

void readColumns();

void writeRows();

void writeColumns();

struct timespec diff(struct timespec start, struct timespec end);

void endTime(struct timespec start);

void startTime();


int main(int argc, char ** argv)
{
	int i, j;
	for(i = 0; i < 4096; i++)
	{
		for(j = 0; j < 4096; j++)
		{
			array[i][j] = 0;
		}
	}

	startTime();

//	for(i = 0; i < 4096; i++)
//	{
//		for(j = 0; j < 4096; j++)
//		{
//			printf("%d ", array[i][j]);
//		}
//		printf("\n");
//	}

	return 0;
}

void readRows()
{
	int i, j;
	for(i = 0; i < 4096; i++)
	{
		for(j = 0; j < 4096; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void readColumns()
{
	int i, j;
	for(j = 0; j < 4096; j++)
	{
		for(i = 0; i < 4096; i++)
		{
			array[i][j];
		}
	}
}

void writeRows()
{
	int i, j;
	for(i = 0; i < 4096; i++)
		{
			for(j = 0; j < 4096; j++)
			{
				array[i][j] = 4;
			}

		}
}

void writeColumns()
{
	int i, j;
	for(j = 0; j < 4096; j++)
	{
		for(i = 0; i < 4096; i++)
		{
			array[i][j] = 5;
		}
	}
}
/*
struct timespec diff(struct timespec start, struct timespec end) - subtracts the end time from the start
time and returns it as a struct timespec that is defined in time.h
*/
struct timespec diff(struct timespec start, struct timespec end)
{
	struct timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}

/*
void runTime(struct timespec start, int MaX, int p_threads) - calculates the run time for the
program by subtracting the end time from the start time.  It then prints out to standard error
the number of iterations, the number of threads, and then the time in seconds and nanoseconds.
*/
void endTime(struct timespec start)
{
  struct timespec end;
  struct timespec runTime;
  if((clock_gettime(CLOCK_REALTIME, &end)) == -1)
  {
	  perror( "clock gettime" );
      exit( EXIT_FAILURE );
  }
  runTime = diff(start, end);
  fprintf(stderr, "\n%lld seconds %lld nanoseconds\n", (long long)runTime.tv_sec, (long long)runTime.tv_nsec);
}

/*
void getVal(int argc,char *argv[]) - takes the commands from the command line and parses it out
to the appropriate variable. Make sure the first command after the run command is the number that you
wish to iterate through (N). Then the number of threads you wish to use.
*/
void startTime()
{
	struct timespec start;
    if((clock_gettime(CLOCK_REALTIME, &start)) == -1)
    {
		perror( "clock gettime" );
		exit( EXIT_FAILURE );
    }

    readRows();
    readColumns();
    writeRows();
    writeColumns();

	endTime(start);
}
