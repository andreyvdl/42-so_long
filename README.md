# 42-so_long

Program name | Files to turn in | Makefile rules | External functions | Result
:---: | :---: | :---: | :---: |:---:
so_long | Makefile, \*.h, \*.c, maps, textures | NAME, all, clean, fclean, re | open, close, read, write, malloc, free, perror, streeror, exit, all math.h functions, all mlx functions, ft_printf or any equivalent made, (libft) | 0/100%

## Objective

>You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want.

## Execution
```sh
make
./so_long <filename>.ber
```

or

```
make bonus
./so_long <filename>.ber
```

### [CODAM MLX](https://github.com/codam-coding-college/MLX42)
### [42Paris](https://github.com/42Paris/minilibx-linux)

### Key table (numerical order)

code used to get that values:
```c
#include <mlx.h>
#include <stdio.h>

// The param "*key" is used because the function "mlx_key_hook" needs a pointer NULL.
// We assign "*key" to "keycode" so the compiler don't say we are not using "*key".
int	key_hook(int keycode, int *key)
{
	printf("key: %c ", (unsigned char)keycode);
	*key = keycode;
	printf("keycode: %d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	int		key;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Map Keys");
	mlx_key_hook(win, key_hook, &key);
	mlx_loop(mlx);
	return (0);
}
```

<!-- 32 | space | 39 | ' | 45 | -
44 | , | 46 | . | 47 | /
48 | 0 | 49 | 1 | 50 | 2
51 | 3 | 52 | 4 |53 | 5
54 | 6 | 55 | 7 | 56 | 8
57 | 9 | 59 | ; | 61 | =
91 | [ | 92 | \ | 93 | ]
97 | a | 98 | b | 99 | c
100 | d | 101 | e | 102 | f
103 | g | 104 | h | 105 | i
106 | j | 107 | k | 108 | l
109 | m | 110 | n | 111 | o
112 | p | 113 | q | 114 | r
115 | s | 116 | t | 117 | u
118 | v | 119 | w | 120 | x
121 | y | 122 | z |-->

number	| key			| number	| key
:---:	| :---:			| :---:		| :---:
231		| ç				| 65027		| AltGr (right Alt)
65105	| ´				| 65107		| ~
65288	| backspace		| 65289		| tab
65293	| enter			| 65299		| pause
65300	| scrollock		| 65307		| esc
65360	| HOME			| 65361		| ⬅
65362	| ⬆				| 65363		| ➡
65364	| ⬇				| 65365		| page up
65366	| page down		| 65367		| END
65379	| insert		| 65383		| context menu key
65407	| num lock		| 65421		| num_enter
65429	| num_7			| 65430		| num_4
65431	| num_8			| 65432		| num_6
65433	| num_2			| 65434		| num_9
65435	| num_3			| 65436		| num_1
65437	| num_5			| 65438		| num_0
65439	| num_,			| 65450		| num_*
65451	| num_+			| 65453		| num_-
65454	| num_.			| 65455		| num_/
65470	| F1			| 65471		| F2
65472	| F3			| 65473		| F4
65474	| F5			| 65475		| F6
65476	| F7			| 65477		| F8
65478	| F9			| 65479		| F10
65480	| F11			| 65481		| F12
65505	| left shift	| 65506		| right shift
65507	| left ctrl		| 65508		| right ctrl
65509	| capslock		| 65513		| left alt
65515	| windows		| 65535		| delete

### Errno table

