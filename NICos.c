#
#
#

typedef struct {
    Buffer *next;
    size_t;
    Buffer *prev;
} Buffer;

void add_buffer(Buffer *buffer) {
    while (buffer->next!=NULL) {
        buffer=buffer->next;
    }
    new_buffer=Buffer buffer;
    buffer->next=new_buffer;
    new_buffer->prev=buffer;
    new_buffer->next=NULL;
}

void delete_buffer(Buffer *buffer) {

}

void read_buffer(Buffer *buffer) {

}
void extract_packet(Buffer *buffer, char *input) {
    fgets(input, sizeof(buffer), buffer);//stops at null terminator
    buffer->bit=0;
}
void parse_to_os(char *input) {

}
/*In kernel code i begin with a circular buffer on the stack represented by a pointer plus a value which is the size 
of the buffer. None of the above methods for add, delete and read are used. Just setup 10 such buffer. The DD is an int 
value either 0 or 1 on the stack after which i have the address 64 bit pointing to a buffer of constant length then it must
be allocated on the stack also. Implement the interrupt loop for the driver then pass the value of the buffer pointed to by
the pointer into another register.   */




















