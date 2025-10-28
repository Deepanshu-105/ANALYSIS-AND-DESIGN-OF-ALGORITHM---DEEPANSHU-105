import matplotlib.pyplot as plt

# Sample data
x = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000]
y = [0.001000 ,0.002000 ,0.002000 ,0.002000 ,0.004000 ,0.004000 ,0.005000 ,0.006000 ,0.006000 ,0.006000 ,0.007000  ]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER Of Items : n')
plt.ylabel('Avg Time taken (in seconds)')
plt.title('Fractional knapsack by Greedy method GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