Num		| Name				| Error
:---:	| :---:				| :---:
1		| EPERM				| Operation not permitted
2		| ENOENT			| No such file or directory
3		| ESRCH				| No such process
4		| EINTR				| Interrupted system call
5		| EIO				| Input/output error
6		| ENXIO				| No such device or address
7		| E2BIG				| Argument list too long
8		| ENOEXEC			| Exec format error
9		| EBADF				| Bad file descriptor
10		| ECHILD			| No child processes
11		| EAGAIN			| Resource temporarily unavailable
11		| EWOULDBLOCK		| Resource temporarily unavailable
12		| ENOMEM			| Cannot allocate memory
13		| EACCES			| Permission denied
14		| EFAULT			| Bad address
15		| ENOTBLK			| Block device required
16		| EBUSY				| Device or resource busy
17		| EEXIST			| File exists
18		| EXDEV				| Invalid cross-device link
19		| ENODEV			| No such device
20		| ENOTDIR			| Not a directory
21		| EISDIR			| Is a directory
22		| EINVAL			| Invalid argument
23		| ENFILE			| Too many open files in system
24		| EMFILE			| Too many open files
25		| ENOTTY			| Inappropriate ioctl for device
26		| ETXTBSY			| Text file busy
27		| EFBIG				| File too large
28		| ENOSPC			| No space left on device
29		| ESPIPE			| Illegal seek
30		| EROFS				| Read-only file system
31		| EMLINK			| Too many links
32		| EPIPE				| Broken pipe
33		| EDOM				| Numerical argument out of domain
34		| ERANGE			| Numerical result out of range
35		| EDEADLK			| Resource deadlock avoided
35		| EDEADLOCK			| Resource deadlock avoided
36		| ENAMETOOLONG		| File name too long
37		| ENOLCK			| No locks available
38		| ENOSYS			| Function not implemented
39		| ENOTEMPTY			| Directory not empty
40		| ELOOP				| Too many levels of symbolic links
42		| ENOMSG			| No message of desired type
43		| EIDRM				| Identifier removed
44		| ECHRNG			| Channel number out of range
45		| EL2NSYNC			| Level 2 not synchronized
46		| EL3HLT			| Level 3 halted
47		| EL3RST			| Level 3 reset
48		| ELNRNG			| Link number out of range
49		| EUNATCH			| Protocol driver not attached
50		| ENOCSI			| No CSI structure available
51		| EL2HLT			| Level 2 halted
52		| EBADE				| Invalid exchange
53		| EBADR				| Invalid request descriptor
54		| EXFULL			| Exchange full
55		| ENOANO			| No anode
56		| EBADRQC			| Invalid request code
57		| EBADSLT			| Invalid slot
59		| EBFONT			| Bad font file format
60		| ENOSTR			| Device not a stream
61		| ENODATA			| No data available
62		| ETIME				| Timer expired
63		| ENOSR				| Out of streams resources
64		| ENONET			| Machine is not on the network
65		| ENOPKG			| Package not installed
66		| EREMOTE			| Object is remote
67		| ENOLINK			| Link has been severed
68		| EADV				| Advertise error
69		| ESRMNT			| Srmount error
70		| ECOMM				| Communication error on send
71		| EPROTO			| Protocol error
72		| EMULTIHOP			| Multihop attempted
73		| EDOTDOT			| RFS specific error
74		| EBADMSG			| Bad message
75		| EOVERFLOW			| Value too large for defined data type
76		| ENOTUNIQ			| Name not unique on network
77		| EBADFD			| File descriptor in bad state
78		| EREMCHG			| Remote address changed
79		| ELIBACC			| Can not access a needed shared library
80		| ELIBBAD			| Accessing a corrupted shared library
81		| ELIBSCN			| .lib section in a.out corrupted
82		| ELIBMAX			| Attempting to link in too many shared libraries
83		| ELIBEXEC			| Cannot exec a shared library directly
84		| EILSEQ			| Invalid or incomplete multibyte or wide character
85		| ERESTART			| Interrupted system call should be restarted
86		| ESTRPIPE			| Streams pipe error
87		| EUSERS			| Too many users
88		| ENOTSOCK			| Socket operation on non-socket
89		| EDESTADDRREQ		| Destination address required
90		| EMSGSIZE			| Message too long
91		| EPROTOTYPE		| Protocol wrong type for socket
92		| ENOPROTOOPT		| Protocol not available
93		| EPROTONOSUPPORT	| Protocol not supported
94		| ESOCKTNOSUPPORT	| Socket type not supported
95		| ENOTSUP			| Operation not supported
95		| EOPNOTSUPP		| Operation not supported
96		| EPFNOSUPPORT		| Protocol family not supported
97		| EAFNOSUPPORT		| Address family not supported by protocol
98		| EADDRINUSE		| Address already in use
99		| EADDRNOTAVAIL		| Cannot assign requested address
100		| ENETDOWN			| Network is down
101		| ENETUNREACH		| Network is unreachable
102		| ENETRESET			| Network dropped connection on reset
103		| ECONNABORTED		| Software caused connection abort
104		| ECONNRESET		| Connection reset by peer
105		| ENOBUFS			| No buffer space available
106		| EISCONN			| Transport endpoint is already connected
107		| ENOTCONN			| Transport endpoint is not connected
108		| ESHUTDOWN			| Cannot send after transport endpoint shutdown
109		| ETOOMANYREFS		| Too many references: cannot splice
110		| ETIMEDOUT			| Connection timed out
111		| ECONNREFUSED		| Connection refused
112		| EHOSTDOWN			| Host is down
113		| EHOSTUNREACH		| No route to host
114		| EALREADY			| Operation already in progress
115		| EINPROGRESS		| Operation now in progress
116		| ESTALE			| Stale file handle
117		| EUCLEAN			| Structure needs cleaning
118		| ENOTNAM			| Not a XENIX named type file
119		| ENAVAIL			| No XENIX semaphores available
120		| EISNAM			| Is a named type file
121		| EREMOTEIO			| Remote I/O error
122		| EDQUOT			| Disk quota exceeded
123		| ENOMEDIUM			| No medium found
124		| EMEDIUMTYPE		| Wrong medium type
125		| ECANCELED			| Operation canceled
126		| ENOKEY			| Required key not available
127		| EKEYEXPIRED		| Key has expired
128		| EKEYREVOKED		| Key has been revoked
129		| EKEYREJECTED		| Key was rejected by service
130		| EOWNERDEAD		| Owner died
131		| ENOTRECOVERABLE	| State not recoverable
132		| ERFKILL			| Operation not possible due to RF-kill
133		| EHWPOISON			| Memory page has hardware error
