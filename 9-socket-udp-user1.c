#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(void)
{
int user1_desc;
struct sockaddr_in user1_addr, user2_addr;
char user1_msg[2000], user2_msg[2000];
int user2_len = sizeof(user2_addr);
// Clean buffers
memset(user1_msg, '\0', sizeof(user1_msg));
memset(user2_msg, '\0', sizeof(user2_msg));
// Create UDP socket
user1_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (user1_desc < 0)
{
printf("Error while creating socket.\n");
return -1;
}
printf("Socket created successfully.\n");
// Set port and IP
user1_addr.sin_family = AF_INET;
user1_addr.sin_port = htons(2000);
user1_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
// Bind to the set port and IP
if (bind(user1_desc, (struct sockaddr *)&user1_addr,
sizeof(user1_addr)) < 0)
{
printf("Couldn't bind to the port.\n");
return -1;
}
printf("Done with binding.\n");
printf("Listening for incoming messages...\n\n");
// Receive user 2's message:
if (recvfrom(user1_desc, user2_msg, sizeof(user2_msg), 0,
(struct sockaddr *)&user2_addr, &user2_len) <
0)
{
printf("Couldn't receive.\n");
return -1;
}
printf("Received message from IP: %s and port: %i\n",
inet_ntoa(user2_addr.sin_addr),
ntohs(user2_addr.sin_port));
printf("User 2: %s", user2_msg);
// Get input from the user
printf("User 1: ");
fgets(user1_msg, 2000, stdin);
if (sendto(user1_desc, user1_msg, strlen(user1_msg), 0,
(struct sockaddr *)&user2_addr, user2_len) < 0)
{
printf("Can't send.\n");
return -1;
}
// Close the socket
close(user1_desc);
return 0;
}
