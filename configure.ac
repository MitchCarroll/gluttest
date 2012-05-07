#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([gluttest], [1.6], [c.mitch.carroll@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lglut':
AC_CHECK_LIB([GL], [glBegin])
AC_CHECK_LIB([GLU], [gluPerspective])
AC_CHECK_LIB([glut], [glutInit])
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
