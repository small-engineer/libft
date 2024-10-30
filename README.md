# Libft

Libft is a custom C library that implements essential utility functions, serving as a foundation for various C projects. The goal of this library is to recreate standard library functions and provide additional tools for developers to use across multiple projects.

---

## Directory Structure

```
libft/
│
├── Makefile             # Build configuration
├── README.md            # Project documentation
├── auto_git_push.sh     # Script to automate Git pushes
├── git_auto_push.log    # Log file for Git automation
├── libft.a              # Compiled static library
│
├── include/             # Header files directory
│   └── libft.h          # Main header file with declarations
│
├── obj/                 # Directory for object files
│   ├── lists/
│   ├── memory/
│   ├── string/
│   └── utils/
│
├── src/                 # Source code directory
│   ├── lists/
│   ├── memory/
│   ├── string/
│   └── utils/
│
└── tests/               # Test files directory
    └── test.c           # Test code
```

---

## Compilation

To compile the library, run the following command:

```
make
```

This will generate the static library `libft.a`.

---

## Cleaning Up

To clean up object files, use:

```
make clean
```

To remove all generated files, including the library:

```
make fclean
```

---

## Testing

Compile and run the test file with:

```
gcc -o test tests/test.c libft.a -I include
./test
```

---

## Author

Developed as part of the 42 curriculum to enhance understanding of standard C functions and libraries.
