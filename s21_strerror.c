// Copyright 2022 michaleh

#include "s21_string.h"
#include <stdlib.h>

#if defined(__linux__)

#define s21_err_max 134

#define s21_errlist                                                            \
  {"Undefined error: 0",                                                       \
   "Operation not permitted",                                                  \
   "No such file or directory",                                                \
   "No such process",                                                          \
   "Interrupted system call",                                                  \
   "I/O error",                                                                \
   "No such device or address",                                                \
   "Argument list too long",                                                   \
   "Exec format error",                                                        \
   "Bad file number",                                                          \
   "No child processes",                                                       \
   "Try again",                                                                \
   "Out of memory",                                                            \
   "Permission denied",                                                        \
   "Bad address",                                                              \
   "Block device requiered",                                                   \
   "Device or resource busy",                                                  \
   "File exists",                                                              \
   "Cross-device link",                                                        \
   "No such device",                                                           \
   "Not a directory",                                                          \
   "Is a directory",                                                           \
   "Invalid argument",                                                         \
   "File table overflow",                                                      \
   "Too many open files",                                                      \
   "Not a typewriter",                                                         \
   "Text file busy",                                                           \
   "File too large",                                                           \
   "No space left on device",                                                  \
   "Illegal seek",                                                             \
   "Read-only file system",                                                    \
   "Too many links",                                                           \
   "Broken pipe",                                                              \
   "Math argument out of domain of func",                                      \
   "Math result not representable",                                            \
   "Resource deadlock would occur",                                            \
   "File name too long",                                                       \
   "No record locks available",                                                \
   "Invalid system call number",                                               \
   "Directory not empty",                                                      \
   "Too many symbolic links encountered",                                      \
   "Operation would block",                                                    \
   "No message of desired type",                                               \
   "Identifier removed",                                                       \
   "Channel number out of range",                                              \
   "Level 2 not synchronized",                                                 \
   "Level 3 halted",                                                           \
   "Level 3 reset",                                                            \
   "Link number out of range",                                                 \
   "Protocol driver not attached",                                             \
   "No CSI structure available",                                               \
   "Level 2 halted",                                                           \
   "Invalid exchange",                                                         \
   "Invalid request descriptor",                                               \
   "Exchange full",                                                            \
   "No anode",                                                                 \
   "Invalid request code",                                                     \
   "Invalid slot",                                                             \
   "Bad font file format",                                                     \
   "Device not a stream",                                                      \
   "No data available",                                                        \
   "Timer expired",                                                            \
   "Out of streams resources",                                                 \
   "Machine is not on the network",                                            \
   "Package not installed",                                                    \
   "Object is remote",                                                         \
   "Link has been severed",                                                    \
   "Advertise error",                                                          \
   "Srmount error",                                                            \
   "Communication error on send",                                              \
   "Protocol error",                                                           \
   "Multihop attempted",                                                       \
   "RFS specific error",                                                       \
   "Not a data message",                                                       \
   "Value too large for defined data type",                                    \
   "Name not unique on network",                                               \
   "File descriptor in bad state",                                             \
   "Remote address changed",                                                   \
   "Can not access a needed shared library",                                   \
   "Accessing a corrupted shared library",                                     \
   ".lib section in a.out corrupted",                                          \
   "Attempting to link in too "                                                \
   "many shared libraries",                                                    \
   "Cannot exec a shared library directly",                                    \
   "Illegal byte sequence",                                                    \
   "Interrupted system call should"                                            \
   " be restarted",                                                            \
   "Streams pipe error",                                                       \
   "Too many users",                                                           \
   "Socket operation on non-socket",                                           \
   "Destination address required",                                             \
   "Message too long",                                                         \
   "Protocol wrong type for socket",                                           \
   "Protocol not available",                                                   \
   "Protocol not supported",                                                   \
   "Socket type not supported",                                                \
   "Operation not supported on "                                               \
   "transport endpoint",                                                       \
   "Protocol family not supported",                                            \
   "Address family not supported by protocol",                                 \
   "Address already in use",                                                   \
   "Cannot assign requested address",                                          \
   "Network is down",                                                          \
   "Network is unreachable",                                                   \
   "Network dropped connection because"                                        \
   " of reset",                                                                \
   "Software caused connection abort",                                         \
   "Connection reset by peer",                                                 \
   "No buffer space available",                                                \
   "Transport endpoint is already connected",                                  \
   "Transport endpoint is not connected",                                      \
   "Cannot send after transport "                                              \
   "endpoint shutdown",                                                        \
   "Too many references: cannot splice",                                       \
   "Connection timed out",                                                     \
   "Connection refused",                                                       \
   "Host is down",                                                             \
   "No route to host",                                                         \
   "Operation already in progress",                                            \
   "Operation now in progress",                                                \
   "Stale file handle",                                                        \
   "Structure needs cleaning",                                                 \
   "Not a XENIX named type file",                                              \
   "No XENIX semaphores available",                                            \
   "Is a named type file",                                                     \
   "Remote I/O error",                                                         \
   "Quota exceeded",                                                           \
   "No medium found",                                                          \
   "Wrong medium type",                                                        \
   "Operation Canceled",                                                       \
   "Required key not available",                                               \
   "Key has expired",                                                          \
   "Key has been revoked",                                                     \
   "Key was rejected by service",                                              \
   "Owner died",                                                               \
   "State not recoverable",                                                    \
   "Operation not possible due to RF-kill",                                    \
   "Memory page has hardware error"};

