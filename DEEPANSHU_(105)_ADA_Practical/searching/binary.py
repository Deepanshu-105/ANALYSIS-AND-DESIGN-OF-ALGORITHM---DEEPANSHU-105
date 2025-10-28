import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000030,0.000020,0.000050,0.000030,0.000050,0.000030,0.000020,0.000020,0.000020,0.000020,0.000020,0.000030]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Avg Time taken in millisec')
plt.title('BINARY SEARCH GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

