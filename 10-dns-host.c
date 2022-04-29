#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
int main()
{
struct sockaddr_in sa;
socklen_t len;
char hbuf[NI_MAXHOST];
memset(&sa, 0, sizeof(struct sockaddr_in));
sa.sin_family = AF_INET;
struct hostent *he;
struct in_addr **addr_list;
int i;
int choice = 0;
char IP[50];
char hostname[100];
while (true)
{
printf("Menu:\n1. Get hostname from IPV4 address.\n2. Get IPV4 address from hostname.\n3. Exit.\n");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter IP address:\n");
scanf("%s", IP);
sa.sin_addr.s_addr = inet_addr(IP);
len = sizeof(struct sockaddr_in);
if (getnameinfo((struct sockaddr *)&sa, len, hbuf,
sizeof(hbuf),
NULL, 0, NI_NAMEREQD))
{
printf("Could not resolve hostname.\n");
}
else
{
printf("Hostname: %s\n\n", hbuf);
}
break;
case 2:
printf("Enter hostname:\n");
scanf("%s", hostname);
he = gethostbyname(hostname);
printf("IP address: %s\n\n", inet_ntoa(*(struct
in_addr *)he->h_addr));
break;
case 3:
printf("Exiting...\n");
return 0;
break;
}
}
return 0;
}
