#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Jude Michael Teves
#
# This is my implementation of the k-nearest neighbors machine learning algorithm.
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

import numpy as np
import pandas as pd

from collections import Counter

class KNN():
  def __init__(self, k:int=3, p:int=2):
    '''
    Parameters:
    k - number of neighbors
    p - order in Minkowski distance (1 - Manhattan, 2 - Euclidean)
    '''
    self.k = k
    self.p = p
    pass

  def minkowski(self, X, point) -> list:
    '''
    Returns a list of distances of each elements in X from the reference point.
    Vectorized implementation.
    '''
    X = np.array(X)
    d = ((abs(X-point)**self.p).sum(axis=1))**(1/self.p)
    distances = list(d)
    return distances
  
  def get_nearest_neighbors(self, X, point) -> list:
    '''
    Returns indices of nearest neighbors
    '''
    distances = self.minkowski(X, point)
    indices = np.argsort(distances)[:self.k].tolist()
    return indices
  
  def fit(self, X, y):
    '''
    'Train' the model. In kNN's case, it just memorizes the values.
    ---
    Parameters:
    X - input matrix
    y - output vector
    '''
    self.X_train = X
    self.y_train = y
    pass

  def predict(self, X) -> list:
    '''
    Return predictions
    ---
    Parameters:
    X - input matrix
    '''
    pass

  def score(self, X, y) -> float:
    '''
    R-squared for regression.
    Accuracy for classification.
    ---
    Parameters:
    X - input matrix
    y - output vector
    '''
    pass


class KNNRegressor(KNN):
  @staticmethod
  def r_squared(y_true:np.array, y_pred:np.array) -> float:
    '''
    Returns the score using R-squared metric.
    '''
    u = ((y_true - y_pred) ** 2).sum() # residual sum of squares
    v = ((y_true - y_true.mean()) ** 2).sum() # total sum of squares
    score = 1 - (u/v)
    return score

  def calculate(self, point):
    '''
    Returns the value of a new data point
    '''
    indices = self.get_nearest_neighbors(self.X_train, point)
    labels = self.y_train[indices]
    label = labels.sum()/len(labels)
    return label

  def predict(self, X) -> list:
    y_pred = [self.calculate(point) for point in X]
    return y_pred
    pass

  def score(self, X, y) -> float:
    y_pred = self.predict(X)
    return self.r_squared(y, y_pred)
    pass


class KNNClassifier(KNN):

  def classify(self, point):
    '''
    Returns the classification of a new data point
    '''
    indices = self.get_nearest_neighbors(self.X_train, point)
    labels = self.y_train[indices]
    label = Counter(labels).most_common(1)[0][0]
    return label

  def predict(self, X) -> list:
    y_pred = [self.classify(point) for point in X]
    return y_pred
    pass

  def score(self, X, y) -> float:
    y_pred = self.predict(X)
    return sum(y_pred == y)/len(y) # accuracy
    pass
