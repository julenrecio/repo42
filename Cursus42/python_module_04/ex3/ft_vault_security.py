#!/usr/bin/env python3

def secure_archive(filename: str, action: bool = False,
                   content: str = "") -> tuple[bool, str]:
    if action:
        if content == "":
            return (False, "Content to write in the file must be provided")
        else:
            with open(filename, 'w') as file:
                file.write(content)
                return (True, "Content successfully written to file")
    else:
        try:
            with open(filename, 'r') as file:
                content = file.read()
                return (True, content)
        except FileNotFoundError as f:
            return (False, str(f))
        except PermissionError as p:
            return (False, str(p))


if __name__ == "__main__":
    print("=== Cyber Archives Security ===\n")
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file", False))
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("pass.txt", False))
    print("\nUsing 'secure_archive' to read from a regular file:")
    read: tuple = secure_archive("a.txt", False)
    print(read)
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    print(secure_archive("b.txt", True, read[1]))
