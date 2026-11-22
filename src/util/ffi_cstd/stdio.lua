local ffi = require('ffi')

ffi.cdef [[

typedef struct FILE_ { void* _Placeholder; } FILE;
typedef int64_t fpos_t;

int fclose(FILE *stream);
void clearerr(FILE *stream);
int feof(FILE *stream);
int ferror(FILE *stream);
int fflush(FILE *stream);
int fgetpos(FILE *stream, fpos_t *pos);
FILE *fopen(const char *filename, const char *mode);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
FILE *freopen(const char *filename, const char *mode, FILE *stream);
int fseek(FILE *stream, long int offset, int whence);
int fsetpos(FILE *stream, const fpos_t *pos);
long int ftell(FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int remove(const char *filename);
int rename(const char *old_filename, const char *new_filename);
void rewind(FILE *stream);
void setbuf(FILE *stream, char *buffer);
int setvbuf(FILE *stream, char *buffer, int mode, size_t size);
FILE *tmpfile(void);
char *tmpnam(char *str);
int fprintf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int sprintf(char *str, const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list arg);
int vprintf(const char *format, va_list arg);
int vsprintf(char *str, const char *format, va_list arg);
int fscanf(FILE *stream, const char *format, ...);
int scanf(const char *format, ...);
int sscanf(const char *str, const char *format, ...);
int fgetc(FILE *stream);
char *fgets(char *str, int n, FILE *stream);
int fputc(int char_, FILE *stream);
int fputs(const char *str, FILE *stream);
int getc(FILE *stream);
int getchar(void);
char *gets(char *str);
int putc(int char_, FILE *stream);
int putchar(int char_);
int puts(const char *str);
int ungetc(int char_, FILE *stream);
void perror(const char *str);

]]

--
local M = {}

M.EOF = -1

M.SEEK_SET = 0
M.SEEK_CUR = 1
M.SEEK_END = 2

M.FILENAME_MAX = 260
M.FOPEN_MAX = 20
M.TMP_MAX = 2147483647

return M
