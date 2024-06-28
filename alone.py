import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

pi = np.pi
x = np.linspace(-np.sqrt(33), np.sqrt(33), 100)
fig, ax = plt.subplots()
line, = ax.plot(x, np.zeros_like(x))

ax.set_xlim(-15, 15)
ax.set_ylim(-10, 10)

ax.axhline(0, color='black',linewidth=0.5)
ax.axvline(0, color='black',linewidth=0.5)

def update(frame):
    a = frame
    y = np.abs(x)**(2/3) + 0.8 * np.sqrt(33 - x**2) * np.sin(0.01 * a * pi * x)
    line.set_ydata(y)
    return line,

ani = FuncAnimation(fig, update, frames=np.arange(1, 1000), interval = 20, blit=True)

plt.xlabel('x')
plt.ylabel('y')
plt.title('??Alone ??')
plt.show()


