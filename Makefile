N64KITDIR   = c:/nintendo/n64kit

TARGET      = helloworld
CODEFILES   = main.c graphic.c textdisplayer.c
OBJECTFILES = assets/include/sprites.o assets/include/stages.o assets/include/objects.o

include $(ROOT)/usr/include/make/PRdefs

DEBUGSYM    = -g
OPTIMIZER   = -O0

NUSYSDIR    = $(N64KITDIR)/nusys
NUSTDINCDIR = $(N64KITDIR)/nustd/include
NUSTDLIBDIR = $(N64KITDIR)/nustd/lib
NUSYSINC    = $(NUSYSDIR)/include
NUSYSLIB    = $(NUSYSDIR)/lib

NUOBJ       = $(NUSYSLIB)/nusys.o 
CODEOBJECTS = $(CODEFILES:.c=.o) $(NUOBJ) $(OBJECTFILES)

CUSTFLAGS   = 
LCINCS      = -I$(NUSYSINC) -I$(NUSTDINCDIR)
LCOPTS      = -G 0 $(DEBUGSYM) $(CUSTFLAGS)
LDFLAGS     = -L$(ROOT)/usr/lib -L$(ROOT)/usr/lib/PR -L$(NUSYSLIB) \
			  -lnusys_d -lgultra_d -L$(GCCDIR)/mipse/lib -lkmc -L$(NUSTDLIBDIR) -lnustd_d

CODESEGMENT = codesegment.o
OBJECTS     = $(CODESEGMENT)

SYMBOL    = $(TARGET).out
ROM       = $(TARGET).n64

default:$(ROM)

include $(ROOT)/usr/include/make/commonrules

$(CODESEGMENT): $(CODEOBJECTS)
		$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)
	
$(ROM) : $(OBJECTS)
		$(MAKEROM) spec -I$(NUSYSINC) -r $(ROM) -e $(SYMBOL)

# add this here i guess?