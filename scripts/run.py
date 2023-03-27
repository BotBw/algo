import subprocess

def run():
  cpp = subprocess.check_output('git diff solution.cpp', shell=True)
  py = subprocess.check_output('git diff solution.py', shell=True)
  
  if(len(py) > 0 and len(cpp) > 0):
      print('Not sure which file to run')
      return
  
  if(len(cpp) > 0):
     subprocess.run('g++ solution.cpp -g -Wall -Wextra -Wno-sign-conversion -Wshadow -fsanitize=address,undefined -std=c++20 -o test.out', shell=True)
     subprocess.run('./test.out < input.txt', shell=True)
     return
  
  if(len(py) > 0):
     subprocess.run(['python3 solution.py < input.txt'], shell=True)
     return
  
  print('Nothing to run')


run()