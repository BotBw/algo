from pathlib import Path

solution = Path('solution.cpp').read_text()
mySTL = ['dsu', 'segtree', 'CustomHash', 'modint']
check = dict.fromkeys(mySTL, False)
for lib in mySTL:
  if lib in solution:
    check[lib] = True

with open('tmp.cpp', 'w') as f:
  f.write('#include <bits/stdc++.h>\n')
  freq_txt = Path('bits/freq.h').read_text()
  f.write(freq_txt)
  for lib in mySTL:
    if check[lib]:
      lib_txt = Path('mySTL/' + lib + '.h').read_text()
      f.write(lib_txt)
  with open('solution.cpp', 'r') as s:
    for line in s:
      if line[0] == '#':
        continue
      if "main" in line:
        break
      f.write(line)
  