/* $Copyright: $
 * Copyright (c) 1994 by Steve Baker (ice@mama.indstate.edu)
 * All Rights reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * ascii: Print the ascii table.
 *
 * Usage: ascii [-a] [-b] [-o] [-h]
 *
 * Make: gcc -O -o ascii ascii.c -s
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

enum { BIN, DEC, HEX, OCT };
int num, alt;

u_char chr(u_char);
char *pnum(int);

int main(int argc, char **argv)
{
  int i, j;
  u_char c;

  num = DEC;
  alt = 0;
  for(i=1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (strcmp(argv[i],"--help") == 0) {
	printf("usage: ascii [-aboh]\n");
	printf(" -a\tPrint characters using ansi alternate character-set\n");
	printf(" -b\tPrint ascii values in binary.\n");
	printf(" -o\tPrint ascii values in octal.\n");
	printf(" -h\tPrint ascii values in hexidecimal.\n");
	exit(0);
      }
      for(j=1;argv[i][j];j++) {
        switch(argv[i][j]) {
	  case 'a':
	    alt=1;
	    break;
	  case 'b':
	    num=BIN;
	    break;
	  case 'o':
	    num=OCT;
	    break;
	  case 'h':
	    num=HEX;
	    break;
	}
      }
    }
  }
  if (alt) printf("\033(0");
  for(c=0;c<32;c++) {
    printf(" %4s: '%c'",pnum(c),chr(c));
    printf("\t%4s: '%c'",pnum(c+32),chr(c+32));
    printf("\t%4s: '%c'",pnum(c+64),chr(c+64));
    printf("\t%4s: '%c'\n",pnum(c+96),chr(c+96));
  }
  for(c=128;c<160;c++) {
    if (c>=157 && c<=159) printf(" %4s: ' '",pnum(c));
    else printf(" %4s: '%c'",pnum(c),chr(c));
    printf("\t%4s: '%c'",pnum(c+32),chr(c+32));
    printf("\t%4s: '%c'",pnum(c+64),chr(c+64));
    printf("\t%4s: '%c'\n",pnum(c+96),chr(c+96));
  }
  if (alt) printf("\033(B");
  return 0;
}

u_char chr(u_char c)
{
  if (c < 32 || (c > 126 && c < 160)) return '.';
  else return c;
}

char *pnum(int n)
{
  static char sbuf[10];
  int i;

  switch(num) {
    case BIN:
      for(i=7;i>=0;i--) sbuf[7-i] = (n&(1<<i)) ? '1' : '0';
      sbuf[i] = 0;
      break;
    case DEC:
      sprintf(sbuf,"%d",n);
      break;
    case HEX:
      sprintf(sbuf,"%X",n);
      break;
    case OCT:
      sprintf(sbuf,"%o",n);
      break;
  }
  return sbuf;
}
