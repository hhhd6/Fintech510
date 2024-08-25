# FinTech510 Student Repository

This repository provides the assignments used for the FinTech 510 - 
Programming for Financial Technology course at Duke University.

## Getting started
You will need to clone this repository to your computer.  After you have 
established your environment as defined in the [Preliminaries Section](https://fintechpython.pages.oit.duke.edu/jupyternotebooks/0-Preliminaries/01-Environment.html)
of the [Programming for Financial Technology](https://duke.is/FTGuide) guide, 
execute these steps for your platform:
 
### MacOS
1. Open a terminal Window
2. Execute the following commands:
   ```bash
   cd ~/Documents
   git clone https://gitlab.oit.duke.edu/fintech-510/fintech510-studentrepository
   ```
   
That creates `~/Documents/fintech510-studentrepository` on your Mac.

You can then start VS Code to view the assignments:
```bash
cd ~/Documents/fintech510-studentrepository
code .
```

Once you've opened up the repository folder, that location will be available
on the "Welcome" page under "Recent".  

You can also open VSCode from the Launchpad and then open the appropriate folder.

### Windows
1. Open Ubuntu / WSL.
2. Execute the following commands:
   ```bash
   WINDOWS_HOME=$(echo /mnt/c/Users/$(cmd.exe /c "echo %USERNAME%" | tr -d '\r'))
   cd "$WINDOWS_HOME"/Documents
   git clone https://gitlab.oit.duke.edu/fintech-510/fintech510-studentrepository
   cd
   ln -s "$WINDOWS_HOME"/Documents/fintech510-studentrepository fintech510-studentrepository
   ```
3. To start VS Code, you must still be in Ubuntu / WSL.
   ```bash
   cd ~/fintech510/student-repository
   code .
   ```

In Step 2, the first line creates a variable containing the location of
your home directory in the Windows environment.  You can see the contents of that
variable by running `echo $WINDOWS_HOME`.

The following line then changes the current working directory to the "Documents" folder
in your Windows environment. You can execute `ls` to see the contents of
the directory and validate that you are in the correct location.

The third line clones (makes a local copy) of the FinTech 510 Student Repository
to your computer.

The last line creates a soft link (Linux shortcut) from your WSL home directory
to the repository directory within Windows.
   
With Windows, it can become a bit confusing whether you are in the 
regular Windows environment or WSL. When we execute code and use VS Code, we
want to use the WSL environment. Hence, starting VS Code from the WSL
window.  However, we also want you to be able to quickly find your code files, 
so we have placed the student repository under your normal "Documents" folder. 
The `/mnt/c` directory in WSL points to "C:\\" in Windows.

The `ln -s` command created a symbolic link from your home directory in WSL
to the student repository directory under your Windows "Documents" folder.

Once you've started VS Code, you should be able to use the "Recent" list to open
VS Code within the WSL environment, even if you start it from the application icon
or the Start Menu.  You can also repeat step #3 above to open VS Code.

