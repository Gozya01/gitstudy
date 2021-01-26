import numpy as np
import matplotlib.pyplot as plt
from math import *
x=np.arange(-1,1,0.01)
y=[-i*i for i in x]
plt.plot(x,y)
plt.show()
