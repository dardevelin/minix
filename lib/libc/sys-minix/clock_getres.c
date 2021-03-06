#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"

#include <sys/time.h>

#ifdef __weak_alias
__weak_alias(clock_getres, __clock_getres50);
#endif

int clock_getres(clockid_t clock_id, struct timespec *res)
{
  message m;

  m.m2_i1 = (clockid_t) clock_id;

  if (_syscall(PM_PROC_NR, CLOCK_GETRES, &m) < 0)
  	return -1;

  res->tv_sec = (time_t) m.m2_l1;
  res->tv_nsec = (long) m.m2_l2;

  return 0;
}

