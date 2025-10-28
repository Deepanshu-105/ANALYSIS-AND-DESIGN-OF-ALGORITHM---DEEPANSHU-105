import matplotlib.pyplot as plt


x = [2,5,10,15,20,25,30,35,40,45,50,55,60,65,75,85,90,95]
y = [0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000001,0.000001,0.000001,0.000001,0.000001,0.000001]


plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')


plt.xlabel('POSITION IN FIBONACCI SERIES')
plt.ylabel('Avg Time taken in sec')
plt.title('BOTTOM-UP(TABULATION) APPROACH OF FIBONACCI SERIES TIME COMPLEXITY')
plt.legend()


plt.grid(True)
plt.show()