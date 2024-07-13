#ifndef NOT_IMPLEMENTED_H
# define NOT_IMPLEMENTED_H
# include <stdio.h>
# include <stdlib.h>

	__attribute__((noreturn)) void not_implemented(const char *func_name) {
    fprintf(stderr, "%s function not yet implemented\n", func_name);
    abort();
}

#endif
