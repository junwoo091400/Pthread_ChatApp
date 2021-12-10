#include <stdio.h> // printf, fopen 
#include <stdlib.h> // atoi
#include <string.h> // strlen
#include <pthread.h>
#include <sys/socket.h> // 
#include <netinet/in.h> // struct sockaddr_in

// Global Variables
char user_name[32] = {};
int socket_descriptor = 0; // socket file descripter 

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

int main (int argc, char **argv) {
	if (argc < 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(0);
	}
	
	char *server_ip = "127.0.0.1";
	int port = atoi(argv[1]);
	
	splashPage();
	printf("Welcome to 'Chat Thyself'\n");
	
	printf("Please enter your name : ");
	fgets(user_name, sizeof(user_name), stdin); // safer than 'gets()' with buffer limit
	
	trim_string(user_name);
	if (strlen(user_name) < 2) {
		puts("User name should be at least 2 characters long!");
		exit(0);
	}
	
	socket_descriptor = socket(AF_INET, SOCK_STREAM, 0); // Internet Address domain, Bidirectional Bytestream type, 0 for protocol
	
	struct sockaddr_in server_addr; // = {.sin_family = AF_INET, .sin_addr.s_addr = inet_addr(server_ip), .sin_port = htons(port)};
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(server_ip);
	server_addr.sin_port = htons(port);
	
	
	
}
