#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <linux/fs.h>
#include <linux/serial.h>
#include <linux/tty.h>
#include <linux/ioctl.h>

#include "sp_serial.h"

int sp_scan_device(char *name)
{
	int fd, stat = -1;
	fd = open(name, O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd < 0)
	{
		perror("scan");
		return stat;
	}
	else
	{
#ifdef GG
		if(ioctl(fd, TIOCGSERIAL, &sp_serialinfo) < 0)
		{
			perror("Can't get serial port info");
			close(fd);
			return stat;
		}
		else
		{
			stat = 0 //success
			close(fd);
			return stat;
		}
#endif
	}
}


void *sp_serial_open(char *name)
{
	int fd;
	struct port_s *obj;
	fd = open(name, O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd < 0)
	{
		perror("open");
	}
	printf("Port is open");
	obj = (struct port_s *)::malloc(sizeof(struct port_s));
	memset((void *)obj, 0, sizeof(struct port_s));
	obj->fd = fd;
	strcpy(obj->port_name, name);
	return (void *)obj;
}




int sp_configure_device(void * obj, int Baudrate, int databits, int stopbit, int parity, int flow, int timeout)
{
	struct port_s *port = (struct port_s *)obj;
	int fd = port->fd;
	struct termios options;
	speed_t speed;
	switch (Baudrate)
	{
		case 150:
			speed = B150;
			break;
		case 200:
			speed = B200;
			break;
		case 300:
			speed = B300;
			break;
		case 600:
			speed = B600;
			break;
		case 1200:
			speed = B1200;
			break;
		case 1800:
			speed = B1800;
			break;
		case 2400:
			speed = B2400;
			break;
		case 4800:
			speed = B4800;
			break;
		case 9600:
			speed = B9600;
			break;
		case 19200:
			speed = B19200;
			break;
		case 38400:
			speed = B38400;
			break;
		case 57600:
			speed = B57600;
			break;
		case 115200:
			speed = B115200;
			break;
		case 230400:
			speed = B230400;
			break;	
		default:
			speed = B115200;
	}
	tcgetattr(fd, &options);
	cfsetispeed(&options, speed);
	cfsetospeed(&options, speed);
	options.c_cflag |= (CLOCAL | CREAD);
	if(5 == databits)
	{
		options.c_cflag &= ~CSIZE;
		options.c_cflag |= CS5;
	}	
	else if(6 == databits)
	{
		options.c_cflag &= ~CSIZE;
		options.c_cflag |= CS6;
	}	
	else if(7 == databits)
	{
		options.c_cflag &= ~CSIZE;
		options.c_cflag |= CS7;
	}	
	else //(8 == databits)
	{
		options.c_cflag &= ~CSIZE;
		options.c_cflag |= CS8;
	}
	if(1 == stopbit)
		options.c_cflag &= ~CSTOPB;
	else // (2 == stopbits)
		options.c_cflag |= CSTOPB;	
	if( 'N' == parity)
	{
		options.c_cflag &= ~PARENB;
	}
	else if('E' == parity)
	{
		options.c_cflag |= PARENB;
		options.c_cflag &= ~PARODD;
	}
	else if('O' == parity)
	{
		options.c_cflag |= PARENB;
		options.c_cflag |= PARODD;
	}
	else //('S' == parity) space parity
	{
		options.c_cflag &= ~PARENB;
	}
	tcsetattr(fd, TCSANOW, &options);
return 0;	
}
int sp_write_device(void* obj, char *data, int len)
{
	struct port_s *port = (struct port_s *)obj;
	int fd = port->fd;
	int ret;
	ret = write(fd, data, len);
	if(ret < 0)
		return ret;
}
int sp_read_device(void* obj, char *buf, int len )
{
	struct port_s *port = (struct port_s *)obj;
	int fd = port->fd;
	int ret;
	ret = read(fd, buf, len);
	if(ret < 0)
		return ret;
}
int sp_close_device(void *obj)
{
	struct port_s *serport = (struct port_s *) obj;
	int fd = serport->fd;
	close(fd);
}

#ifdef GG
int main()
{
	char device[25];
	char input[512], output[512];
	int stat;
	int baudrate, databits, stopbits;
	char parity;
	struct port_t *sp_serport;
	printf("Please enter the device name\n");
	scanf("%s", device);
	stat = sp_scan_device(device);
	if(0 == stat)
	{
		sp_serport = (struct port_s*) sp_open_device(device);
		printf("Enter the config parameters: baudrate, databits, stopbits, parity, flow and timeout\n");
		scanf("%d %d %d %c", &baudrate, &databits, &stopbits, &parity);
		sp_configure_device(sp_serport, baudrate, databits, stopbits, parity);
		while(1)
		{
			printf("Please enter the Data\n");
			scanf("%s", input);
			if(sp_write_device(sp_serport, input, sizeof(input))< 0)
			{
				printf("not able to write on the device\n");
			}
			if(sp_read_device(sp_serport, output, sizeof(output))<0)
			{
				printf("not able to read\n");
			}
		}
	}
}
#endif
