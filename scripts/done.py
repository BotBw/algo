import sys
import os
import shutil
import subprocess

def done():
  n = len(sys.argv)

  if n != 2:
    print('Invalid arguments')
    return
  
  filepath = 'Solutions/' + sys.argv[1]

  if os.path.exists(filepath):
    print(filepath + ' already exists')
    return
  
  postfix = filepath.split('.')[-1]
  
  if(postfix == 'cpp'):
    shutil.copy2('solution.cpp', filepath)
    shutil.copy2('template.cpp', 'solution.cpp')
    return
  
  if(postfix == 'py'):
    shutil.copy2('solution.py', filepath)
    subprocess.run('cat "" > solution.py')
    return
  print(filepath + " Unknown file type")

done()