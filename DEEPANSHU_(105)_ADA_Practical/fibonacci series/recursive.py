import matplotlib.pyplot as plt


x = [2,5,10,15,20,25,30,35,40,45,50]
y = [0.000000,0.000000,0.000000,0.000000,0.000000,0.002000,0.008000,0.078000,1.003000,9.233000,112.215000]


plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')


plt.xlabel('POSITION IN FIBONACCI SERIES')
plt.ylabel('Avg Time taken in sec')
plt.title('RECURSIVE APPROACH OF FIBONACCI SERIES TIME COMPLEXITY')
plt.legend()
plt.grid(True)
plt.show()