import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000000,0.000012,0.000031,0.000710,0.003192,0.038207,0.059328,0.095364,0.120076,0.158564,0.199162,0.250900]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Avg Time taken in sec')
plt.title('BUBBLE SORTING GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

