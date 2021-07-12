# Installation
1. Create solution and project in Visual Studio
2. Copy the nanodbc folder within solution's folder

# Configure your project to use nanodbc
0. Configure your project to be **x64**!!!
1. Open project's properties
2. Navigate to C/C++ > Additional Include Directories
2.1. Add the path: $(SolutionDir)nanodbc\src
3. Navigate to Linker > General > Additional Linrary Directories
3.1. Add the path: $(SolutionDir)nanodbc\bin
4. Navigate to Linker > Input > Additional dependencies
4.1. Add: nanodbc.library

# Examples
[Example program](https://nanodbc.github.io/nanodbc/use.html#quickstart)

# Connection strings
1. Driver={ODBC Driver 17 for SQL Server};Server=**(localdb)\MSSQLLocalDB**;Database=**master**;Trusted_Connection=yes;
2. Driver={ODBC Driver 17 for SQL Server};Server=**(localdb)\MSSQLLocalDB**;Database=**master**;UID=sqlUsername;PWD=sqlPassword;