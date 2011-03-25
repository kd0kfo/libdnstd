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
AC_ARG_WITH([zlib],AS_HELP_STRING([--with-zlib<:%=path%:>%],[Include tar/gzip in library]),with_zlib=${withval},with_zlib=true)
[case "$with_zlib" in
      yes) zlib=. ;;
      no) zlib=false ;;
      *) zlib=${with_zlib} ;;
esac]
if test x$zlib != xfalse; then
   AC_MSG_RESULT(Compiling with zlib)
fi
AM_CONDITIONAL([BUILD_WITH_ZLIB],[test x$zlib != xfalse])


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
