import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000001,0.000007,0.000015,0.000394,0.001196,0.011093,0.029593,0.044330,0.057447,0.075075,0.096428,0.119998]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Avg Time taken in sec')
plt.title('SELECTION SORTING GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()