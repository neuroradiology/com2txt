#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#ifndef UNIX
#  include <dos.h>
#endif

extern	char	*strcpy(), *strchr();

#ifndef LSI_C
#  define is_upper(c) (isascii(c) && isupper(c))
#  define is_alnum(c) (isascii(c) && isalnum(c))
#  define is_print(c) (isascii(c) && isprint(c))
#else
#  define is_upper(c) isupper(c)
#  define is_alnum(c) isalnum(c)
#  define is_print(c) isprint(c)
#endif
#ifndef iskanji
#  define iskanji(c) \
	(0x81 <= (unsigned)(c) && (unsigned)(c) <= 0x9f || \
	 0xe0 <= (unsigned)(c) && (unsigned)(c) <= 0xfc)
#endif

#ifndef LSI_C
#  define fsetbin(fp) setmode(fileno(fp), O_BINARY)
#endif

#define MAXPATHLEN 128
#define DEFAULT_LEN 54
 /* �o�͂̍s���̃f�t�H���g�Bhdr_data.c�� comtdat1[n], comtdat2[n] �̒�����
    �ő�ȏ�ł��邱�� */
#define QSTRLEN 12

#define MAXOSIZE 65200L /* 0xFEB0 */