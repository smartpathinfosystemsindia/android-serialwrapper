/***********************
	Serial.h
***********************/
#define MAX 10
struct port_s
{
    int fd;
    char port_name[MAX];
    struct termios;
    unsigned char *writebuf;
    struct readbuf;
    unsigned char *userbuf;
};
typedef struct port_s port_t;


struct readbuf
{
    char readbuf_name[MAX];
    int front;
    int rear;
    int length;
};

int sp_scan_device(char *name);/* will check the device name entered by user as valid or not*/
void *sp_serial_open(char * name); /*give fd, name & alloc mem n init ringbuf*/
int sp_configure_device(void * obj, int Baudrate, int databits, int stopbit, int parity, int flow, int timeout);
int sp_write_device(void* obj, char *data, int len);
int sp_read_device(void* obj, char *buf, int len );
int sp_write_device_async(void* obj, char *data, int len);/*cp data to ring buf and start a thread in which write ringbuf to fd*/
int sp_read_device_async(void* obj, char *buf, int len );
int sp_data_available(void *obj); /*Diff b/w rear and front :-returns -1 if no data else positive val*/
int sp_data_written(void *obj);/*no. of bytes written in async*/
int sp_close_device(void *obj);/*dealloc mem for hte buf also*/



