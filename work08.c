#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

unsigned long get_file_size(char *path){
  struct stat sb;
  stat(path, &sb);

  return sb.st_size;
}

unsigned int get_file_permissions(char *path){
  struct stat sb;
  stat(path, &sb);

  return sb.st_mode;
}

char * get_file_accesstime(char *path){
  struct stat sb;
  stat(path, &sb);

  return ctime(&sb.st_atime);
}

int main(){
  int fd;
  char buff[] = "hello";
  //printf("%lu", sizeof(buff));
  fd = open("file", O_CREAT | O_WRONLY, 0644);
  write(fd, buff, sizeof(buff));
  close(fd);

  printf("size of file: %lu\n", get_file_size("file"));
  printf("permissions of file: %o\n", get_file_permissions("file"));
  printf("last access time of file: %s\n", get_file_accesstime("file"));

  printf("last access time of test: %s\n", get_file_accesstime("test"));
  
  return 0;
}
