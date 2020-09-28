CC = gcc  # C compiler
CFLAGS = -fPIC  # C flags
LDFLAGS = -shared   # linking flags
RM = rm -f   # rm command
TARGET_LIB = libtarget.so  # target lib

SRCS = add.c sub.c mul.c div.c  # source files
OBJS = $(SRCS:.c=.o)

dytest:dytestapp.c libtarget.so
	$(CC) -o dytest  dytestapp.c -I. libtarget.so


$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c):%.c
	$(CC) $(CFLAGS) -MM $< >$@

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS}  dytest

