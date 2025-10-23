#include "s21_string.h"

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
  char text[1000];
  char *answer;
  char *array[s21_err_max] = s21_errlist;
  if ((errnum >= 0) && (errnum < s21_err_max)) {
    answer = array[errnum];
  } else {
    sprintf(text, "Unknown error: %d", errnum);
    answer = text;
  }
  return answer;
}
