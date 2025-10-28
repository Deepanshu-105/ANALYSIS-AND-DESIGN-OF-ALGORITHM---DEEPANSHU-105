import matplotlib.pyplot as plt


x = [2,5,10,15,20,25,30,35,40,45,50]
y = [0.000000,0.002000,0.005000,0.006000,0.007000,0.011000,0.011000,0.014000,0.012000,0.018000,0.018000]


plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')


plt.xlabel('POSITION IN FIBONACCI SERIES')
plt.ylabel('Avg Time taken in sec')
plt.title('ITERATIVE APPROACH OF FIBONACCI SERIES TIME COMPLEXITY')
plt.legend()


plt.grid(True)
plt.show()