/*
Copyright (c) 2009, Regents of the University of Alaska

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of the Geographic Information Network of Alaska nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

This code was developed by Dan Stahlke for the Geographic Information Network of Alaska.
*/




#ifndef COMMON_H
#define COMMON_H

#include <ogr_spatialref.h>
#include <cpl_string.h>
#include <gdal.h>

// these constants from GDAL interfere with config.h
#undef PACKAGE_VERSION
#undef PACKAGE_TARNAME
#undef PACKAGE_STRING
#undef PACKAGE_NAME
#undef PACKAGE_BUGREPORT

#include "config.h"

#include <math.h>
#include <stdio.h>

#if HAVE_STDINT_H
#  include <stdint.h>
#endif

#if HAVE_INTTYPES_H
#  include <inttypes.h>
#endif

#if HAVE_STDLIB_H
#  include <stdlib.h>
#endif

#if HAVE_STRING_H
#  include <string.h>
#endif

#if HAVE_STDBOOL_H
#  include <stdbool.h>
#endif

/* see http://www.unixwiz.net/techtips/gnu-c-attributes.html */
#ifndef __GNUC__
#  define  __attribute__(x)  /*NOTHING*/
#endif

#ifndef M_PI
#define M_PI 3.1415926535897932385
#endif

#define D2R (M_PI / 180.0)

#ifdef MIN
#undef MIN
#endif
#define MIN(a,b) ((a)<(b)?(a):(b))

#ifdef MAX
#undef MAX
#endif
#define MAX(a,b) ((a)>(b)?(a):(b))

// if there is no stdbool.h...
#ifndef __bool_true_false_are_defined
enum bool {false, true};
#endif

extern int VERBOSE;

#define MYALLOC(type, cnt) ((type *)_myalloc(sizeof(type) * (cnt)))
#define REMYALLOC(type, buf, cnt) ((type *)_remyalloc(buf, sizeof(type) * (cnt)))

// use the MYALLOC macro which wraps this function
void fatal_error(const char *s, ...) __attribute__((noreturn, format(printf, 1, 2)));
void *_myalloc(size_t size) __attribute__((malloc));
void *_remyalloc(void *p, size_t size) __attribute__((warn_unused_result));
int parse_list_of_doubles(const char *input, int *num_out, double **list_out);
void setup_ndv_list(GDALDatasetH ds, int bandlist_size, int *bandlist, int *num_ndv, double **ndv_list);

#endif // ifndef COMMON_H
