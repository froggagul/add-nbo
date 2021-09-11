#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
// #include <netinet/in.h>

void dump(void* p, size_t n) {
	uint32_t* u8 = static_cast<uint32_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%x ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0) printf(" ");
		if (i % 16 == 0) printf("\n");
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	// if (argc != 3) {
	// 	printf("usage: ./add-nbo <bin> <bin>");
	// 	return 0;
	// }
	FILE * p;
	uint32_t buffer[6] = {0, 0, 0, 0};

	p = fopen(argv[1], "r");
	if (p == NULL) perror("error opening file");

	fread(buffer, sizeof(uint32_t), 4, p);


	printf("%x\n", buffer[0]);
	// printf("%x\n", ntohl(buffer[0]));

	fclose(p);
	return 0;
}