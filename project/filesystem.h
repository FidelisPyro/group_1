#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "iNode.h"
#include "diskmanager.h"
#include "partitionmanager.h"
#include <vector>
#include <string>


using namespace std;

class FileSystem {
private:
  DiskManager *myDM;
  PartitionManager *myPM;
  char myfileSystemName;
  int myfileSystemSize;
  
  // Node for the files
  struct FileNode 
  {
    string name;
    int iNodeNumber;

    FileNode(const string& name, int iNodeNumber)
      : name(name), iNodeNumber(iNodeNumber){}
  };

  // Node for the directories
  class Directory 
  {
    public:
      string name;
      int iNodeNumber;
      Directory* parent;
      vector<Directory*> children;
      vector<FileNode> entries;

      Directory() : name(""), iNodeNumber(), parent(nullptr){}

      Directory(const string name, int iNodeNumber, Directory* parent)
        : name(name), iNodeNumber(iNodeNumber), parent(parent){}

      void addEntry(const string& name, int iNodeNumber) 
      {
        entries.push_back({name, iNodeNumber});
      }
  };

  // Root directory of the tree structure
  Directory rootDirectory;

  /* declare other private members here */

  public:
    FileSystem(DiskManager *dm, char fileSystemName)
      : rootDirectory("/r", 0, nullptr){}
    int createFile(char *filename, int fnameLen);
    int createDirectory(char *dirname, int dnameLen);
    int lockFile(char *filename, int fnameLen);
    int unlockFile(char *filename, int fnameLen, int lockId);
    int deleteFile(char *filename, int fnameLen);
    int deleteDirectory(char *dirname, int dnameLen);
    int openFile(char *filename, int fnameLen, char mode, int lockId);
    int closeFile(int fileDesc);
    int readFile(int fileDesc, char *data, int len);
    int writeFile(int fileDesc, char *data, int len);
    int appendFile(int fileDesc, char *data, int len);
    int seekFile(int fileDesc, int offset, int flag);
    int truncFile(int fileDesc, int offset, int flag);
    int renameFile(char *filename1, int fnameLen1, char *filename2, int fnameLen2);
    int renameDirectory(char *dirname1, int dnameLen1, char *dirname2, int dnameLen2);
    int getAttribute(char *filename, int fnameLen /* ... and other parameters as needed */);
    int setAttribute(char *filename, int fnameLen /* ... and other parameters as needed */);

    /* declare other public members here */

};
#endif
