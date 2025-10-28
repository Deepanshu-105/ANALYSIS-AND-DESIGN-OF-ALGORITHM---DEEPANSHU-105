import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000001,0.000007,0.000024,0.000518,0.002027,0.018837,0.051724,0.094378,0.101193,0.139345,0.187311,0.205940]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Avg Time taken in sec')
plt.title('QUICK SORTING GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()


