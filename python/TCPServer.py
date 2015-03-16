#!/usr/bin/env python   
#TCP SERVER,When Client send string, add a ctime,then echo and send to client 
from socket import *  
from time import ctime  
HOST = ''  
PORT = 20000       
BUFSIZE = 1024    #1KB   
ADDR = (HOST, PORT)  
tcpSerSock = socket(AF_INET, SOCK_STREAM)  
tcpSerSock.bind(ADDR)  
tcpSerSock.listen(5)  
while True:  
    print 'waiting for connection...'  
    tcpClientSock,clientAddr = tcpSerSock.accept()  
    print '...connected from :', clientAddr  
    while True:  
        data = tcpClientSock.recv(BUFSIZE)  
        if not data:  
            break  
        print '[%s] %s' % (ctime(), data)  
        tcpClientSock.send('[%s] %s' % (ctime(), data))  
    tcpClientSock.close()  
tcpSerSock.close()  
