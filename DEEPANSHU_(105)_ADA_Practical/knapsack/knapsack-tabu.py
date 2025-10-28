import matplotlib.pyplot as plt

# Sample data
x = [100,200,300,400,500,600,700,800,900,1000]
y = [0.000001 ,0.000001 ,0.000003 ,0.000003 ,0.000005 ,0.000009 ,0.000010 ,0.000010 ,0.000010 ,0.000018 ]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER Of Items : n')
plt.ylabel('Avg Time taken (in seconds)')
plt.title('0/1 knapsack by Tabulation method GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

