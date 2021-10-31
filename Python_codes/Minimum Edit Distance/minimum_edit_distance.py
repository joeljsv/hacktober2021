#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Jude Michael Teves
#
# My implementation of Minimum Edit (Levenshtein) Distance.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.

def minimum_edit_distance(X, Y):
  '''
  This function calculates the distance matrix of 2 strings.
   
  Parameters
  ---
  X : str
    source string
  Y: str
    target string

  Returns
  ---
  D : matrix (list of lists, numpy array, etc.)
    D is the distance matrix and has a dimension of MxN, 
    where: 
      M = len(X)+1
      N = len(Y)+1

  Examples
  ---
  >>> X, Y = ('ant', 'at')
  >>> D = minimum_edit_distance(X, Y)
  >>> D
  array([[0, 1, 2],
       [1, 0, 1],
       [2, 1, 2],
       [3, 2, 1]])

  '''

  # Get length of each input
  n = len(X)+1
  m = len(Y)+1

  D = np.zeros((n, m), dtype=int) # Create a maxtrix / table of size (n,m) of all zeros
  # Initialize
  D[0, 1:] = range(1, m)
  D[1:, 0] =  range(1, n)

  for i in range(1,n):
    for j in range(1,m):
      diagonal = D[i-1,j-1] + (2 if X[i-1] != Y[j-1] else 0)
      up = D[i,j-1] + 1
      left = D[i-1,j] + 1

      D[i,j] = min(diagonal, up, left)

  return D

def backtrace(D, X, Y):
  '''
  This function does the back alignment. 
  The priority is the operation that has the lowest cost.
  If the same, then do insertion > deletion > substitution.
   
  Parameters
  ---
  D: matrix (list of lists, numpy array, etc.)
    D is the distance matrix and has a dimension of MxN, 
    where: 
      M = len(X)+1
      N = len(Y)+1
  X : str
    source string
  Y: str
    target string

  Returns
  ---
  operations : list of lists
    operations is a list of operations(list), 
    wherein the inner list has the following format:
      [<source character>, <operation>, <target character>]
      
    The symbol for each operation is as follows:
      | => no change
      D => deletion
      I => insertion 
      S => substitution
    
    The operation starts at the last character of the string 
    and ends with the first character.

  Examples
  ---
  >>> X, Y = ('ant', 'at')
  >>> D = minimum_edit_distance(X, Y)
  >>> operations = backtrace(D, X, Y)
  >>> operations
  [['t', '|', 't'], ['n', 'D', '-'], ['a', '|', 'a']]

  '''

  i = D.shape[0] - 1
  j = D.shape[1] - 1
  # print("String1: %s; String2: %s" % (i,j))

  operations = []
  while i != 0 or j != 0:
    diagonal = D[i-1,j-1]	# Match	
    up = D[i-1,j]			  # Delete
    left = D[i,j-1]			    # Insert

    if up < left and up < diagonal:	# highest priority, insertion
      operations.append([X[i-1], "D", "-"])
      i -= 1
    elif left < diagonal: # highest priority, insertion
      operations.append(["-", "I", Y[j-1]])
      j -= 1
    else:
      if X[i-1] == Y[j-1]:
        operations.append([X[i-1], "|", Y[j-1]])
      else:  
        operations.append([X[i-1], "S", Y[j-1]])
      i -= 1
      j -= 1
  
  return operations

def format_backtrace(operations):
  operations = operations[::-1] # reverse
  source = ''.join([o[0] for o in operations])
  operation = ''.join([o[1] for o in operations])
  target = ''.join([o[2] for o in operations])

  output = '\n'.join([source, operation, target])

  return output
