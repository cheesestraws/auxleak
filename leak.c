#define KERNEL

#include <sys/errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/uio.h>
#include <sys/user.h>
#include <sys/file.h>

#include "leak.h"

struct leak_req_t req;

int leak_init() {
	req.cmd = CMD_NONE;
	return 0;
}

int leak_open(dev) dev_t dev; {
  if(minor(dev) != 0) return EINVAL;
  return 0;
}

int leak_close(dev) dev_t dev; {
  return 0;
}

int leak_read(dev, uio) dev_t dev; struct uio* uio; {
	struct leak_resp_t resp;
	struct file* f;
	int ret;
	
	resp.cmd = CMD_NONE;
	resp.valid = 0;
	resp.ret - 0;
	
	switch (req.cmd) {
	case CMD_GET_FD_TYPE:
		resp.cmd = CMD_GET_FD_TYPE;;
		f = getf(req.param);
		if (f != 0) {
			resp.valid = 1;
			resp.ret = (long)(f->f_type);
		}
		break;
	}
	
	ret = uiomove(&resp, sizeof(resp), UIO_READ, uio);
	return ret;
}

int leak_write(dev, uio) dev_t dev; struct uio* uio; {
	int ret;
    ret = uiomove(&req, sizeof(req), UIO_WRITE, uio);
    return ret;
}

int leak_ioctl(dev, cmd, addr, arg)
  dev_t dev; int cmd; caddr_t* addr; int arg;
{
	return EINVAL;
}

int leak_select(dev, rw) dev_t dev; int rw; {
	return 1;
}

