from pathlib import Path

def submit_cpp():
  mySTL = ['dsu', 'segtree', 'CustomHash', 'modint', 'treap', 'odt']
  solution = Path('solution.cpp').read_text()
  check = dict.fromkeys(mySTL, False)
  leet = False

  result = ''

  for lib in mySTL:
    if lib in solution:
      check[lib] = True

  result += ('#include <bits/stdc++.h>\n')
  result += Path('bits/freq.h').read_text()

  for lib in mySTL:
    if check[lib]:
      result += Path('mySTL/' + lib + '.h').read_text()
  with open('solution.cpp', 'r') as s:
    for line in s:
      if '#include' in line:
        continue
      if 'Solution' in line:
        leet = True
      if leet and "main" in line:
        break
      result += line

  print(result)