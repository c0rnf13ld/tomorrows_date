#/usr/bin/make

RM = /usr/bin/rm
RMFLAGS = -rf
MKDIR = /usr/bin/mkdir
BUILDDIR = builds
OBJS := $(patsubst %.c,$(BUILDDIR)/%.o,$(wildcard *.c))
DEPS := $(wildcard *.h)
CFLAGS = -Wall

$(BUILDDIR)/main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $?

$(BUILDDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

init:
	$(MKDIR) -p $(BUILDDIR)

clean:
	$(RM) $(RMFLAGS) $(BUILDDIR)/$(OBJS)
