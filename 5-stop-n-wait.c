#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

unsigned long begTime;
void start()
{
begTime = clock();
}
unsigned long elapsedTime()
{
return ((unsigned long)clock() - begTime) /
CLOCKS_PER_SEC;
}
bool isTimeout(unsigned long seconds)
{
return seconds >= elapsedTime();
}
int main()
{
int frames[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
14, 15};
unsigned long seconds = 5;
srand(time(NULL));
printf("Sender has to send frames: \n");
for (int i = 0; i < 10; i++)
printf("%d ", frames[i]);
printf("\n");
int count = 0;
bool delay = false;
printf("\nSender\t\t\t\tReceiver\n");
do
{
bool timeout = false;
printf("Sending Frame: %d", frames[count]);
printf("\t\t");
start();
if (rand() % 2)
{
int to = 24600 + rand() % (64000 - 24600) + 1;
for (int i = 0; i < 64000; i++)
for (int j = 0; j < to; j++)
{
}
}
if (elapsedTime() <= seconds)
{
printf("Received Frame: %d ", frames[count]);
if (delay)
{
printf("Duplicate\n");
delay = false;
}
printf("\n");
count++;
}
else
{
printf("---\n");
printf("Timeout\n");
timeout = true;
}
start();
if (rand() % 2 || !timeout)
{
int to = 24600 + rand() % (64000 - 24600) + 1;
for (int i = 0; i < 64000; i++)
for (int j = 0; j < to; j++)
{
}
if (elapsedTime() > seconds)
{
printf("Delayed Ack\n");
count--;
delay = true;
}
else if (!timeout)
printf("Acknowledgement: %d \n", frames[count] - 1);
}
} while (count != 10);
return 0;
}
