#include <stdio.h>
/*Description:
 *          show the argruments which shell passed
 */

int main(int argc,char *argv[])
{
    fprintf(stderr,"argc : %d args :");
    int i;
    for(i = 0; i < argc;++i)
    {
        fprintf(stderr," %s",argv[i]);
    }
    fprintf(stderr,"\n");
    return 0;
}
