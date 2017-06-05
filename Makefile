
###########################################################################
#
#    CDE Application Builder Makefile
#
# This file was generated by `dtcodegen' from project file `morsetutor.bip'.
# The target platform for this Makefile is SunOS.
#
###########################################################################

###########################################################################
# These are the SunOS-dependent configuration parameters that must be
# set in order for any application to build.
###########################################################################

.KEEP_STATE:

        RM = rm -f
        INCLUDES = -I/usr/include

        STD_DEFINES = 
        ANSI_DEFINES = 

        CDEBUGFLAGS = -g
        COPTFLAGS = -O2
        SYS_LIBRARIES = -lm
        ALLX_LIBPATH = 
        ALLX_LDFLAGS = -L$(ALLX_LIBPATH) -R$(ALLX_LIBPATH)
        LOCAL_LIBRARIES = -lpthread -lXm -lXt -lXext -lX11

        CFLAGS = $(CDEBUGFLAGS) $(INCLUDES) $(STD_DEFINES) $(ANSI_DEFINES)
        CCFLAGS = $(CFLAGS)
        LDLIBS = $(SYS_LIBRARIES)
        LDOPTIONS = $(CDE_LDFLAGS) $(ALLX_LDFLAGS)

###########################################################################
#  These parameters are generated by dtcodegen according to the structure
#  of the project as defined in the .bip and .bil files
###########################################################################

PROGRAM = morsetutor

TARGETS.h = \
	dtb_utils.h \
	main_ui.h \
	settings_ui.h \
	charset_ui.h \
	connect_ui.h

TARGETS.c = \
	dtb_utils.c \
	main_ui.c \
	settings_ui.c \
	charset_ui.c \
	connect_ui.c

TARGETS.h.merged = \
	morsetutor.h

TARGETS.c.merged = \
	morsetutor.c \
	main_stubs.c \
	settings_stubs.c \
	charset_stubs.c \
	connect_stubs.c

SOURCES.h = $(TARGETS.h.merged) $(TARGETS.h)

SOURCES.c = $(TARGETS.c.merged) $(TARGETS.c)

OBJS = \
	morsetutor.o \
	dtb_utils.o \
	main_ui.o \
	main_stubs.o \
	settings_ui.o \
	settings_stubs.o \
	charset_ui.o \
	charset_stubs.o \
	connect_ui.o \
	connect_stubs.o \
	interface.o

.NO_PARALLEL: $(TARGETS.h) $(TARGETS.h.merged) $(TARGETS.c) $(TARGETS.c.merged)

######################################################################
# Standard targets.                                                  #
######################################################################
all:: $(PROGRAM)

$(PROGRAM) : $(SOURCES.c) $(SOURCES.h) $(OBJS)
	$(RM) $@
	$(CC) -o $@ $(OBJS) $(LDOPTIONS) $(LOCAL_LIBRARIES) $(LDLIBS)

morsetutor.o: morsetutor.c $(TARGETS.h) $(TARGETS.h.merged)
morsetutor.c: $(TARGETS.h)


main_stubs.o: main_stubs.c main_ui.h

settings_ui.o: settings_ui.c settings_ui.h
settings_stubs.o: settings_stubs.c settings_ui.h

charset_ui.c + charset_ui.h + charset_stubs.c:
charset_ui.o: charset_ui.c charset_ui.h
charset_stubs.o: charset_stubs.c charset_ui.h

connect_ui.o: connect_ui.c connect_ui.h
connect_stubs.o: connect_stubs.c connect_ui.h

CLEAN_FILES =	core .dtcodegen.log *.BAK *.delta \
		$(PROGRAM) $(OBJS)
clean:
	$(RM)  $(CLEAN_FILES)
