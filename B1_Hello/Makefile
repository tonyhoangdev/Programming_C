## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES
CSOURCES:=main.c

## Define SOURCEDIR
SOURCEDIR:=inc/
SOURCEDIR+=src/
## Location of objects
OBJECTDIR:=obj/

## Toolchain executables ##
CC:=gcc.exe
CCSIZE:=size.exe

## Toolchain flags ##
CFLAGS:= -g -O0
CFLAGS+= -Wall -std=c99 -Wextra -Werror

## Execute file ##
EXECUTABLE=B1_Hello.exe

## Internal variables
OBJECTS=$(CSOURCES:%.c=%.o)
COBJECTS=$(addprefix $(OBJECTDIR),$(OBJECTS))
INCLUDES=$(addprefix -I,$(SOURCEDIR))

## Targets
all: print $(EXECUTABLE) size run

$(EXECUTABLE): dir $(COBJECTS)
	@echo 'Linking to $(EXECUTABLE)'
	@$(CC) -o $(EXECUTABLE) $(COBJECTS) $(CFLAGS)

# $<: dependency (%.c)
# $@: target (%.o)
$(OBJECTDIR)%.o: %.c
	@echo 'Compiling $@'
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

size:
	@$(CCSIZE) $(EXECUTABLE)

print:
	@echo 'Compile options: $(CFLAGS) $(INCLUDES)'

dir:
	mkdir -p $(OBJECTDIR)

clean:
	rm -rf $(OBJECTDIR)

clean_all:
	rm -rf $(OBJECTDIR) $(EXECUTABLE)

run:
	@echo 'Run...'
	@./$(EXECUTABLE)

.PHONY: all print dir size run clean clean_all
