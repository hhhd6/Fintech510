import os

file_path = 'example_file.txt'
if os.path.isfile(file_path):
    print("File exists.")
else:
    print("File does not exist.")