#endif

#if defined(__APPLE__)

#define s21_err_max 107

#define s21_errlist                                                            \
  {"Undefined error: 0",                                                       \
   "Operation not permitted",                                                  \
   "No such file or directory",                                                \
   "No such process",                                                          \
   "Interrupted system call",                                                  \
   "Input/output error",                                                       \
   "No such device or adress",                                                 \
   "Argument list too long",                                                   \
   "Exec format error",                                                        \
   "Bad file descriptor",                                                      \
   "No child processes",                                                       \
   "Try again",                                                                \
   "Out of memory",                                                            \
   "Permission denied",                                                        \
   "Bad address",                                                              \
   "Block device required",                                                    \
   "Device or resource busy",                                                  \
   "File exists",                                                              \
   "Cross-device link",                                                        \
   "No such device",                                                           \
   "Not a directory",                                                          \
   "Is a directory",                                                           \
   "Invalid argument",                                                         \
   "File table overflow",                                                      \
   "Too many open files",                                                      \
   "Inappropriate ioctl for device",                                           \
   "Text file busy",                                                           \
   "File too large",                                                           \
   "No space left on device",                                                  \
   "Illegal seek",                                                             \
   "Read-only file system",                                                    \
   "Too many links",                                                           \
   "Broken pipe",                                                              \
   "Numerical argument out of domain",                                         \
   "Result too large",                                                         \
   "Resource temporarily unavailable",                                         \
   "Operation now in progress",                                                \
   "Operation already in progress",                                            \
   "Socket operation on non-socket",                                           \
   "Destination address required",                                             \
   "Message too long",                                                         \
   "Protocol wrong type for socket",                                           \
   "Protocol not available",                                                   \
   "Protocol not supported",                                                   \
   "Socket type not supported",                                                \
   "Operation not supported",                                                  \
   "Protocol family not supported",                                            \
   "Address family not "                                                       \
   "supported by protocol family",                                             \
   "Address already in use",                                                   \
   "Can\'t assign requested address",                                          \
   "Network is down",                                                          \
   "Network is unreachable",                                                   \
   "Network dropped connection on reset",                                      \
   "Software caused connection abort",                                         \
   "Connection reset by peer",                                                 \
   "No buffer space available",                                                \
   "Socket is already connected",                                              \
   "Socket is not connected",                                                  \
   "Can\'t send after socket shutdown",                                        \
   "Too many references: can\'t splice",                                       \
   "Operation timed out",                                                      \
   "Connection refused",                                                       \
   "Too many levels of symbolic links",                                        \
   "File name too long",                                                       \
   "Host is down",                                                             \
   "No route to host",                                                         \
   "Directory not empty",                                                      \
   "Too many processes",                                                       \
   "Too many users",                                                           \
   "Disc quota exceeded",                                                      \
   "Stale NFS file handle",                                                    \
   "Too many levels of remote in path",                                        \
   "RPC struct is bad",                                                        \
   "RPC version wrong",                                                        \
   "RPC prog. not avail",                                                      \
   "Program version wrong",                                                    \
   "Bad procedure for program",                                                \
   "No locks available",                                                       \
   "Function not implemented",                                                 \
   "Inappropriate file type or format",                                        \
   "Authentication error",                                                     \
   "Need authenticator",                                                       \
   "Device power is off",                                                      \
   "Device error, e.g. paper out",                                             \
   "Value too large to be stored in data type",                                \
   "Bad executable",                                                           \
   "Bad CPU type in executable",                                               \
   "Shared library version mismatch",                                          \
   "Malformed Macho file",                                                     \
   "Operation canceled",                                                       \
   "Identifier removed",                                                       \
   "No message of desired type",                                               \
   "Illegal byte sequence",                                                    \
   "Attribute not found",                                                      \
   "Bad message",                                                              \
   "Reserved",                                                                 \
   "No message available on STREAM",                                           \
   "Reserved",                                                                 \
   "No STREAM resources",                                                      \
   "Not a STREAM",                                                             \
   "Protocol error",                                                           \
   "STREAM ioctl timeout",                                                     \
   "Operation not supported on socket",                                        \
   "No such policy registered",                                                \
   "State not recoverable",                                                    \
   "Previous owner died",                                                      \
   "Interface output queue is full"};

#endif

char *s21_strerror(int errnum) {
  // Analogues to the strerror function of the standard library
  // The strerror() function accepts an error number argument errnum and returns
  // a pointer to the corresponding message string
  char *text;
  char *answer;
  char *array[s21_err_max] = s21_errlist;
  text = malloc(150 * sizeof(char));
  if ((errnum >= 0) && (errnum <= s21_err_max)) {
    answer = array[errnum];
  } else {
    sprintf(text, "Unknown error: %d", errnum);
    answer = text;
  }
  free(text);
  return *answer;
}
