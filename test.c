#include<pthread.h>
#include<stdio.h>
#include <netinet/in.h>

int main(){	
	uint16_t test_port_num = 5046;
	printf("USHORT : %u | RAW : %x -> NETWORK NO : %x\n", test_port_num, test_port_num, htons(test_port_num));
	uint16_t test_short = 0;
	uint8_t *test_short_pointer = &test_short;
	test_short_pointer[0] = 0x69;
	test_short_pointer[1] = 0xab;
	printf("Byte 1 : 0x69, Byte 2 : 0xab, USHORT : %u == %x\n", test_short, test_short);
	printf("Hi!");
}
