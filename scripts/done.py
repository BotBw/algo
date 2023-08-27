import sys
import os
import shutil
import subprocess

def gitAddCommit(filepath):
  subprocess.run('git add ' + filepath, shell=True)
  subprocess.run(f'git commit -m "Add {filepath}"', shell=True)

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
    if os.path.exists('test.out'):
        subprocess.run('rm test.out', shell=True)
    shutil.copy2('solution.cpp', filepath)
    shutil.copy2('templates/template.cpp', 'solution.cpp')
    gitAddCommit(filepath)
    return
  
  if(postfix == 'py'):
    shutil.copy2('solution.py', filepath)
    shutil.copy2('templates/template.py', 'solution.py')
    gitAddCommit(filepath)
    return
  print(filepath + " Unknown file type")

done()