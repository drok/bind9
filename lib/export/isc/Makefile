# Copyright (C) 2009, 2010, 2012-2014  Internet Systems Consortium, Inc. ("ISC")
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# $Id: Makefile.in,v 1.8 2010/06/09 23:50:58 tbox Exp $

top_srcdir =	../../..
srcdir =	../../../lib/isc
export_srcdir =	../../../lib/export

VERSION=9.9.5-P1

# LIBINTERFACE ranges
# 9.6: 50-59, 110-119
# 9.7: 60-79
# 9.8: 80-89, 120-129
# 9.9: 90-109
# 9.9-sub: 130-139
LIBINTERFACE = 100
LIBREVISION = 0
LIBAGE = 5

CINCLUDES =	-I${srcdir}/unix/include \
		-I${srcdir}/pthreads/include \
		-I${srcdir}/x86_32/include \
		-I${export_srcdir}/isc/include -I${srcdir}/include \
		
CDEFINES =	-DOPENSSL -DUSE_APPIMPREGISTER -DUSE_MEMIMPREGISTER \
		-DUSE_SOCKETIMPREGISTER -DUSE_TASKIMPREGISTER \
		-DUSE_TIMERIMPREGISTER
CWARNINGS =

# Alphabetically
# {file,dir}.c is necessary for isclog
# symtab.c is necessary for isccfg
APIOBJS =	app_api.lo mem_api.lo socket_api.lo \
		task_api.lo timer_api.lo

ISCDRIVEROBJS =	mem.lo unix/socket.lo task.lo timer.lo lib.lo \
		heap.lo	#timer module depends on this

UNIXOBJS =	 \
		unix/app.lo \
		unix/dir.lo \
		unix/errno2result.lo \
		unix/file.lo \
		unix/fsaccess.lo \
		unix/stdio.lo \
		unix/stdtime.lo unix/strerror.lo unix/time.lo

NLSOBJS =	nls/msgcat.lo

THREADOPTOBJS = pthreads/condition.lo pthreads/mutex.lo

THREADOBJS =	${THREADOPTOBJS} pthreads/thread.lo

WIN32OBJS = 	win32/condition.lo win32/dir.lo win32/file.lo \
		win32/fsaccess.lo win32/once.lo win32/stdtime.lo \
		win32/thread.lo win32/time.lo

# Alphabetically
OBJS =		  \
		assertions.lo backtrace.lo backtrace-emptytbl.lo base32.lo \
		base64.lo buffer.lo bufferlist.lo \
		error.lo event.lo \
		hash.lo hex.lo hmacmd5.lo hmacsha.lo \
		inet_aton.lo iterated_hash.lo lex.lo lfsr.lo log.lo \
		md5.lo mutexblock.lo netaddr.lo netscope.lo \
		ondestroy.lo parseint.lo portset.lo radix.lo \
		random.lo refcount.lo region.lo regex.lo result.lo \
		rwlock.lo safe.lo serial.lo sha1.lo sha2.lo \
		sockaddr.lo stats.lo string.lo \
		symtab.lo \
		tm.lo \
		version.lo \
		${APIOBJS} ${ISCDRIVEROBJS} \
		${UNIXOBJS} ${NLSOBJS} ${THREADOBJS}

# Alphabetically
APISRCS =	app_api.c mem_api.c socket_api.c \
		task_api.c timer_api.c

ISCDRIVERSRCS =	mem.c task.c lib.c timer.c heap.c

SRCS =		  \
		assertions.c backtrace.c backtrace-emptytbl.c base32.c \
		base64.c buffer.c bufferlist.c \
		error.c event.c \
		hash.c hex.c hmacmd5.c hmacsha.c \
		inet_aton.c iterated_hash.c lex.c log.c lfsr.c \
		md5.c mutexblock.c \
		netaddr.c netscope.c \
		ondestroy.c \
		parseint.c portset.c radix.c \
		random.c refcount.c region.c regex.c result.c rwlock.c \
		safe.c serial.c sha1.c sha2.c sockaddr.c \
		stats.c string.c symtab.c \
		tm.c \
		version.c \
		${APISRCS} ${ISCDRIVERSRCS}

