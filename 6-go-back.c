#include <stdio.h>
#include <stdbool.h>
int main()
{
int windowSize, sent = 1, ack, i;
printf("Enter your window size\n");
scanf("%d", &windowSize);
while (true)
{
for (i = 0; i <= windowSize; i++)
{
printf("Frame %d has been transmitted.\n", sent);
sent++;
if (sent == windowSize + 1)
break;
}
printf("\nPlease enter the last acknowledgement received.\n");
scanf("%d", &ack);
if (ack == windowSize)
break;
else
sent = ack + 1;
}
return 0;
}
