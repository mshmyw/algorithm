/* mkpass - creates a temporary source file that uses random alignment
   and other fancy stuff to disguise a 256 bit password in an executable
   (No, this is not 100% SECURE, it just makes it awfully HARD to
    find the password)	- Mixter */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *getpass (const char *prompt);

static char *header =
"\x2f\x2a\x20\x50\x41\x53\x53\x2e\x68\x20\x2d\x20\x74\x65\x6d\x70\x6f\x72"
"\x61\x72\x79\x20\x70\x61\x73\x73\x77\x6f\x72\x64\x20\x69\x6e\x63\x6c\x75"
"\x64\x65\x0a\x20\x20\x20\x44\x45\x4c\x45\x54\x45\x20\x74\x68\x69\x73\x20"
"\x66\x69\x6c\x65\x20\x61\x66\x74\x65\x72\x20\x63\x6f\x6d\x70\x69\x6c\x61"
"\x74\x69\x6f\x6e\x20\x21\x20\x2a\x2f\x0a\x0a\x23\x69\x6e\x63\x6c\x75\x64"
"\x65\x20\x22\x61\x65\x73\x2e\x68\x22\x0a\x0a\x63\x68\x61\x72\x0a";

static char *function =
"\x76\x6f\x69\x64\x20\x73\x65\x63\x75\x72\x69\x74\x79\x5f\x74\x68\x72\x6f"
"\x75\x67\x68\x5f\x6f\x62\x73\x63\x75\x72\x69\x74\x79\x20\x28\x20\x69\x6e"
"\x74\x20\x73\x77\x31\x74\x63\x68\x20\x29\x0a\x7b\x0a\x63\x68\x61\x72\x20"
"\x68\x69\x5b\x33\x32\x5d\x3b\x0a\x0a\x69\x66\x20\x28\x21\x73\x77\x31\x74"
"\x63\x68\x29\x20\x61\x65\x73\x5f\x73\x65\x74\x6b\x65\x79\x28\x22\x22\x29"
"\x3b\x0a\x20\x20\x65\x6c\x73\x65\x0a\x20\x7b\x0a\x20\x68\x69\x5b\x30\x5d"
"\x20\x3d\x20\x5f\x63\x31\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31"
"\x5d\x20\x3d\x20\x5f\x63\x32\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b"
"\x32\x5d\x20\x3d\x20\x5f\x63\x33\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69"
"\x5b\x33\x5d\x20\x3d\x20\x5f\x63\x34\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68"
"\x69\x5b\x34\x5d\x20\x3d\x20\x5f\x63\x35\x20\x2d\x20\x61\x6c\x3b\x0a\x20"
"\x68\x69\x5b\x35\x5d\x20\x3d\x20\x5f\x63\x36\x20\x2d\x20\x61\x6c\x3b\x0a"
"\x20\x68\x69\x5b\x36\x5d\x20\x3d\x20\x5f\x63\x37\x20\x2d\x20\x61\x6c\x3b"
"\x0a\x20\x68\x69\x5b\x37\x5d\x20\x3d\x20\x5f\x63\x38\x20\x2d\x20\x61\x6c"
"\x3b\x0a\x20\x68\x69\x5b\x38\x5d\x20\x3d\x20\x5f\x63\x39\x20\x2d\x20\x61"
"\x6c\x3b\x0a\x20\x68\x69\x5b\x39\x5d\x20\x3d\x20\x5f\x63\x31\x30\x20\x2d"
"\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31\x30\x5d\x20\x3d\x20\x5f\x63\x31"
"\x31\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31\x31\x5d\x20\x3d\x20"
"\x5f\x63\x31\x32\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31\x32\x5d"
"\x20\x3d\x20\x5f\x63\x31\x33\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b"
"\x31\x33\x5d\x20\x3d\x20\x5f\x63\x31\x34\x20\x2d\x20\x61\x6c\x3b\x0a\x20"
"\x68\x69\x5b\x31\x34\x5d\x20\x3d\x20\x5f\x63\x31\x35\x20\x2d\x20\x61\x6c"
"\x3b\x0a\x20\x68\x69\x5b\x31\x35\x5d\x20\x3d\x20\x5f\x63\x31\x36\x20\x2d"
"\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31\x36\x5d\x20\x3d\x20\x5f\x63\x31"
"\x37\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31\x37\x5d\x20\x3d\x20"
"\x5f\x63\x31\x38\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x31\x38\x5d"
"\x20\x3d\x20\x5f\x63\x31\x39\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b"
"\x31\x39\x5d\x20\x3d\x20\x5f\x63\x32\x30\x20\x2d\x20\x61\x6c\x3b\x0a\x20"
"\x68\x69\x5b\x32\x30\x5d\x20\x3d\x20\x5f\x63\x32\x31\x20\x2d\x20\x61\x6c"
"\x3b\x0a\x20\x68\x69\x5b\x32\x31\x5d\x20\x3d\x20\x5f\x63\x32\x32\x20\x2d"
"\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x32\x32\x5d\x20\x3d\x20\x5f\x63\x32"
"\x33\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x32\x33\x5d\x20\x3d\x20"
"\x5f\x63\x32\x34\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x32\x34\x5d"
"\x20\x3d\x20\x5f\x63\x32\x35\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b"
"\x32\x35\x5d\x20\x3d\x20\x5f\x63\x32\x36\x20\x2d\x20\x61\x6c\x3b\x0a\x20"
"\x68\x69\x5b\x32\x36\x5d\x20\x3d\x20\x5f\x63\x32\x37\x20\x2d\x20\x61\x6c"
"\x3b\x0a\x20\x68\x69\x5b\x32\x37\x5d\x20\x3d\x20\x5f\x63\x32\x38\x20\x2d"
"\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x32\x38\x5d\x20\x3d\x20\x5f\x63\x32"
"\x39\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x32\x39\x5d\x20\x3d\x20"
"\x5f\x63\x33\x30\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b\x33\x30\x5d"
"\x20\x3d\x20\x5f\x63\x33\x31\x20\x2d\x20\x61\x6c\x3b\x0a\x20\x68\x69\x5b"
"\x33\x31\x5d\x20\x3d\x20\x5f\x63\x33\x32\x20\x2d\x20\x61\x6c\x3b\x0a\x20"
"\x61\x65\x73\x5f\x73\x65\x74\x6b\x65\x79\x28\x68\x69\x29\x3b\x0a\x20\x7d"
"\x0a\x7d\x0a";

