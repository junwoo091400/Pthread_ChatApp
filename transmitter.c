/*
Simple Transmiter to send out messages to test client code working
*/

#include <stdio.h> // printf, fopen 
#include <stdlib.h> // atoi
#include <string.h> // strlen
#include <pthread.h>
#include <sys/socket.h> // 
#include <netinet/in.h> // struct sockaddr_in

// Global Variables
#define USER_NAME_LEN 32
#define MESSAGE_LEN 1024
char user_name[USER_NAME_LEN] = {};
int socketfd = 0; // socket file descripter 

// Prints Splash Page
void splashPage () {
	char splashBuffer[100] = {};
	
	FILE *splashscreen = fopen("./splashscreen.txt", "r");
	
	if (splashscreen == NULL) {
		puts("Splashscreen opening error");
		return;
	}
	
	while (fgets(splashBuffer, sizeof(splashBuffer), splashscreen) != NULL) {
		printf("%s", splashBuffer);
	}
	
	fclose(splashscreen);
}

// Trims string to remove white spaces
void trim_string(char *s) {
	char *back = s + strlen(s); // Navigate to NULL
	while(isspace(*--back)); // Find until there's a non-space character
	*(back+1) = 0; // terminate string after the valid character
}

// Handler for sending messages
void *send_msg_handler() {
	char message[MESSAGE_LEN] = {};
	char buffer[MESSAGE_LEN + USER_NAME_LEN + 2] = {};
	int counter = 0;
	while (1) {
		
		if(strcmp(message, "exit") == 0)
			break;
		else {
			int buffer_len = sprintf(buffer, "%s : %d\n", "Hello this is Transmitter message!", ++counter);
			if (buffer_len < 0) {
				continue;
			}
			else {
				send(socketfd, buffer, buffer_len, 0);
			}
		}
		
		sleep(1);
		// Back to loop
	}
	
	exit(0);
}

/*
// Message receive handler
void *recv_msg_handler() {
	char message[MESSAGE_LEN] = {};
	while (1) {
		int receive = recv(socketfd, message, sizeof(mesage), 0);
		if (receive > 0) {
			printf("%s", message); // Print the message
		}
		else if (receive == 0) {
			break;
		}
	}
}*/

int main (int argc, char **argv) {
	// Start
	if (argc < 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(0);
	}
	
	char *server_ip = "127.0.0.1";
	int port = atoi(argv[1]);
	
	// 
	socketfd = socket(AF_INET, SOCK_STREAM, 0); // Internet Address domain, Bidirectional Bytestream type, 0 for protocol
	
	struct sockaddr_in server_addr; // = {.sin_family = AF_INET, .sin_addr.s_addr = inet_addr(server_ip), .sin_port = htons(port)};
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(server_ip);
	server_addr.sin_port = htons(port);
	
	int err = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (err == -1) {
		puts("Connection Error with the server!");
		exit(0);
	}
	
	// Send Name
	send(socketfd, user_name, USER_NAME_LEN, 0);
	printf("Welcome to the Chat! You are connected :)\n");
	
	
	// Set up threads for send / receiving messages
	pthread_t send_msg_thread;
	if (pthread_create(&send_msg_thread, NULL, send_msg_handler, NULL) !=0) {
		puts("Send Message pthread create error");
		exit(0);
	}
	
	close(socketfd); // close socket upon exit
}
