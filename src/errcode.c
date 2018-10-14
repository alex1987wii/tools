#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>	/*for exit() */
void usage(const char *str)
{
	printf("usage:%s errcode\n",str);
	exit(0);

}
int check_arg(const char *str)
{
	while(*str){
		if(!isdigit(*str++))
			return 1;
	}
	return 0;
}
int main(int argc,char **argv)
{
	
	if(argc != 2 || check_arg(argv[1]))
		usage(argv[0]);
	printf("%s\n",strerror(atoi(argv[1])));
	return 0;
}
