#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/File.o \
	${OBJECTDIR}/src/IPAddress.o \
	${OBJECTDIR}/src/IniFile.o \
	${OBJECTDIR}/src/clock.o \
	${OBJECTDIR}/src/epoll.o \
	${OBJECTDIR}/src/file_watch.o \
	${OBJECTDIR}/src/mailbox.o \
	${OBJECTDIR}/src/mysql_help.o \
	${OBJECTDIR}/src/pipe.o \
	${OBJECTDIR}/src/poller_base.o \
	${OBJECTDIR}/src/signaler.o \
	${OBJECTDIR}/src/thread.o \
	${OBJECTDIR}/src/trie_t.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomponent.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomponent.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomponent.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomponent.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomponent.a

${OBJECTDIR}/src/File.o: src/File.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/File.o src/File.cpp

${OBJECTDIR}/src/IPAddress.o: src/IPAddress.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IPAddress.o src/IPAddress.cpp

${OBJECTDIR}/src/IniFile.o: src/IniFile.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IniFile.o src/IniFile.cpp

${OBJECTDIR}/src/clock.o: src/clock.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/clock.o src/clock.cpp

${OBJECTDIR}/src/epoll.o: src/epoll.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/epoll.o src/epoll.cpp

${OBJECTDIR}/src/file_watch.o: src/file_watch.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/file_watch.o src/file_watch.cpp

${OBJECTDIR}/src/mailbox.o: src/mailbox.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mailbox.o src/mailbox.cpp

${OBJECTDIR}/src/mysql_help.o: src/mysql_help.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mysql_help.o src/mysql_help.cpp

${OBJECTDIR}/src/pipe.o: src/pipe.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/pipe.o src/pipe.cpp

${OBJECTDIR}/src/poller_base.o: src/poller_base.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/poller_base.o src/poller_base.cpp

${OBJECTDIR}/src/signaler.o: src/signaler.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/signaler.o src/signaler.cpp

${OBJECTDIR}/src/thread.o: src/thread.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/thread.o src/thread.cpp

${OBJECTDIR}/src/trie_t.o: src/trie_t.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinclude -Isrc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/trie_t.o src/trie_t.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.c


${OBJECTDIR}/src/File_nomain.o: ${OBJECTDIR}/src/File.o src/File.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/File.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/File_nomain.o src/File.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/File.o ${OBJECTDIR}/src/File_nomain.o;\
	fi

${OBJECTDIR}/src/IPAddress_nomain.o: ${OBJECTDIR}/src/IPAddress.o src/IPAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/IPAddress.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IPAddress_nomain.o src/IPAddress.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/IPAddress.o ${OBJECTDIR}/src/IPAddress_nomain.o;\
	fi

${OBJECTDIR}/src/IniFile_nomain.o: ${OBJECTDIR}/src/IniFile.o src/IniFile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/IniFile.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IniFile_nomain.o src/IniFile.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/IniFile.o ${OBJECTDIR}/src/IniFile_nomain.o;\
	fi

${OBJECTDIR}/src/clock_nomain.o: ${OBJECTDIR}/src/clock.o src/clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/clock.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/clock_nomain.o src/clock.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/clock_nomain.o;\
	fi

${OBJECTDIR}/src/epoll_nomain.o: ${OBJECTDIR}/src/epoll.o src/epoll.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/epoll.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/epoll_nomain.o src/epoll.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/epoll.o ${OBJECTDIR}/src/epoll_nomain.o;\
	fi

${OBJECTDIR}/src/file_watch_nomain.o: ${OBJECTDIR}/src/file_watch.o src/file_watch.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/file_watch.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/file_watch_nomain.o src/file_watch.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/file_watch.o ${OBJECTDIR}/src/file_watch_nomain.o;\
	fi

${OBJECTDIR}/src/mailbox_nomain.o: ${OBJECTDIR}/src/mailbox.o src/mailbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/mailbox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mailbox_nomain.o src/mailbox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/mailbox.o ${OBJECTDIR}/src/mailbox_nomain.o;\
	fi

${OBJECTDIR}/src/mysql_help_nomain.o: ${OBJECTDIR}/src/mysql_help.o src/mysql_help.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/mysql_help.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mysql_help_nomain.o src/mysql_help.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/mysql_help.o ${OBJECTDIR}/src/mysql_help_nomain.o;\
	fi

${OBJECTDIR}/src/pipe_nomain.o: ${OBJECTDIR}/src/pipe.o src/pipe.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/pipe.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/pipe_nomain.o src/pipe.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/pipe.o ${OBJECTDIR}/src/pipe_nomain.o;\
	fi

${OBJECTDIR}/src/poller_base_nomain.o: ${OBJECTDIR}/src/poller_base.o src/poller_base.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/poller_base.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/poller_base_nomain.o src/poller_base.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/poller_base.o ${OBJECTDIR}/src/poller_base_nomain.o;\
	fi

${OBJECTDIR}/src/signaler_nomain.o: ${OBJECTDIR}/src/signaler.o src/signaler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/signaler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/signaler_nomain.o src/signaler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/signaler.o ${OBJECTDIR}/src/signaler_nomain.o;\
	fi

${OBJECTDIR}/src/thread_nomain.o: ${OBJECTDIR}/src/thread.o src/thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/thread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/thread_nomain.o src/thread.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/thread.o ${OBJECTDIR}/src/thread_nomain.o;\
	fi

${OBJECTDIR}/src/trie_t_nomain.o: ${OBJECTDIR}/src/trie_t.o src/trie_t.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/trie_t.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinclude -Isrc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/trie_t_nomain.o src/trie_t.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/trie_t.o ${OBJECTDIR}/src/trie_t_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
