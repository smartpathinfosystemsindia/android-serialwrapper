#########################################################
#               Description:  serial wrapper for android
#		File       : Makefile	
#		Author     : Ganesh Gudigara
#
#
#
########################################################


JAVA_HOME ?= /usr/lib/jvm/java-6-openjdk-amd64
ARCH      ?= x86_64
CROSS :=
CC    := $(CROSS)gcc
CXX   := $(CROSS)/g++
LD    := $(CROSS)/ld

CFLAGS += -I. -fpic -shared -fPIC -fno-omit-frame-pointer -fno-stack-protector -D_REENTRANT 
CFLAGS += -I$(JAVA_HOME)/include -I$(JAVA_HOME)/$(ARCH)/include
LDFLAGS := -fpic -shared 
LIBS :=   -lpthread
TARGET := libserialportv1.so
SRCS := sp_serial.c
OBJS := $(SRCS:.c=.o)
JAVA_TARGET := libserialport.so
JAVA_SRCS := $(SRCS)
JAVA_SRCS += serialport_jni.c
JAVA_OBJS := $(JAVA_SRCS:.c=.o)


all: $(TARGET) $(JAVA_TARGET) 

$(TARGET):$(OBJS)
	$(CC) $(LDFLAGS) -o $@  $(OBJS) $(LIBS)


$(JAVA_TARGET):$(JAVA_OBJS)
	$(CC) $(LDFLAGS) -o $@  $(JAVA_OBJS) $(LIBS)



%.o:%.c
	$(CC) -o $@ $(CFLAGS) -c $<


clean:
	rm -f *.o *.core core $(TARGET)



buildjava:
	  ./run.sh




