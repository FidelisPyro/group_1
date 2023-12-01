#include "disk.h"
#include "diskmanager.h"
#include "partitionmanager.h"
#include "filesystem.h"
#include "iNode.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;


FileSystem::FileSystem(DiskManager *dm, char fileSystemName)
{

}

int FileSystem::createFile(char *filename, int fnameLen)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::createDirectory(char *dirname, int dnameLen)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::lockFile(char *filename, int fnameLen)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::unlockFile(char *filename, int fnameLen, int lockId)
{
 if(lockId == 0 /*file.lockId*/)
 {
  //unlock file/set file's lockId to -1
  return 0;
 }
 if(lockId <= 0) return -1;
 else return -2;
}

int FileSystem::deleteFile(char *filename, int fnameLen)
{
 if(true/*file not exists*/) return -1;
 if(true/*file locked/opened*/) return -2;
 //remove file/all file info in inode
 if(true/*removed successfully*/) return 0;
 return -3;
}

int FileSystem::deleteDirectory(char *dirname, int dnameLen)
{
 if(true/*directory not exists*/) return -1;
 if(true/*directory not empty*/) return -2;
 //remove dir/all dir info in inode
 if(true/*removed successfully*/) return 0;
 return -3;
}

int FileSystem::openFile(char *filename, int fnameLen, char mode, int lockId)
{
 if(true/*file not exist*/) return -1;
 if(mode != 'm' && mode != 'r' && mode != 'w') return -2;
 if(lockId!=0/*file.lockId*/) return -3;
 if(true/*opened successfully*/)
 {
  //generate/set fileDescriptor
  //rw = 0 for descriptor
  return 0;
 }
 return -4;
}

int FileSystem::closeFile(int fileDesc)
{
 if(fileDesc <=0) return -1;
 //close File in inode, remove fileDesc from wherever we are storing them
 if(true/*file closed correctly*/) return 0;
 return -2;
}

int FileSystem::readFile(int fileDesc, char *data, int len)
{
  return 0; //place holder so there is no warnings when compiling.
}

int FileSystem::writeFile(int fileDesc, char *data, int len)
{
  return 0; //place holder so there is no warnings when compiling.
}

int FileSystem::appendFile(int fileDesc, char *data, int len)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::truncFile(int fileDesc, int offset, int flag)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::seekFile(int fileDesc, int offset, int flag)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::renameFile(char *filename1, int fnameLen1, char *filename2, int fnameLen2)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::renameDirectory(char *dirname1, int dnameLen1, char *dirname2, int dnameLen2)
{
 return -1; //place holder so there is no warnings when compiling.
}

int FileSystem::getAttribute(char *filename, int fnameLen /* ... and other parameters as needed */)
{
 return -1; //place holder so there is no warnings when compiling.
}

int setAttribute(char *filename, int fnameLen /* ... and other parameters as needed */)
{
 return -1; //place holder so there is no warnings when compiling.
}
