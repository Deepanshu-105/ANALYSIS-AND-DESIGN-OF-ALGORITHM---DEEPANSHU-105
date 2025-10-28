import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000000,0.000001,0.000000,0.000004,0.000006,0.000021,0.000035,0.000048,0.000059,0.000073,0.000083,0.000106]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Avg Time taken in sec')
plt.title('INSERTION SORTING GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()