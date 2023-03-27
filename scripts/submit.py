import subprocess
import os

from utils.submit_cpp import *
from utils.submit_py import *

def submit():
  cpp = subprocess.check_output('git diff solution.cpp', shell=True)
  py = subprocess.check_output('git diff solution.py', shell=True)
  
  if(len(py) > 0 and len(cpp) > 0):
      print('Not sure which file to submit')
      return
  
  if(len(cpp) > 0):
     submit_cpp()
     return
  
  if(len(py) > 0):
     submit_py()
     return
  
  print('Nothing to submit')

submit()