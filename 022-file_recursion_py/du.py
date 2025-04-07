import sys
import os


def du(file):
    """
    From the given directory produce output similar to the linux command: du -ac
    However rather than the number of blocks the size of the files and directories
    should be printed
    
    returns: size of the given directory and all of its subdirectories/files
    """
    total_size = 0
    for entry in sorted(os.listdir(file)):
        path = os.path.join(file, entry)
        
        if os.path.isdir(path):
            size = du(path)
            total_size += size
            print('{}\t{}'.format(size, path))
        else:
            size = os.path.getsize(path)
            total_size += size
            print('{}\t{}'.format(size, path))
            
    directory_size = os.path.getsize(file)
    total_size += directory_size

    return total_size
            

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python du.py directory")
        sys.exit(2)
    total_size = du(sys.argv[1])
    # print the total line
    print('{}\t{}'.format(total_size, sys.argv[1]))
    print('{}\t{}'.format(total_size, 'total'))
