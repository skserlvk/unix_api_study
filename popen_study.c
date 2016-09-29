/*
#include <stdio.h>

FILE * popen(const char *command , const char *type );
int pclose(FILE *stream);

*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char buf[128] = {0};
	FILE *fp;

	if (argc != 2 || argv[1] == NULL) {
		printf("Invalid param\n");
		return -1;
	}
	
	/* type: r, fp can be read. */
	fp = popen(argv[1], "r");
	
	printf("popen call [ %s ] execute result :\n");
	while (fgets(buf, sizeof(buf), fp) != NULL)
		printf(">> %s", buf);
	
	fclose(fp);
	
	return 0;
}
