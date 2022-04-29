#include <stdio.h>
#include <stdlib.h>
int main()
{
int p, i = 1, a, w, nac, ack;
a = 15;
w = 5;
printf("Packet size %d\n", a);
while (i <= a)
{
printf("Sending packets from %d to %d\n", i, w + i - 1);
for (p = i; p < w + i; p++)
printf("Transmitting packet %d\n", p);
nac = i + rand() % w;
if (nac == i)
{
printf("Ack = %d\n", w + i);
i = i + w;
continue;
}
printf("NACK = %d\n", nac);
printf("Sending packet %d\n", nac);
printf("ACK = %d\n", nac + 1);
printf("ACK = %d\n", i + w);
i = i + w;
}
return 0;
}