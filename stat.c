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
  fd = open("file1.test", O_CREAT | O_WRONLY, 0644);
  write(fd, buff, sizeof(buff));
  close(fd);

  printf("size of file: %lu\n", get_file_size("file1.test"));
  printf("permissions of file: %o\n", get_file_permissions("file1.test"));
  printf("NOTE: file1.test is accessed each time the file is run, file2.test isn't\n");
  printf("last access time of file1.test: %s\n", get_file_accesstime("file1.test"));
  printf("last access time of file2.test: %s\n", get_file_accesstime("file2.test"));

  return 0;
}