LIBS =		-ldl -lcap -lpthread  -lxml2 -lz -lm

# Note: the order of SUBDIRS is important.
# Attempt to disable parallel processing.
.NOTPARALLEL:
.NO_PARALLEL:
SUBDIRS =	include unix nls pthreads
TARGETS =	timestamp

# Copyright (C) 2004-2009, 2011, 2012  Internet Systems Consortium, Inc. ("ISC")
# Copyright (C) 1998-2003  Internet Software Consortium.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# $Id$

###
### Common Makefile rules for BIND 9.
###

###
### Paths
###
### Note: paths that vary by Makefile MUST NOT be listed
### here, or they won't get expanded correctly.

prefix =	/usr
exec_prefix =	/usr
bindir =	/usr/bin
sbindir =	/usr/sbin
includedir =	/usr/include/bind9
libdir =	/usr/lib
sysconfdir =	/etc
localstatedir =	/var
mandir =	/usr/share/man
datarootdir =   ${prefix}/share
export_libdir =	/usr/lib
export_includedir = /usr/include

DESTDIR =



top_builddir =	/home/radu/proj/bind9

###
### All
###
### Makefile may define:
###	TARGETS

all: subdirs ${TARGETS} testdirs

###
### Subdirectories
###
### Makefile may define:
###	SUBDIRS

ALL_SUBDIRS = ${SUBDIRS} nulldir
ALL_TESTDIRS = ${TESTDIRS} nulldir

