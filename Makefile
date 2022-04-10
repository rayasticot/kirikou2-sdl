# A simple Makefile for compiling small SDL projects

# set the compiler
CC := clang

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O2 --std=c99 -Wall -lSDL2_image -lSDL2_mixer -lm

# add header files here
HDRS := struct.h map.h vars.h functions.h include.h kirikou.h npc.h spritelist.h bole.h cave.h skull.h boat.h

# add source files here
SRCS := main.c render.c title.c load.c overworld.c dungeon.c dead.c ocean.c boss.c credits.c

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := sad

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean