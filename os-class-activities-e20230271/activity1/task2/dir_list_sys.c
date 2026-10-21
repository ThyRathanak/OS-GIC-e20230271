
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

int main()
{
  char buffer[512];

  // 1. Open the current directory
  DIR *dir = opendir(".");

  if (dir == NULL)
  {
    const char *err = "Error opening directory\n";
    write(2, err, strlen(err));
    return 1;
  }

  struct dirent *entry;
  struct stat fileStat;

  // 2. Print the header using write()
  int len = snprintf(buffer, sizeof(buffer),
                     "%-30s %10s\n",
                     "Filename", "Size (bytes)");

  if (len > 0 && (size_t)len < sizeof(buffer))
  {
    write(1, buffer, (size_t)len);
  }

  len = snprintf(buffer, sizeof(buffer),
                 "%-30s %10s\n",
                 "------------------------------", "----------");

  if (len > 0 && (size_t)len < sizeof(buffer))
  {
    write(1, buffer, (size_t)len);
  }

  // 3. Read directory entries
  while ((entry = readdir(dir)) != NULL)
  {

    // 4. Get information about each entry
    if (stat(entry->d_name, &fileStat) == 0)
    {

      // 5. Format the filename and size
      len = snprintf(buffer, sizeof(buffer),
                     "%-30s %10ld\n",
                     entry->d_name, (long)fileStat.st_size);

      // Write the formatted line to stdout
      if (len > 0 && (size_t)len < sizeof(buffer))
      {
        write(1, buffer, (size_t)len);
      }
    }
  }

  // 6. Close the directory
  closedir(dir);

  return 0;
}
