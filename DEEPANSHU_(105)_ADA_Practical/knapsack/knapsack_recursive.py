import matplotlib.pyplot as plt

# Sample data
x = [5,10,15,20,25,30,35,40,45]
y = [0.000000 ,0.000000 ,0.002000 ,0.003000 ,0.031000 ,0.237000 ,3.692000 ,24.285000 ,228.821000 ]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER Of Items : n')
plt.ylabel('Avg Time taken (in seconds)')
plt.title('0/1 knapsack by recursive method GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
