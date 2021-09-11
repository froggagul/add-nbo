#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("usage: add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin c.bin\n");
		return 0;
	}

	FILE * p;
	uint32_t a, b;

	p = fopen(argv[1], "r");
	if (p == NULL) perror("error opening bin 1\n");

	fread(&a, sizeof(uint32_t), 1, p);

	p = fopen(argv[2], "r");
	if (p == NULL) perror("error opening bin 2\n");

	fread(&b, sizeof(uint32_t), 1, p);

    a = ntohl(a);
    b = ntohl(b);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);

	fclose(p);
	return 0;
}