int
main (void)
{
  char al, *p, c[32], buf[64];
  int i, fd;
  memset (c, 0, sizeof (c));
  srand (getpid ());
  al = (rand () % 40) + 1;
dufus:
  p = getpass ("server key [8 - 32 chars]: ");
#ifdef DEBUG_INSECURE
  printf ("Your password is '%s'.\n", p);
#endif
  if ((strlen (p) > 32) || (strlen (p) < 8))
    goto dufus;
  for (i = 0; i <= strlen (p); i++)
    c[i] = p[i];
  fd = open ("pass.c", O_WRONLY | O_TRUNC | O_CREAT, 0777);
  write (fd, header, strlen (header));
  for (i = 0; i < 31; i++)
    {
      memset (buf, 0, 64);
      sprintf (buf, " _c%d = %d + %d,\n", i + 1, c[i], al);
      write (fd, buf, strlen (buf));
    }
  memset (buf, 0, 64);
  sprintf (buf, " _c32 = %d + %d;\n\n", c[31], al);
  write (fd, buf, strlen (buf));
  memset (buf, 0, 64);
  sprintf (buf, " int al = %d;\n\n", al);
  write (fd, buf, strlen (buf));
  memset (buf, 0, 64);
  write (fd, function, strlen (function));
  close (fd);
  printf ("compiling server with %d byte password...\n", strlen (c));
  return (0);
}
