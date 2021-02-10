from sympy import *
x=symbols('x')
f=pow(factorial(x),1/x)
pprint(limit(f,x,oo))