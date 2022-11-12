#include "leak.h"
#include "stdio.h"
#include <sys/uio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>

int main(argc, argv)
int argc;
char** argv;
{
	struct leak_req_t req;
	struct leak_resp_t resp;
	int lfd;
	int sfd;
	int ret;

	lfd = open("/dev/leak0",  O_RDWR);

	req.cmd = CMD_GET_FD_TYPE;
	req.param = 0;

	ret = write(lfd, &req, sizeof(req));
	printf("write ret => %d\n", ret);
	ret = read(lfd, &resp, sizeof(resp));
	printf("read ret => %d\n", ret);

	printf("\nresult=> [ %ld, %ld, %ld ]\n", resp.cmd, resp.valid, resp.ret);
	sfd = socket(AF_INET, SOCK_STREAM, 6);
	req.param = sfd;
	ret = write(lfd, &req, sizeof(req));
	ret = read(lfd, &resp, sizeof(resp));
	
 	printf("read ret => %d\n", ret);

        printf("\nresult=> [ %ld, %ld, %ld ]\n", resp.cmd, resp.valid, resp.ret);

	close(lfd);
}
