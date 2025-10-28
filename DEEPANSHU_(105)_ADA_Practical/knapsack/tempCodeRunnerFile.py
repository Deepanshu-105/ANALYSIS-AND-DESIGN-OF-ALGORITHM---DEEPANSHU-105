import matplotlib.pyplot as plt

# Sample data
x = [100,200,300,400,500,600,700,800,900,1000]
y = [0.001000 , 0.003000 , 0.004000 , 0.006000 , 0.011000 , 0.016000 , 0.021000 , 0.026000 , 0.032000 ]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER Of Items : n')
plt.ylabel('Avg Time taken (in seconds)')
plt.title('0/1 knapsack by Memoization method GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
