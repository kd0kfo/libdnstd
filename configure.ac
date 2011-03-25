#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.50])
AC_INIT([DNSTD], [2.0], [david@davecoss.com])
AC_CONFIG_SRCDIR([src/])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
# Checks for libraries.

AC_ARG_WITH([fftw3],AS_HELP_STRING([--with-fftw3%<:%=path%:>%],[Include FFTW3 library]),with_fftw3=${withval},with_fftw3=false)
[case "$with_fftw3" in
      yes) fftw3=. ;;
      no) fftw3=false ;;
      *) fftw3=${with_fftw3} ;;
esac]
if test x$fftw3 != xfalse; then
   AC_MSG_RESULT(Compiling with fftw3)
   AC_SUBST(FFTW3_PATH,$fftw3)
fi
AM_CONDITIONAL([BUILD_WITH_FFTW3],[test x$fftw3 != xfalse])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([modf pow sqrt strchr])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
