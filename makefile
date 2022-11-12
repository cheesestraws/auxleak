CC=cc
CFLAGS=

all: leak.o 

leak: leak.c
	$(CC) $(CFLAGS) leak.c -c -o leak

clean:
	rm -f leak

install: leak leak_init leak_master
	cp leak /etc/boot.d/leak
	cp leak_init /etc/install.d/init.d/leak
	cp leak_master /etc/master.d/leak
	chmod 755 /etc/install.d/init.d/leak
	chmod 644 /etc/boot.d/leak /etc/master.d/leak
	echo "Do not forget to run newconfig"
