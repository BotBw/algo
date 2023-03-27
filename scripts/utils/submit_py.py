def submit_py():
  result = ''
  
  with open('solution.py', 'r') as s:
    for line in s:
      result += line

  print(result)