#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(void)
{
int user2_desc;
struct sockaddr_in user1_addr;
char user1_msg[2000], user2_msg[2000];
int user1_len = sizeof(user1_addr);
// Clean buffers:
memset(user1_msg, '\0', sizeof(user1_msg));
memset(user2_msg, '\0', sizeof(user2_msg));
// Create socket:
user2_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (user2_desc < 0)
{
printf("Error while creating socket.\n");
return -1;
}
printf("Socket created successfully.\n");
// Set port and IP
user1_addr.sin_family = AF_INET;
user1_addr.sin_port = htons(2000);
user1_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
// Get input from the user
printf("User 2: ");
fgets(user2_msg, 2000, stdin);
// Send the message to user 1
if (sendto(user2_desc, user2_msg, strlen(user2_msg), 0,
(struct sockaddr *)&user1_addr, user1_len) < 0)
{
printf("Unable to send message.\n");
return -1;
}
// Receive the user 2's response
if (recvfrom(user2_desc, user1_msg, sizeof(user1_msg), 0,
(struct sockaddr *)&user1_addr, &user1_len) <
0)
{
printf("Error while receiving user 1's message.\n");
return -1;
}
printf("User 1: %s\n", user1_msg);
// Close the socket
close(user2_desc);
return 0;
}