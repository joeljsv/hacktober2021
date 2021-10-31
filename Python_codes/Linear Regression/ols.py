#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Jude Michael Teves
#
# This is my implementation of the linear regression machine learning algorithm through ordinary least squares method.
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

class OLS():
  def fit(self, X, y):
    b = np.ones(X.shape[0]).reshape(-1,1)
    X = np.concatenate([b, X], axis=1)
    theta = np.linalg.inv(np.dot(X.T, X)) @ X.T @ y.T
    self.theta = theta
    return theta
  
  def predict(self, X):
    b = np.ones(X.shape[0]).reshape(-1,1)
    X = np.concatenate([b, X], axis=1)
    return X @ self.theta

  @staticmethod
  def r_squared(y_true:np.array, y_pred:np.array) -> float:
    '''
    Returns the score using R-squared metric.
    '''
    u = ((y_true - y_pred) ** 2).sum() # residual sum of squares
    v = ((y_true - y_true.mean()) ** 2).sum() # total sum of squares
    score = 1 - (u/v)
    return score

  def score(self, X, y) -> float:
    y_pred = self.predict(X)
    return self.r_squared(y, y_pred)
