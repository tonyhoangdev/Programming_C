## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## v3.0 - 20170223
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES and ASMSOURCES
CSOURCES:=main.c
CSOURCES+=libC.c

## Define SOURCEDIR_LIB
BASEDIR:=./
SOURCEDIR_LIB:=include/

## Location of objects
OBJECTDIR_NAME:=obj
SOURCEDIR_NAME:=src

## Execute file ##
EXECUTABLE:=app.exe

## Toolchain executables ##
CC:=gcc
AS:=gcc
LD:=gcc
CCSIZE:=size
PROFILE:=gprof

## Toolchain C flags ##
CFLAGS:=-std=c99
CFLAGS+=-Wall
CFLAGS+=-Wextra
CFLAGS+=-Wstrict-prototypes
CFLAGS+=-pedantic
# CFLAGS+=-pg
CFLAGS+=-g
CFLAGS+=-O1

## Assembly flags
ASFLAGS:=

## Linker flags
# LDFLAGS:= -pg

## Internal variables
OBJECTS=$(CSOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.$(ASM_EXT)=%.o)
OBJECTDIR=$(OBJECTDIR_NAME)/
COBJECTS:=$(addprefix $(OBJECTDIR),$(OBJECTS))

SOURCEDIR=$(SOURCEDIR_NAME)/
SOURCEDIR+=$(addprefix $(BASEDIR),$(SOURCEDIR_LIB))

INCLUDES:=$(addprefix -I,$(SOURCEDIR))

SEPARATOR=========================================

## Targets
all: print dir $(EXECUTABLE) size build_complete

# Target used to compile C source files
# $<: dependency (%.c)
# $@: target (%.o)
$(OBJECTDIR)%.o: %.c
	@echo -e '$(SEPARATOR)\nCompiling $@'
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# Target used to compile assembler files
$(OBJECTDIR)%.o: %.S
	@echo -e '$(SEPARATOR)\nCompiling $@'
	@$(AS) $(ASFLAGS) $(INCLUDES) -c $< -o $@
# Target used to link compiled sources
$(EXECUTABLE): $(COBJECTS)
	@echo -e '$(SEPARATOR)\nLinking to $(EXECUTABLE)'
	@$(LD) -o $(EXECUTABLE) $(COBJECTS) $(LDFLAGS)
# Target used to print executables sizes
size: print $(EXECUTABLE)
	@echo '$(SEPARATOR)'
	@echo 'Size of $(EXECUTABLE)'
	@$(CCSIZE) $(EXECUTABLE)
# Target used to print compile informations
print:
	@echo $(SEPARATOR)
	@echo -e '_____Compile C options_____:\n    $(CFLAGS)\n'
	@echo -e '_____Compile ASM options_____:\n    $(ASFLAGS)\n'
	@echo -e '_____Includes_____:\n    $(INCLUDES)\n'
build_complete: size
	@echo $(SEPARATOR)
	@echo 'Build completed!'
#Target used to create folder used to store temporary objects
dir:
	@mkdir -p $(OBJECTDIR)
#Target used to remove files and folders
clean:
	@echo $(SEPARATOR)
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE) gmon.out analysis.txt
prof:
	@echo $(SEPARATOR)
	$(PROFILE) $(EXECUTABLE) gmon.out > analysis.txt

.PHONY: all print dir size clean prof
