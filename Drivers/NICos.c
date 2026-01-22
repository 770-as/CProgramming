#
#
#

typedef struct {
    Buffer *next;
    size_t;
    data_address;
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
    //fgets(input, sizeof(buffer), buffer);//stops at null terminator
    memcpy(internal_buffer, buffer->, packet_length);
    buffer->bit=0;
}
loop_start:
    mov eax, [esi] ; esi is the source pointer dereference the pointer to get its data into the register
    mov [edi], eax ; edi is the destination pointer for the nic driver
    add esi, 4 ; the source pointer is incremented by 4
    add edi, 4 ; the destination is incremented by 4
    dec ecx ; decrement the number of 5-byte double words to move
    jnz loop_start ; 
    //in short:
    rep movsd ; rep handles dec ecx and jnz and movsd the mov add esi and add edi    
void parse_to_os(char *input) { 

}
/*In kernel code i begin with a circular buffer on the stack represented by a pointer plus a value which is the size 
of the buffer. None of the above methods for add, delete and read are used. Just setup 10 such buffers. The DD is an int 
value either 0 or 1 on the stack after which i have the address 64 bit pointing to a buffer of constant length then it must
be allocated on the stack also. Implement the interrupt loop for the driver then pass the value of the buffer pointed to by
the pointer into another register. The NIC is a piece of hardware and its data is stored in physical memory, for the cpu to handle
it it must be in visual memory that is what the driver does. Since the cpu has no access to physical memory, it needs to identify 
that data to a specific place in the virtual table. That identification allows him to know that this data belongs to the NIC.
If the cpu needs to fetch data from the NIC, it will look at a specific address on the table. That address will call the driver of 
the NIC, the driver will read the data and parse it to the OS. How that virtual table is organized ? How the OS is looking at that
virtual table ? That is virtual memory management. Major number is the driver number and minor number is the device number in
/dev/sda or /dev/eth0 The hardware announces itself with a device id and a vendor id. When the NIC has a packet it pulls a wire 
called an IRQ and the cpu looks at its IDT to know which driver is registered. fgets is made to send data between two points 
where one point has metadata about that, since i know the registers. On older x86 systems the cpu has a dedicated 16 bit 
address space for hardware. It is separate from ram, to move from ram to that space you dont use mov but in and out. When the cpu 
executes an out instruction it toggles a special pin on the chip to tell the motherboard : i am not looking for a memory address but 
for a     hardware port. If you have a serial port at 0xF3 that address exist in parallel dimension to the RAM address 0xF8. 


If the input buffer is in User-Mode memory, a malicious program can change the data while your driver is in the 
middle of the loop. Check: Your driver checks the packet header (e.g., "Is this packet size safe? Yes, 64 bytes").
Attack: A separate malicious thread in the background quickly changes those 64 bytes to 10,000 bytes in the same 
memory location. Use: Your rep movsd loop (or the NIC) continues to read from that pointer, now pulling in 10,000 bytes of data, 
causing a Buffer Overflow or leaking sensitive kernel memory that was sitting next to the buffer.
*/

mov eax, 0x01 ;the "hello" or reset command
mov dx, 0x3F8 ; the address of the peripheral register
out dx, al ; send the byte in al to the hardware port in dx
    
//on modern NICS the logic is the same a memcpy
mov ebx, [reg_base_addr] ;
mov eax, 0x12345678 ;
mov [ebx], eax; 




















