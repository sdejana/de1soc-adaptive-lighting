CC ?= $(CROSS_COMPILE)gcc
CFLAGS = -Wall
LDLIBS = -lm

OBJS = main.o sensor.o led.o
TARGET = adaptive_light

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean