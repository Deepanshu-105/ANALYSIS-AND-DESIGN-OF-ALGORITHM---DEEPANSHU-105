import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000003,0.000015,0.000030,0.000103,0.000191,0.000674,0.000920,0.001151,0.001390,0.001495,0.001700,0.001956]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Avg Time taken in sec')
plt.title('MERGE SORTING GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()