# https://open.kattis.com/problems/kornislav
import sys
numbers = sorted( map( lambda x: int(x), sys.stdin.readlines()[0].split(" ") ) )
print( min(numbers[0:1]) * min(numbers[2:3]) )
