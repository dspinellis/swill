/* ----------------------------------------------------------------------------- 
 * log.c
 *
 *     Log files
 * 
 * Author(s) : David Beazley (beazley@cs.uchicago.edu)
 *             Sotiria Lampoudi (slampoud@cs.uchicago.edu)
 *
 * Copyright (C) 1999-2002.  The University of Chicago
 * See the file LICENSE for information on usage and redistribution.	
 * ----------------------------------------------------------------------------- */

static char cvsroot[]="$Header: /cvs/projects/SWILL/Source/SWILL/log.c,v 1.2 2002/03/19 19:51:34 beazley Exp $";

#include "swillint.h"
#include <stdarg.h>

static FILE *SwillLog = 0;

void swill_log(FILE *f) { 
  SwillLog = f;
}

int swill_logprintf(const char *fmt, ...) {
  int ret;
  va_list ap;
  if (!SwillLog) return 0;
  va_start(ap,fmt);
  ret = vPrintf(SwillLog,fmt,ap);
  fflush(SwillLog);
  va_end(ap);
  return ret;
}
