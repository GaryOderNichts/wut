#include "devoptab_fs.h"

int
__wut_fs_utimes(struct _reent *r,
        const char *filename,
        const struct timeval times[2])
{
   r->_errno = ENOSYS;
   return -1;
}