#
# We use a single-colon rule so that additional dependencies of
# subdirectories can be specified after the inclusion of this file.
# The "depend" and "testdirs" targets are treated the same way.
#
subdirs:
	@for i in ${ALL_SUBDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making all in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" all) || exit 1; \
		fi; \
	done

#
# Tests are built after the targets instead of before
#
testdirs:
	@for i in ${ALL_TESTDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making all in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" all) || exit 1; \
		fi; \
	done

install:: all

install clean distclean maintainer-clean doc docclean man manclean::
	@for i in ${ALL_SUBDIRS} ${ALL_TESTDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making $@ in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" $@) || exit 1; \
		fi; \
	done

###
### C Programs
###
### Makefile must define
###	CC
### Makefile may define
###	CFLAGS
###	LDFLAGS
###	CINCLUDES
###	CDEFINES
###	CWARNINGS
### User may define externally
###     EXT_CFLAGS

CC = 		/usr/bin/gcc
CFLAGS =	-g3 -gdwarf-2 -I/usr/include/libxml2
LDFLAGS =	
STD_CINCLUDES =	 -I/home/radu/proj/bind9/unit/atf/include
STD_CDEFINES =	 -DISC_LIST_CHECKINIT=1 -D_GNU_SOURCE
STD_CWARNINGS =	 -W -Wall -Wmissing-prototypes -Wcast-qual -Wwrite-strings -Wformat -Wpointer-arith -fno-strict-aliasing -fno-delete-null-pointer-checks

BUILD_CC = /usr/bin/gcc
BUILD_CFLAGS = -g3 -gdwarf-2 -I/usr/include/libxml2
BUILD_CPPFLAGS =  -D_GNU_SOURCE 
BUILD_LDFLAGS = 
BUILD_LIBS = -ldl -lcap -lpthread  -lxml2 -lz -lm

.SUFFIXES:
.SUFFIXES: .c .lo

ALWAYS_INCLUDES = -I${top_builddir}
ALWAYS_DEFINES = -D_REENTRANT
ALWAYS_WARNINGS =

ALL_CPPFLAGS = \
	${ALWAYS_INCLUDES} ${CINCLUDES} ${STD_CINCLUDES} \
	${ALWAYS_DEFINES} ${CDEFINES} ${STD_CDEFINES}

ALL_CFLAGS = ${EXT_CFLAGS} ${ALL_CPPFLAGS} ${CFLAGS} \
	${ALWAYS_WARNINGS} ${STD_CWARNINGS} ${CWARNINGS}

%.lo:  ${srcdir}/%.c
	${LIBTOOL_MODE_COMPILE} ${CC} ${ALL_CFLAGS} -c $<

SHELL = /bin/sh
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIBTOOL_MODE_COMPILE = ${LIBTOOL} --mode=compile --tag=CC
LIBTOOL_MODE_INSTALL = ${LIBTOOL} --mode=install --tag=CC
LIBTOOL_MODE_LINK = ${LIBTOOL} --mode=link --tag=CC
PURIFY = 

MKDEP = ${SHELL} ${top_builddir}/make/mkdep

###
### This is a template compound command to build an executable binary with
### an internal symbol table.
### This process is tricky.  We first link all objects including a tentative
### empty symbol table, then get a tentative list of symbols from the resulting
### binary ($@tmp0).  Next, we re-link all objects, but this time with the
### symbol table just created ($tmp@1).  The set of symbols should be the same,
### but the corresponding addresses would be changed due to the difference on
### the size of symbol tables.  So we create the symbol table and re-create the
### objects once again.  Finally, we check the symbol table embedded in the
### final binaryis consistent with the binary itself; otherwise the process is
### terminated.
###
### To minimize the overhead of creating symbol tables, the autoconf switch
### --enable-symtable takes an argument so that the symbol table can be created
### on a per application basis: unless the argument is set to "all", the symbol
### table is created only when a shell (environment) variable "MAKE_SYMTABLE" is
### set to a non-null value in the rule to build the executable binary.
###
### Each Makefile.in that uses this macro is expected to define "LIBS" and
### "NOSYMLIBS"; the former includes libisc with an empty symbol table, and
### the latter includes libisc without the definition of a symbol table.
### The rule to make the executable binary will look like this
### binary: ${OBJS}
###     #export MAKE_SYMTABLE="yes"; \  <- enable if symtable is always needed
###	export BASEOBJS="${OBJS}"; \
###	${FINALBUILDCMD}
###
### Normally, ${LIBS} includes all necessary libraries to build the binary;
### there are some exceptions however, where the rule lists some of the
### necessary libraries explicitly in addition to (or instead of) ${LIBS},
### like this:
### binary: ${OBJS}
###     cc -o $@ ${OBJS} ${OTHERLIB1} ${OTHERLIB2} ${lIBS}
### in order to modify such a rule to use this compound command, a separate
### variable "LIBS0" should be deinfed for the explicitly listed libraries,
### while making sure ${LIBS} still includes libisc.  So the above rule would
### be modified as follows:
### binary: ${OBJS}
###	export BASEOBJS="${OBJS}"; \
###	export LIBS0="${OTHERLIB1} ${OTHERLIB2}"; \
###     ${FINALBUILDCMD}
### See bin/check/Makefile.in for a complete example of the use of LIBS0.
###
FINALBUILDCMD = if [ X"${MKSYMTBL_PROGRAM}" = X -o X"$${MAKE_SYMTABLE:-${ALWAYS_MAKE_SYMTABLE}}" = X ] ; then \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@ $${BASEOBJS} $${LIBS0} ${LIBS}; \
	else \
		rm -f $@tmp0; \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@tmp0 $${BASEOBJS} $${LIBS0} ${LIBS} || exit 1; \
		rm -f $@-symtbl.c $@-symtbl.lo; \
		${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
		-o $@-symtbl.c $@tmp0 || exit 1; \
		$(MAKE) $@-symtbl.lo || exit 1; \
		rm -f $@tmp1; \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@tmp1 $${BASEOBJS} $@-symtbl.lo $${LIBS0} ${NOSYMLIBS} || exit 1; \
		rm -f $@-symtbl.c $@-symtbl.lo; \
		${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
		-o $@-symtbl.c $@tmp1 || exit 1; \
		$(MAKE) $@-symtbl.lo || exit 1; \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@tmp2 $${BASEOBJS} $@-symtbl.lo $${LIBS0} ${NOSYMLIBS}; \
		${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
		-o $@-symtbl2.c $@tmp2; \
		count=0; \
		until diff $@-symtbl.c $@-symtbl2.c > /dev/null ; \
		do \
			count=`expr $$count + 1` ; \
			test $$count = 42 && exit 1 ; \
			rm -f $@-symtbl.c $@-symtbl.lo; \
			${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
			-o $@-symtbl.c $@tmp2 || exit 1; \
			$(MAKE) $@-symtbl.lo || exit 1; \
			${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} \
			${LDFLAGS} -o $@tmp2 $${BASEOBJS} $@-symtbl.lo \
			$${LIBS0} ${NOSYMLIBS}; \
			${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
			-o $@-symtbl2.c $@tmp2; \
		done ; \
		mv $@tmp2 $@; \
		rm -f $@tmp0 $@tmp1 $@tmp2 $@-symtbl2.c; \
	fi

cleandir: distclean
superclean: maintainer-clean

clean distclean maintainer-clean::
	rm -f *.lo *.o *.lo *.la core *.core *-symtbl.c *tmp0 *tmp1 *tmp2
	rm -rf .depend .libs

distclean maintainer-clean::
	rm -f Makefile

depend:
	@for i in ${ALL_SUBDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making depend in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" $@) || exit 1; \
		fi; \
	done
	@if [ X"${srcdir}" != X. ] ; then \
		if [ X"${SRCS}" != X -a X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			echo ${MKDEP} -vpath ${srcdir} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -vpath ${srcdir} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${SRCS}" != X ] ; then \
			echo ${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -vpath ${srcdir} -p ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		fi \
	else \
		if [ X"${SRCS}" != X -a X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			echo ${MKDEP} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${SRCS}" != X ] ; then \
			echo ${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -p ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		fi \
	fi

FORCE:

###
### Libraries
###

AR =		/usr/bin/ar
ARFLAGS =	cruv
RANLIB =	ranlib

###
### Installation
###

INSTALL =		/usr/bin/install -c
INSTALL_PROGRAM =	${INSTALL}
LINK_PROGRAM =		ln -s
INSTALL_SCRIPT =	${INSTALL}
INSTALL_DATA =		${INSTALL} -m 644

###
### Programs used when generating documentation.  It's ok for these
### not to exist when not generating documentation.
###

XSLTPROC =		/usr/bin/xsltproc --novalid --xinclude --nonet
PERL =			/usr/bin/perl
LATEX =			/usr/bin/latex
PDFLATEX =		/usr/bin/pdflatex
W3M =			w3m

###
### Script language program used to create internal symbol tables
###
MKSYMTBL_PROGRAM =	

###
### Switch to create internal symbol table selectively
###
ALWAYS_MAKE_SYMTABLE =	

###
### DocBook -> HTML
### DocBook -> man page
###

.SUFFIXES: .docbook .html .1 .2 .3 .4 .5 .6 .7 .8

.docbook.html:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-docbook-html.xsl $<

.docbook.1:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.2:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.3:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.4:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.5:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.6:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.7:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.8:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

###
### Python executable
###
.SUFFIXES: .py
.py:
	cp -f $< $@
	chmod +x $@


version.lo: ${srcdir}/version.c
	${LIBTOOL_MODE_COMPILE} ${CC} ${ALL_CFLAGS} \
		-DVERSION=\"${VERSION}\" \
		-DLIBINTERFACE=${LIBINTERFACE} \
		-DLIBREVISION=${LIBREVISION} \
		-DLIBAGE=${LIBAGE} \
		-c ${srcdir}/version.c

libisc-export.a: ${OBJS}
	${AR} ${ARFLAGS} $@ ${OBJS}
	${RANLIB} $@

libisc-export.la: ${OBJS}
	${LIBTOOL_MODE_LINK} \
		${CC} ${ALL_CFLAGS} ${LDFLAGS} -o libisc-export.la \
		-rpath ${export_libdir} \
		-version-info ${LIBINTERFACE}:${LIBREVISION}:${LIBAGE} \
		${OBJS} ${LIBS}

timestamp: libisc-export.la
	touch timestamp

installdirs:
	$(SHELL) ${top_srcdir}/mkinstalldirs ${DESTDIR}${export_libdir}

install:: timestamp installdirs
	${LIBTOOL_MODE_INSTALL} ${INSTALL_PROGRAM} libisc-export.la \
	${DESTDIR}${export_libdir}

clean distclean::
	rm -f libisc-export.la libisc-export.la timestamp
