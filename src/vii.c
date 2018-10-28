#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_STRING		4096
#define TEXT_EDITOR		"vim"
#define pend_info(buff,fmt,args...)		snprintf(buff+strlen(buff),MAX_STRING-strlen(buff),fmt,##args)
char comment[MAX_STRING];

int main(int argc,const char **argv)
{
	const char *suffix = NULL;
	time_t current_time;
	int fd;
	if(argc > 2){
		fprintf(stdout,"too many argument!");
		exit(1);
	}
	if(argc == 1){
		system(TEXT_EDITOR);
		return 0;
	}

	/*get current time in seconds from 1970/1/1 to now*/
	time(&current_time);

	if(strlen(argv[1]) > 2){
		/*get last two char as suffix */
		suffix = argv[1]+strlen(argv[1]) - 2;
		if(access(argv[1],F_OK)){
			if(!strcmp(".c",suffix) || !strcmp(".h",suffix) || !strcmp(".C",suffix)) {
				/*if is c source file and it's not exist,then create it and add comment in */
				pend_info(comment,"/***********************************************\n");
				pend_info(comment,"*	Filename    :%s\n",argv[1]);
				pend_info(comment,"*	Author      :%s\n",getlogin());
				pend_info(comment,"*	Date	    :%s",asctime(localtime(&current_time)));
				pend_info(comment,"*	Purpose     :\n");
				pend_info(comment,"*	Description :\n");
				pend_info(comment,"*\n");
				pend_info(comment,"***********************************************/\n");
				pend_info(comment,"\n");
			}
			if(!strcmp(".h",suffix)){
				/*if it's header file,add header protector*/
				char header_protector[256];
				const char *src = argv[1];
				char *target = header_protector;
				/*covert filename to MACRO*/
				while(src && *src){
					if(islower(*src))
						*target = *src - 32;
					else if(isupper(*src)||isdigit(*src))
						*target = *src;
					else if(*src == '.')
						*target = '_';
					else
						--target;
					++target;
					++src;
				}
				*target = 0;
				pend_info(comment,"#ifndef\t%s\n#define\t%s\n\n#endif\n",header_protector,header_protector);

			}
			fd = open(argv[1],O_RDWR | O_CREAT,0777);
			if(fd == -1){
				fprintf(stderr,"%s:%s open failed\n",strerror(errno),argv[1]);
				exit(1);
			}
			write(fd,comment,strlen(comment));
			close(fd);			
			
		}
	}
	/*comment is used for command now*/
	snprintf(comment,MAX_STRING,TEXT_EDITOR" %s",argv[1]);
	system(comment);
	return 0;
}
