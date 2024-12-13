# Pipex 42
External functs.
• open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
• ft_printf and any equivalent
YOU coded

The functions you've listed are essential for system-level programming in C, particularly for projects like **pipex**. Here's a breakdown of each function and what it's used for:

---

### 📂 **File Operations**

1. **`open()`**
   - Opens a file and returns a file descriptor.
   - Commonly used with flags like `O_RDONLY`, `O_WRONLY`, `O_CREAT`, `O_TRUNC`, etc.

   ```c
   #include <fcntl.h>
   int fd = open("file.txt", O_RDONLY);
   ```

2. **`close()`**
   - Closes a file descriptor.
   - Essential to avoid file descriptor leaks.

   ```c
   close(fd);
   ```

3. **`read()`**
   - Reads data from a file descriptor.

   ```c
   char buffer[100];
   ssize_t bytes_read = read(fd, buffer, 100);
   ```

4. **`write()`**
   - Writes data to a file descriptor.

   ```c
   write(fd, "Hello, world!", 13);
   ```

---

### 📝 **Memory Management**

5. **`malloc()`**
   - Allocates memory dynamically on the heap.

   ```c
   char *ptr = (char *)malloc(100 * sizeof(char));
   ```

6. **`free()`**
   - Frees dynamically allocated memory to prevent memory leaks.

   ```c
   free(ptr);
   ```

---

### ⚠️ **Error Handling**

7. **`perror()`**
   - Prints a descriptive error message based on the current value of `errno`.

   ```c
   perror("Error opening file");
   ```

8. **`strerror()`**
   - Returns a string describing the error code passed.

   ```c
   printf("%s\n", strerror(errno));
   ```

---

### 📜 **File Accessibility**

9. **`access()`**
   - Checks if a file exists or if you have specific permissions.

   ```c
   if (access("file.txt", F_OK) == 0) {
       printf("File exists.\n");
   }
   ```

---

### 🔄 **File Descriptor Duplication**

10. **`dup()`**
    - Duplicates a file descriptor to the lowest available file descriptor.

    ```c
    int new_fd = dup(fd);
    ```

11. **`dup2()`**
    - Duplicates a file descriptor to a specific file descriptor.

    ```c
    dup2(fd, STDOUT_FILENO); // Redirects stdout to fd
    ```

---

### 🚀 **Process Management**

12. **`execve()`**
    - Replaces the current process with a new process.

    ```c
    char *args[] = {"/bin/ls", "-l", NULL};
    execve("/bin/ls", args, NULL);
    ```

13. **`exit()`**
    - Terminates the calling process with a specific exit status.

    ```c
    exit(EXIT_SUCCESS);
    ```

14. **`fork()`**
    - Creates a new child process.

    ```c
    pid_t pid = fork();
    ```

15. **`wait()`**
    - Waits for a child process to finish.

    ```c
    wait(NULL);
    ```

16. **`waitpid()`**
    - Waits for a specific child process to finish.

    ```c
    waitpid(pid, NULL, 0);
    ```

---

### 🛠️ **Pipes and Communication**

17. **`pipe()`**
    - Creates a pipe for inter-process communication.

    ```c
    int fd[2];
    pipe(fd);
    ```

---

### 🔥 **File Removal**

18. **`unlink()`**
    - Deletes a file.

    ```c
    unlink("file.txt");
    ```

---

### 🧩 **How These Functions Apply to `pipex`**

In the **pipex** project:
- **`open()`** and **`close()`** manage file descriptors for input/output redirection.
- **`pipe()`** sets up a communication channel between processes.
- **`fork()`** creates child processes to execute commands.
- **`dup2()`** redirects file descriptors to handle piping.
- **`execve()`** runs commands in child processes.
- **`wait()`** or **`waitpid()`** ensures the parent process waits for child processes.
- **`perror()`** and **`strerror()`** handle error messages.

Understanding how these functions interact is key to successfully implementing **pipex**!