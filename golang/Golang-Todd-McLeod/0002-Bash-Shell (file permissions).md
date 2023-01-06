
- `pwd`: print working directory
- `ls` : list
- `ls -la` : list -list all
	- PERMISSIONS of files:
		- owner, group, world (rwxrwxrwx)
		- `r, w, x` (read, write, execute)
		- 4, 2, 1
	- `d` - directory
	- Example: drwxrwxrwx = directory, owner, group, world
- `cd` : change directory
- `mkdir` : make directory
- `touch` : makes a new file
- `nano <file name> : text editor
- `cat <file name>` : prints content of a file
- `clear` : clear screen
- `chmod` : change modification (changes permissions)
	- chmod options permissions filename
	- chmod 777 temp.txt
- `env` : shows environment variables
- `rm <file>` : remove file
	- `rm -rf <file/folder>` : remove recursive force
- `.bash_profile & .bashrc`
	- `.bash_profile` is executed for login shells.
	- `.bashrc` is executed for interactive non-login shells.
	- When you login (type username and password) via console, either sitting at the machine, or remotely via. ssh:
	- `.bash_profile` is executed to configure your shell before the initial command prompt.
- `grep <keyword>` : Looks for the keyword in file/ directory, returns lines having keyword.
	- `cat temp2.txt | grep enter` 
	- `ls | grep -i documents`


![[0002-2.png]]


Every Linux system have three types of owner:

1.  **User:** A user is the one who created the file. By default, whosoever, creates the file becomes the owner of the file. A user can create, delete, or modify the file.
2.  **Group:** A group can contain multiple users. All the users belonging to a group have same access permission for a file.
3.  **Other/World:** Any one who has access to the file other than **user** and **group** comes in the category of **other**. Other has neither created the file nor is a group member.


![[0002.png]]


When we type **ls -l** command, ten characters are displayed before user owner and group. First character tells us about the type of the file.

**Following are the file types:**

| First Character | File Type        |
| --------------- | ---------------- |
| -               | Normal File      |
| d               | directory        |
| l               | Symbolic link    |
| p               | Named pipe       |
| b               | Blocked device   |
| c               | Character device |
| s               | Socket           |

You can view all the groups on the system and their members by looking in the `/etc/group` file, as you would with `/etc/passwd` for users.

![[0002-1.png]]


## Examples of Modes (and Permissions)

-   `-rw-------` : A file that is only accessible by its owner
-   `-rwxr-xr-x` : A file that is executable by every user on the system. A “world-executable” file
-   `-rw-rw-rw-` : A file that is open to modification by every user on the system. A “world-writable” file
-   `drwxr-xr-x` : A directory that every user on the system can read and access
-   `drwxrwx---` : A directory that is modifiable (including its contents) by its owner and group
-   `drwxr-x---` : A directory that is accessible by its group

Another thing to note is that even though many permission combinations are possible, only certain ones make sense in most situations. For example, _write_ or _execute_ access is almost always accompanied by _read_ access, since it’s hard to modify, and impossible to execute, something you can’t read.

- We can modify these permissions using `chown`, `chgrp`, and `chmod`.

## Octal Notation
Using this method, each permissions category (owner, group owner, and other) is represented by a number between 0 and 7.

We arrive at the appropriate number by assigning each type of permission a numerical value:

-   4 = read permissions
-   2 = write permissions
-   1 = execute permission

We add up the numbers associated with the type of permissions we would like to grant for each category. This will be a number between 0 and 7 (0 representing no permissions and 7 representing full read, write, and execute permissions) for each category.

For example, if the file owner has read and write permissions, this would be represented as a 6 in the file owner's column. If the group owner requires only read permissions, then a 4 can be used to represent their permissions.

```
-rw-rw-r-- 1 demouser demouser 0 Jul 10 17:23 testfile
```
If we interpret the permissions, we can see that the file owner and file group owner both have read and write privileges, and other users have read capabilities.
If we convert that into octal notation, the owner and group owner would have a permission value of 6 (4 for read, plus 2 for write) and the other category would have 4 (for read). The full permissions would be represented by the triplet 664.
We will pretend that this file contains a bash script that we would like to execute, as the owner. We don't want anyone else to modify the file, including group owners, and we don't want anyone not in the group to be able to read the file at all.

We can represent our desired permissions setting alphabetically like this: -rwxr-----. We will convert that into octal notation and change the permissions with _chmod_:

```
chmod 740 testfile 
ls -l testfile
```

```
-rwxr----- 1 demouser demouser 0 Jul 10 17:23 testfile
```

If we want to change the permissions back, we can easily do that by giving chmod the following command:

```
chmod 664 testfile ls -l testfile
```

```
-rw-rw-r-- 1 demouser demouser 0 Jul 10 17:23 testfile
```
---
## Setting Default Permissions with Umask

The _umask_ command defines the default permissions for newly created files based on the "base" permissions set defined for files and directories.
Files have a base permissions set of **666**, or full read and write access for all users. 
Execute permissions are not assigned by default because most files are not made to be executed (`assigning executable permissions also opens up some security concerns`).

Directories have a base permissions set of 777, or read, write, and execute permissions for all users.

Umask operates by applying a subtractive "mask" to the base permissions shown above. We will use an example to demonstrate how this works.
If we want the owner and members of the owner group to be able to write to newly created directories, but not other users, we would want to assign the permissions to 775.

We need the three digit number that would express the difference between the base permissions and the desired permissions. That number is 002.

```
777 - 775 = 002
```

This resulting number is the umask value that we would like to apply. Coincidently, this is the default umask value for many systems, as we saw when we created a file with the _touch_ command earlier. Let's try again:

```
touch test2 ls -l test2
```

```
-rw-rw-r-- 1 demouser demouser 0 Jul 10 18:30 test2
```

We can define a different umask using the _umask_ command.
If we want to secure our system more, we can say that by default, we want users who are not the file owner to have no permissions at all. This can be accomplished with the 077 umask:
```
umask 077 touch restricted ls -l restricted
```

```
-rw------- 1 demouser demouser 0 Jul 10 18:33 restricted
```

If we have a process that creates shared content, we may want give full permissions to every file and directory that it creates:

```
umask 000 touch openfile ls -l openfile
```

```
-rw-rw-rw- 1 demouser demouser 0 Jul 10 18:36 openfile
```

By default, the settings you assign to _umask_ will only apply to the current shell session. When you log in next time, any new files and directories will be give the original settings chosen by your distribution.


If you would like to make your umask settings persist across sessions, you can define the umask settings in your .bashrc file:
Search to see if there is already a umask value set. Modify the existing value if there is one. Otherwise, add a line at the bottom of the file with your desired umask settings:

```
umask 022
```
Here, we have chosen to give the owner full permissions, and take away write permissions for both the group owner and other categories. Adjust this setting to your liking to make your preferences available next time you log in.

---
