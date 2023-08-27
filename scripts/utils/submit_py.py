def submit_py():
  result = ''
  
  with open('solution.py', 'r') as s:
    for line in s:
      if "import" in line or not line.strip():
        continue
      result += line

  print(result)