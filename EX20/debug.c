#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

static int debug_level = 0;
void set_debug_level(int _debug_level) {
  debug_level = _debug_level;
}

int dprintf(int _debug_level, const char *fmt, ...) {
  if (debug_level >= _debug_level) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "[DBG%d] ", _debug_level);
    vfprintf(stderr, fmt, args);
    va_end(args);
    return 1;
  }
  return 0;
}